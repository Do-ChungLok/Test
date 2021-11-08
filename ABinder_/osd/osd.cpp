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
	char buf[512];
	int read_ret, write_ret;
 
	cout<< "Device driver : abinder - osd test." <<endl;
 
	fd = open("/dev/abinder", O_RDWR);
	if (fd < 0){
		cout<< "Device Driver를 불러오는데 실패하였습니다." <<endl;
		return 0;
	}
 
#if 0
	write_ret = write(fd,"osd_test", 512);
	read_ret = read(fd, buf, 512);
	cout<< "fd = " <<fd <<endl << "ret_wrtie = " << write_ret <<endl << "read_ret = " <<read_ret <<endl; 
	cout<< "Content = " << buf <<endl;
	
	ioctl(fd,IOCTL_PRINT,NULL);
#endif
	
	while(1)
 	{
		//sleep(1);
		read_ret = read(fd, buf, 512);
		if (read_ret > 0) {
			//cout<< "fd = " <<fd <<endl << "ret_wrtie = " << write_ret <<endl << "read_ret = " <<read_ret <<endl; 
			cout<< "Content = " << buf <<endl;
			//cout<< "osd 실행 테스트 중입니다." <<endl;
		}
 	}
 	
	close(fd);
}
