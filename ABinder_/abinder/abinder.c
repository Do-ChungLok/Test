#include <linux/init.h>	/* 매크로를 사용에 필요 */
#include <linux/kernel.h> 	/* 'KERN_INFO', 'printk' 등 에 필요 */
#include <linux/module.h> 	/* 'Kernel Moudle'에 필수 */
#include <linux/fs.h> 		/* 'file_operations'에 필요 */
#include <linux/uaccess.h>
//#include <asm/uaccess.h> 	/* 'copy_to, from_user()'에 필요 */
#include <linux/slab.h> 	/* 'kmalloc', 'kfree'에 필요 */
#include <linux/device.h> 
#include <linux/errno.h> 	/* '에러 코드'에 필요 */
#include <linux/unistd.h> 
#include <linux/cdev.h> 

#define BASE_MINOR 0 /* minor number(부번호)의 Startin Number */ 
#define DEVICE_NAME "abinder" 
#define IOCTL_PRINT 1 

//TODO: 전역적으로 사용하는 변수들 묶어서 struct abinder_dev {}  만들어야 함
//      multi-application 에서 사용하기 위해, process당 변수와 driver 전체에서 사용하는 변수 구분해야하고...
static dev_t my_dev; 
static struct class *my_class; 
static struct cdev my_cdev; 

static int size = 0; 
static char *device_buf = NULL; 

static int abinder_open(struct inode *inode, struct file *filp); 
static int abinder_release(struct inode *inode, struct file *filp); 
static ssize_t abinder_read(struct file *filp, char *buf, size_t count, loff_t *f_pos); 
static ssize_t abinder_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos); 
static long abinder_ioctl(struct file *filp, unsigned int cmd, unsigned long data); 

/* overriding functions of Virtual File System */ 
static struct file_operations fops = { 
	.read = abinder_read, 
	.write = abinder_write, 
	.open = abinder_open, 
	.release = abinder_release, 
	.unlocked_ioctl = abinder_ioctl 
}; 
	
/* Device 초기화 함수 */
int abinder_open(struct inode *inode, struct file *filp) { 
	printk(KERN_INFO "abinder device open\n"); 
	return 0; 
} 

/* Device 종료 함수 */
int abinder_release(struct inode *inode, struct file *filp) { 
	printk(KERN_INFO "abinder device release\n"); 
	return 0; 
} 

/* 제어 함수 : 별도의 명령어를 통해 'Device'를 제어하고자 할 때 필요 */
long abinder_ioctl(struct file *filp, unsigned int cmd, unsigned long data) { 
	switch (cmd) { 
	case IOCTL_PRINT: 
		printk(KERN_INFO "[%s] IOCTL_PRINT called!", __func__); 
		break; 
	default: 
		printk(KERN_INFO "[%s] unknown command!", __func__); 
		break; 
	} 
	return 0; 
} 

/* -파일에 데이터 쓰기- Copy 'user space buffer' to 'kernel space buffer' */ 
/* 'user space'의 'buff'에서 'count 바이트' 만큼 읽은 후 'Device'의 'fpos' 위치로 저장 */
/* 'struct file *flip' : 읽기와 쓰기에 전달되는 'flip'은 디바이스 파일이 어떤 형식으로 열렸는지 정보 저장 */
/* 'loff_t *f_pos' : 'f_pos' 필드 변수에는 현재 읽고 쓰는 위치를 나타냄 */
ssize_t abinder_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos) { 
	int not_copied; 		//NOTE: not_copied 용도가 뭔진 모르겠지만, 불필요한 변수.. copy_from_user 등 함수 리턴값은 에러처리용
	
	if (device_buf != NULL) 
		kfree(device_buf); 

	//NOTE: 이 부분도 매번 malloc 하는게 아니라,  _init 초기에 PAGE_SIZE 정도 버퍼를 만들어두고 관리하면서 사용해야함
	if ((device_buf = kmalloc(count + 1, GFP_KERNEL)) == NULL)
		return -ENOMEM; 
	
	not_copied = copy_from_user(device_buf, buf, count); 
	printk("[%s] count = %ld, not_copied = %u\n", __func__, count, not_copied); 

	size += count; 			//NOTE:  버퍼에 저장된 바이트 수를 전역변수로 관리하는 목적으로 사용

	if (f_pos) *f_pos = size;

	return count; 			//NOTE: 그렇기 때문에  write 리턴값은  이번에 추가된(쓰여진) 바이트수 리턴
} 

/* -파일로부터 데이터 읽기- copy 'kernel space buffer' to 'user space buffer', saved by write */ 
/* 'Device Driver'가 직접 'Device Memory buff'에서 데이터를 읽어옴 -> 그 내용을 'copy' 하여 'user space'에 전달 */
/* 'Device' 의 'f_pos' 위치에서 'count 바이트' 만큼 읽은 후 'userspace' 의 'buff'로 전달(저장) */
ssize_t abinder_read(struct file *filp, char *buf, size_t count, loff_t *f_pos) { 
	int not_copied; 
	
	if (device_buf == NULL) 
		return -1; 
	
	//NOTE: 위 write 에서 사용된 (아직 user가 안읽어간 buffer 유효데이터 갯수 = size ) 만큼만 복사해 줌
	if (count > size) 
		count = size; 
	
	if (count > 0)  {
		not_copied = copy_to_user(buf, device_buf, count);
		printk("[%s] count = %ld, buffer_avail = %u\n", __func__, count, size);

		size -= count;		//NOTE: **** 이 부분이 중요*****
	}

	return count;	//NOTE: 사용자에게 전송한 데이터 갯수 리턴 (다 전달했으면 0 이 던져져야, 무한 read 가 안되겠지?)
} 

/* 등록 함수 : 'Device Driver'를 커널에 등록하기 위해 필요 */ 
static int __init abinder_init(void){ 
	printk(KERN_INFO "[%s]\n", __func__); 

	/* alloc_chredv_region : 'Minor Number' 자동 할당 */
	/* int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count, const char *name)
	- dev : 주번호 할당, baseminor : 부번호 시작 번호, count : 할당받을 부번호의 갯수, name : d/d 이름 */
	
	if (alloc_chrdev_region(&my_dev, BASE_MINOR, 1, DEVICE_NAME)) { 
		printk(KERN_ALERT "[%s] alloc_chrdev_region failed\n", __func__); 
		goto err_return; 
	} 
	
	/* cdev_init : cdev 구조체를 초기화 ( 'cdev'와 'file_operations'의 포인터를 받아 cdev 초기화) */ 
	cdev_init(&my_cdev, &fops);	
	
	/* cdev_add : cdev 구조체를 커널에 등록 */ 
	/* int cdev_add(struct cdev *p, dev_t dev, unsigned count) */
	/* p : 디바이스를 위한 cdev 구조체, dev : first device number for which this device is responsible
	, count : 할당받을 부번호의 갯수 */

	if (cdev_add(&my_cdev, my_dev, 1)) { 	
		printk(KERN_ALERT "[%s] cdev_add failed\n", __func__); 
		goto unreg_device; 
	} 
	
	//TODO: class 서브그룹은 추후 필요시 추가하는걸로.. (꼭 필요한것은 아니니)
	/* class : 디바이스의 그룹 -> 'sysfs'에 우리가 만드는 class가 등록됨 
	'ls -l /sys/class' 에서 클래스 목록 확인가능 */
	if ((my_class = class_create(THIS_MODULE, DEVICE_NAME)) == NULL) { 
		printk(KERN_ALERT "[%s] class_add failed\n", __func__); 
		goto unreg_device; 
	} 
	
	/* 앞서 등록한 'char device'와 연결된 'device file'을 만들어줌  */
	/* struct device *device_create(struct class *class, struct device *parent, dev_t devt, void *drvdata, 		const char *fmt, ...)
	- class : 구조 클래스에에 대한 포인터, parent : 부모 구조에 대한 포인터, dev_t, drvdata : 콜백을 위한 추가할 		수 있는 데이터, fmt : Device 이름 */

	if (device_create(my_class, NULL, my_dev, NULL, DEVICE_NAME) == NULL) { 
		goto unreg_class; 
	} 
	
	printk("[%s] successfully created device: Major = %d, Minor = %d", 
		__func__, MAJOR(my_dev), MINOR(my_dev)); 
		
	return 0; 
	
unreg_class: 
	class_destroy(my_class); 
	
unreg_device: 
	unregister_chrdev_region(my_dev, 1); 
	
err_return: 
	return -1; 
}

/* 해제 함수 : 'Device Driver'를 커널에서 삭제하기 위해 필요 */
static void __exit abinder_exit(void) { 
	device_destroy(my_class, my_dev); 
	class_destroy(my_class); 
	cdev_del(&my_cdev); 
	unregister_chrdev_region(my_dev, 1); /* 'my_dev'로부터 '1'개 Minor Number 반납 */
	
	if (device_buf != NULL) 
		kfree(device_buf); 
} 

module_init(abinder_init); 
module_exit(abinder_exit); 

MODULE_AUTHOR("Chunglok"); 
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("My first character device driver");
