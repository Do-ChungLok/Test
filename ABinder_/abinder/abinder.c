#include <linux/init.h>	/* '매크로' 사용 */
#include <linux/kernel.h> 	/* 'KERN_INFO', 'printk()' 사용 */
#include <linux/module.h> 	/* 'Kernel Moudle' 사용 */
#include <linux/fs.h> 		/* 'file_operations' 사용 */
#include <linux/uaccess.h>	/* 'copy_to, from_user()' 사용 */
#include <linux/slab.h> 	/* 'kmalloc()', 'kfree()' 사용 */ 
#include <linux/errno.h> 	/* '에러 코드' 사용 */
#include <linux/unistd.h> 	/* 'read(), write()' 사용 */
#include <linux/cdev.h> 	/* 'cdev' 구조체 사용*/
#include <linux/device.h> 

#define FIRST_MINOR 0 		/* minor number(부번호)의 'Starting Number' */ 
#define MINOR_CNT 1 
#define DEVICE_NAME "abinder" 
#define REGISTER_SERVICE 1
#define CALL_SERVICE 2
#define CALL_SERVICE_RET 3
 


//TODO: 전역적으로 사용하는 변수들 묶어서 struct abinder_dev {}  만들어야 함 - (o)
//      multi-application 에서 사용하기 위해, process당 변수와 driver 전체에서 사용하는 변수 구분해야하고... << ???

static dev_t dev;
struct abinder_dev{
	struct class *my_class;
	struct cdev my_cdev;
};

static struct abinder_dev adev; 

static int buffer_size = 0; 
static char *device_buf = NULL; 

static int abinder_open(struct inode *inode, struct file *filp); 
static int abinder_release(struct inode *inode, struct file *filp); 
static long abinder_ioctl(struct file *filp, unsigned int cmd, unsigned long data); 
static ssize_t abinder_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos); 
static ssize_t abinder_read(struct file *filp, char *buf, size_t count, loff_t *f_pos); 

/* overriding functions of Virtual File System */ 
static struct file_operations fops = { 
	.open = abinder_open,
	.release = abinder_release,
	.unlocked_ioctl = abinder_ioctl,
	.write = abinder_write, 
	.read = abinder_read,
}; 
	
/* Device 초기화 함수, 'User Space'에서 '디바이스'를 열 때마다 함수가 호출 및 기능 수행 */
int abinder_open(struct inode *inode, struct file *filp) { 
	printk(KERN_INFO "abinder device open\n"); 
	return 0; 
} 

/* Device 종료 함수 'User Space'에서 '디바이스'를 닫을 때마다 호출 및 기능 수행*/
int abinder_release(struct inode *inode, struct file *filp) { 
	printk(KERN_INFO "abinder device release\n"); 
	return 0; 
} 

struct ioctl
{
	pid_t pid;
	int service_type;
};

/* 제어 함수 : 별도의 명령어를 통해 '디바이스'를 제어하고자 할 때 필요 */
long abinder_ioctl(struct file *filp, unsigned int cmd, unsigned long data) { 
	switch (cmd) { 
		case REGISTER_SERVICE:
		{
			printk(KERN_INFO "[%s] REGISTER_SERVICE called!", __func__);
			
			/*
			
			list <ioctl> alist;
			
			for(int i=0; i<10; i++)
			{
				ioctl ic;
				//ic.pid=
			}
			*/
			
		}	
			break;
		case CALL_SERVICE:
			printk(KERN_INFO "[%s] CALL_SERVICE called!", __func__);
			break;
		case CALL_SERVICE_RET:
			printk(KERN_INFO "[%s] CALL_SERVICE_RET called!", __func__);
			break;
		default:
			printk(KERN_INFO "[%s] unknown command!", __func__);
			return 0;
	}
	
	return 0; 
} 



/* -파일에 데이터 쓰기- Copy 'user space buffer' -> 'kernel space buffer' */ 
/* 'user space'의 'buf'에서 'count 바이트' 만큼 읽은 후 'Device'의 'fpos' 위치로 저장 */
/* 'struct file *flip' : 파일을 나타내는 파일 포인터. 디바이스 파일이 어떤 형식으로 열렸는지 정보 저장 */
/* 'const char buf' : 사용자 영역 데이터, 'size_t count' : 쓰기를 수행한 바이트 수 */			
/* 'loff_t *f_pos' : 현재 읽고 쓰는 파일의 상대 위치를 저장 */
/* copy_from_user(device_buf, buf, count) : 사용자영역으로부터 전달받은 데이터 'buf'를 커널공간 'device_buf'에 'count'만큼 복사 */

ssize_t abinder_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos) { 
	int not_copied; 		
	//NOTE: not_copied 용도가 뭔진 모르겠지만, 불필요한 변수.. copy_from_user 등 함수 리턴값은 에러처리용
	
	if (device_buf != NULL) 
		kfree(device_buf); 

	//NOTE: 이 부분도 매번 malloc 하는게 아니라,  _init 초기에 PAGE_SIZE 정도 버퍼를 만들어두고 관리하면서 사용해야함
	if ((device_buf = kmalloc(count + 1, GFP_KERNEL)) == NULL)
		return -ENOMEM; 
	
	not_copied = copy_from_user(device_buf, buf, count); 
	printk("[%s] count = %ld, not_copied = %u\n", __func__, count, not_copied); 

	buffer_size += count; 			//NOTE:  버퍼에 저장된 바이트 수를 전역변수로 관리하는 목적으로 사용

	if (f_pos) *f_pos = buffer_size;

	return count; 			//NOTE: 그렇기 때문에  write 리턴값은  이번에 추가된(쓰여진) 바이트수 리턴
} 

/* -파일로부터 데이터 읽기- copy 'kernel space buffer' -> 'user space buffer' */ 
/* 'Device Driver'가 직접 'Device Memory buff'에서 데이터를 읽어옴 -> 그 내용을 'copy' 하여 'user space'에 전달 */
/* 'Device'의 'f_pos' 위치에서 'count 바이트' 만큼 읽은 후 'user space' 의 'buf'로 전달(저장) */
/* 'struct file *flip' : 파일을 나타내는 파일 포인터. 디바이스 파일이 어떤 형식으로 열렸는지 정보 저장 */
/* 'char buf' : 커널 영역 데이터, 'size_t count' : 읽를 수행한 바이트 수 */			
/* 'loff_t *f_pos' : 현재 읽고 쓰는 파일의 상대위치 */
/* copy_to_user(buf, device_buf, count) : 커널영역에 저장된 'device_buf' 데이터를 'buf'에 'count'만큼 복사 */

ssize_t abinder_read(struct file *filp, char *buf, size_t count, loff_t *f_pos) { 
	int not_copied; 
	
	if (device_buf == NULL) 
		return -1; 
	
	//NOTE: 위 write 에서 사용된 (아직 user가 안읽어간 buffer 유효데이터 갯수 = size ) 만큼만 복사해 줌
	if (count > buffer_size) 
		count = buffer_size; 
	
	if (count > 0)  {
		// '커널 영역'의 '버퍼(device_buf)'를 '사용자 영역'의 '버퍼'로 'count'만큼 복사
		not_copied = copy_to_user(buf, device_buf, count); 
		printk("[%s] count = %ld, buffer_avail = %u\n", __func__, count, buffer_size);
		buffer_size -= count;		//NOTE: **** 이 부분이 중요*****
	}

	return count;	//NOTE: 사용자에게 전송한 데이터 갯수 리턴 (다 전달했으면 0 이 던져져야, 무한 read 가 안되겠지?)
} 

/* 등록(적재) 함수 : 'Device Driver'를 커널에 등록(적재)하기 위해 필요 */ 
static int __init abinder_init(void){ 
	int alloc_ret;
	int cdev_ret;

	/* alloc_chrdev_region : 'dev'가 성공적인 경우 ' Character Device 번호' 자동 할당(시스템에 등록) */
	/* int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count, const char *name) */
	/* - 'dev' : 주번호, 'baseminor' : 디바이스에 할당될 첫번째 부번호(보통 0), */
	/* - 'count' : 할당받을 부번호의 갯수, 'name' : 디바이스 이름 */
	/* 'name'이란 이름으로 'baseminor'로부터 'Minor 번호'를 'count'개 할당 */
	
	alloc_ret = alloc_chrdev_region(&dev, FIRST_MINOR, MINOR_CNT, DEVICE_NAME);
	if (alloc_ret) 
	{ 
		printk(KERN_ERR  "alloc_chrdev_region ERROR = %d\n", alloc_ret); 
		goto err_return; 
	} 
	
	/* cdev_init : 'cdev 구조체'를 초기화 ( 'cdev'와 'file_operations'의 포인터를 받아 cdev 초기화) */ 
	/* void cdev_init(struct *cdev, struct file_operations *fops); */
	/* - '*cdev' - '*cdev'를 초기화할 cdev 구조체, '*fops' : 등록할 fops 구조체 포인터 */
	/* cdev_add : 준비된 cdev 구조체를 커널에 등록, 'Character Device' 등록 (Character Device를 시스템에 추가) */ 
	/* int cdev_add(struct cdev *cdev, dev_t dev, unsigned int count) */
	/* - '*cdev' : 디바이스를 위한 cdev 구조체, 'dev' : 등록할 디바이스 번호, 'count' : 등록할 디바이스 갯수 */
	cdev_init(&adev.my_cdev, &fops);	
	
	cdev_ret = cdev_add(&adev.my_cdev, dev, MINOR_CNT);
	if (cdev_ret) 
	{ 	
		printk(KERN_ERR  "cdev_add = %d\n", alloc_ret); 
		goto unregister_device; 
	} 

	/* 시스템에 '디바이스'를 생성, 앞서 등록한 'char device'와 연결된 'device file'을 만들어줌  */
	/* struct device *device_create(struct class *class, struct device parent, dev_t devt, const char *fmt, ...)
	- 'class' : 장치를 등록해야 하는 구조체 클래스에에 대한 포인터, 'parent' : 새로운 장치의 부모 구조체 클래스에 대한 포인터,
	 'dev' : 추가할 장치의 dev_t(dev_t는 주번호, 부번호를 포함한 디바이스 번호를 나타내는 타입), fmt : Device 이름 */

	if (device_create(adev.my_class, NULL, dev, NULL, DEVICE_NAME) == NULL) 
	{ 
		goto unregister_class; 
	} 
		
	return 0; 
	
unregister_class: 
	class_destroy(adev.my_class); 
	
unregister_device: 
	unregister_chrdev_region(dev, MINOR_CNT); 
	
err_return: 
	return -1; 
}

/* 제거(해제) 함수 : 'Device Driver'를 커널에서 삭제하기 위해 필요 */
static void __exit abinder_exit(void) { 
	/* void device_destroy(struct class* class, dev_t devt) : '디바이스'를 제거 */
	/* - 'class' : 모듈에 대한 정보를 가지고 있는 class 구조체, 'devt' : 삭제할 주번호, 부번호를 가지고 있는 dev_t */
	/* void class_destroy(struct class* class) : 모듈에 대한 정보를 가지고 있는 구조체 '디바이스 class' 삭제(소멸) */
	/* void cdev_del(struct cdev* p) : 등록된 'Character Device' 제거, 디바이스 파일, 디바이스 번호 삭제 */
	/* void unregister_chrdev_region(dev_t from, unsigned count); : 'from'으로부터 'count'개의 'Minor 번호' 반납 */
	/* - 'from' : 주번호, 부번호를 가지고 있는 dev_t, 'count' : 해제할 장비의 개수 -> 장치 번호를 반환 */
	
	device_destroy(adev.my_class, dev);
	cdev_del(&adev.my_cdev); 
	unregister_chrdev_region(dev, MINOR_CNT);	/* 'Char D/D 제거, 'dev'로부터 'MINOR_CNT(=1)개' Minor Number 반납 */
	
	if (device_buf != NULL) 
		kfree(device_buf); 
} 

module_init(abinder_init); 	/* 모듈 적재 함수를 위한 매크로 */
module_exit(abinder_exit); 	/* 모듈 제거 함수를 위한 매크로 */

MODULE_AUTHOR("Chunglok"); 
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("My first character device driver");
