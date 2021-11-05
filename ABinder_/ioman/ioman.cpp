#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/fcntl.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/ioctl.h>

#define IOCTL_PRINT 1

using namespace std;

int main(void)
{
	int fd;
	char buf[1024];
	int read_ret, write_ret;
 
	cout<< "Device driver : abinder - ioman test." <<endl;
 
	fd = open("/dev/abinder", O_RDWR);
	if (fd < 0){
		cout<< "Device Driver를 불러오는데 실패하였습니다." <<endl;
		return 0;
	}
 
	write_ret = write(fd,"ioman_test", 1024);
	read_ret = read(fd, buf, 1024);
	cout<< "fd = " <<fd <<endl << "ret_wrtie = " << write_ret <<endl << "read_ret = " <<read_ret <<endl; 
	cout<< "Content = " << buf <<endl;
	
	ioctl(fd,IOCTL_PRINT,NULL);
	close(fd);
	
	while(1)
 	{
		sleep(1);
		cout<< "ioman 실행 테스트 중입니다." <<endl;
 	}
 	
}
