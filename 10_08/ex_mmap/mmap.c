#include <sys/types.h> 
#include <sys/mman.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 

int main(int argc, char *argv[]) { 
	int fd; 
	pid_t pid; 
	caddr_t addr; 
	struct stat statbuf; 

		if(argc != 2) { 
			fprintf(stderr, "Usage : %s filename\n", argv[0]); 
			exit(1); 
		} 
	
		//stat 함수로 파일의 속성 정보를 검색해 파일의 크기를 알아낸다. 
		if(stat(argv[1], &statbuf) == -1) {			
			perror("stat");
			exit(1); 
		} 
		
		// 메모리에 매핑할 데이터 파일 open.
		if((fd = open(argv[1], O_RDWR)) == -1) {
			perror("open");
			exit(1); 
		} 
		
		// 파일을 메모리에 매핑한다. 
		addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0); 
		
		if(addr == MAP_FAILED) { 
			perror("mmap"); 
			exit(1); 
		} 
			
		close(fd); 
		
		// fork 함수를 실행해 자식 프로세스를 생성(부모 프로세스를 상속). 매핑된 메모리 시작 주소인 addr을 공유
		switch (pid = fork()) { 
		
			case -1: // fork failed 
				perror("fork"); 
				exit(1); 
				break; 
				
			case 0: // child process  
				printf("1. Child Process : addr=%s", addr); 
				sleep(1); 
				addr[0] = 'x';  // addr[0]의 내용을 'x'로 변경
				printf("2. Child Process : addr=%s", addr); 
				sleep(2); 
				printf("3. Child Process : addr=%s", addr); 
				break; 
				
			default: // parent process 
				printf("1. Parent process : addr=%s", addr); 
				sleep(2); 
				printf("2. Parent process : addr=%s", addr); 
				addr[1] = 'y';  // addr[1]의 내용을 'y'로 변경
				printf("3. Parent process : addr=%s", addr); 
				break; 
		} 
}

