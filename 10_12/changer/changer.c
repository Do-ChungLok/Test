#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int counting_lines(char* ptr)
{
	int lines = 0;
	char* p = ptr;

	while (*p != 0) {
		if (*p == '\n') { lines++; ptr=p; }
		//putchar(*ptr);
		p++;
	}
	if (ptr != p-1) lines++;

	printf("total lines =%d\n", lines);
	return lines;
}

char* find_line_start(char* ptr, int want_line)
{
	int lines = 0;
	while (ptr != 0 && want_line > (lines+1)) {
		if (*ptr == '\n') lines++;
		ptr++;
	}
	return ptr;
}

void print_content(char* ptr)
{
	printf("===========\n");
	while (*ptr != 0) {
		putchar(*ptr++);
	}
	printf("===========\n");
}

int main(int argc, char *argv[]) {
    int fd;
    caddr_t addr;
    struct stat statbuf;
    int num1 = 0;
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
	len = statbuf.st_size + 100;
    addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    
	int max_lines = counting_lines((char*)addr);

	do {
		printf("변경할 라인은? ");
		scanf("%d", &num1);
	} while( num1 <= 0 || num1 > max_lines);

	printf("변환할 문자열을 입력하세요 : ");
	scanf("%s", str);

	// add newline character for input strings.
	strcat(str, "\n");

	//
	char* p_next = find_line_start(addr, num1+1);
	char* p = find_line_start(addr, num1);

	int tobe_str_len = strlen(str);
	int asis_str_len = (int)(p_next - p);

	printf("> 이전 문자열 길이 = %d\n", asis_str_len);
	printf("> 입력 문자열 길이 = %d\n", tobe_str_len);

	print_content(addr);

	char *d, *s;
	if (tobe_str_len < asis_str_len) {
		memcpy(p, str, tobe_str_len);
		for (d=p+tobe_str_len, s=p_next; *s; d++, s++) {
			*d = *s;
		}
		for (; *d; d++)	*d = '\0';
	} else {
		s = addr + statbuf.st_size;
		for (d = s + (tobe_str_len-asis_str_len); s>p_next; s--, d--) {
			*d = *s;
		}
		memcpy(p, str, tobe_str_len);
	}

	print_content(addr);

    munmap(addr, len);
    close(fd);

#if 0 
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


			//1행 원래 문자열 그대로
			for(count=0; count-1; count++){
				printf("%c",addr[count]);
			}
		}



		//2행
		for(int i=count+1; addr[i]; i++){ 
			if(addr[i] == '\n')
				count = i;

			//2행에 입력한 문자열 치환
			for(count; count-1; count++){
				printf("%s",str);
			}
		}	


		//3행
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
#endif

    return 0;
}
