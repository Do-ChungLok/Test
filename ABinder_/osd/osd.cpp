#include <iostream>
#include <unistd.h>	/* 'read(), write(), close()' 사용 */
#include <stdlib.h>	
#include <stdio.h> 	/* 'printf(), scanf()' 사용 */
#include <sys/fcntl.h> /* 'ioctl()' 사용 */ 
#include <sys/ioctl.h>	/* '_RDWR 매크로' 사용 */

#define IOCTL_PRINT 1

static int fd;
static char buf[1024];
static int read_ret;

using namespace std;

void onDisplay(char *buffer)
{	
	cout<< "입력한 문자는 [" <<buf <<"] 입니다."<<endl;
}


int main(void)
{
	fd = open("/dev/abinder", O_RDWR);
	if (fd < 0){	// 디바이스를 열지 못하면 에러 메시지 출력 
		cout<< "Device Driver를 불러오는데 실패하였습니다." <<endl;
		return 0;
	}
 
	while(1)
 	{
		read_ret = read(fd, buf, 1024);
		if (read_ret > 0) {
			onDisplay(buf);
			//cout<< "입력한 문자는 [" <<buf <<"] 입니다."<<endl;	
		}
		
 	} 	
	close(fd);	// 디바이스 닫음
}


