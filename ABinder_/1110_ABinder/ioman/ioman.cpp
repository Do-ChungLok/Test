#include <iostream>
#include <unistd.h>	/* 'read(), write(), close()' 사용 */
#include <stdlib.h>	
#include <stdio.h> 	/* 'printf(), scanf()' 사용 */
#include <sys/fcntl.h> /* 'ioctl()' 사용 */ 
#include <sys/ioctl.h>	/* '_RDWR 매크로' 사용 */

#define IOCTL_PRINT 1

using namespace std;

int getKeyboard(char *buffer)
{	
	return scanf("%s", buffer);	
	//return scanf("%[^\n]s", buffer);	// 공백 포함 문자도 입력 가능	
}


int main(void)
{
	int fd;
	char buf[1024];
	int write_ret;
 
	fd = open("/dev/abinder", O_RDWR);
	if (fd < 0){	// 디바이스를 열지 못하면 에러 메시지 출력
		cout<< "Device Driver를 불러오는데 실패하였습니다." <<endl;
		return 0;
	}
	
	cout<< "==========================================================================" <<endl;
	
	while(1)
 	{
		if (getKeyboard(buf) > 0) {		
			write_ret = write(fd, buf, 1024);	
			cout<< "입력한 문자열 : " << buf <<endl;
			//continue;
		}
		//else
			//continue;
			//break;
	}	
 	
 	return 0;
	close(fd);	// 디바이스 닫음
}


