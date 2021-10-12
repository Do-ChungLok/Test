#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int fd;
    caddr_t addr;
    struct stat statbuf;
    int num1;
    char str[100];
    int count;
    int i;
    off_t len;
    


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
    addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, 
                MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    
    for (len = 0; len < statbuf.st_size; ++len)
        putchar(addr[len]);
     
    close(fd);
    //munmap(p, statbuf.st_size);
    

    printf("'2'를 입력하세요 : ");
    scanf("%d", &num1);
    
    switch(num1){
    
    case 2:
    {
    
   	printf("변환할 문자열을 입력하세요 : ");
    	scanf("%s",str);

     	//1행
	for(int i=0; i < statbuf.st_size; i++){
    		if(addr[i] == '\n') 
    			count = i;
    			printf("%d",count);


		1행 원래 문자열 그대로
		for(count=0; count-1; count++){
			printf("%c",addr[count]);
		}
	}
	
	

	//2행
	for(int i=count+1; addr[i]; i++){ 
		if(addr[i] == '\n')
			count = i;
	
		2행에 입력한 문자열 치환
		for(count; count-1; count++){
			printf("%s",str);
		}
	}	


	3행
	for(int i=count+1; addr[i]; i++){
		if(addr[i] == '\n')
			count = i;
	
		//3행 원래 문자열 그대로
		for(count=0; count-1; count++){
			printf("%c",addr[count]);
		}
     	} 	
     	
    	break;
    }	
    default:
    	printf("ERROR. 1~3 input plz\n");
    	break;
    }
    return 0;
}
