#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 라인 카운트하는 함수
int counting_lines(char *ptr)
{
	int total_lines = 0;	    // lines 초기값 '0' 설정
	char *p = ptr;

	while (*p != 0) {	    
		if (*p == '\n') {  // '\n'을 만나면 line 갯수 +1 카운트 
			total_lines++; 
			ptr=p; 
		}
		//putchar(*ptr);
		p++;
	}
	
	if (ptr != p-1) 	    // 'ptr'값과 'p-1'값이 같지 않으면 line 갯수 +1 카운트 
	total_lines++;

	printf("Total Lines =%d\n", total_lines); // '총 Line 갯수' 출력
	return total_lines;	    // 'Total lines' 반환
}

// 라인 시작 문자(지점) 찾는 함수
char* find_line_start(char* ptr, int want_line)  //매핑한 메모리 포인터 변수, 문자열을 변경할 라인넘버 정수값
{
	int lines = 0;
	while (ptr != 0 && want_line > (lines+1)) { // 'ptr'값 != 0 && 문자열 변경할 라인넘버 정수값> 1 조건일때 반복
		if (*ptr == '\n')  // '\n'을 만나면 'lines ++', 'ptr++'
		lines++;
		ptr++;
	}
	
	printf("<%d번째> 라인 시작 문자 = %c\n", ++lines, *ptr);
	return ptr;		    // '라인 시작 문자(지점)' 반환
}

// 내용 출력 함수
void print_content(char* ptr)
{
	printf("===========\n");
	while (*ptr != 0) {	// ptr 포인터 변수 != 0 조건일때 *ptr++ 계속 출력
		putchar(*ptr++);
	}
	printf("===========\n");
}

int main(int argc, char *argv[]) {
    int fd;
    caddr_t addr;
    struct stat statbuf;
    int want_line_num = 0;
    char str[100];
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
    
    // 'counting_lines'함수를 사용하여 매핑한 메모리의 라인 갯수를 'max_lines' 변수에 저장
	int max_lines = counting_lines((char*)addr);
	
	//printf("매핑 파일 크기 : %ld\n",statbuf.st_size);
	printf("변경할 라인 넘버 : ");
	scanf("%d", &want_line_num);	// '변경할 라인 넘버' 입력
	
	while( want_line_num <= 0 || want_line_num > max_lines)
	{
		printf("ERROR! '변경할 라인 넘버'는 정수이어야 하며, 파일의 최대 라인수보다 클 수 없습니다.\n");
		printf("변경할 라인 넘버를 다시 입력해주세요 : ");
		scanf("%d", &want_line_num);	
	}
		
	printf("변경할 문자열을 입력하세요 : ");
	scanf("%s", str);		// '변경할 문자열' 입력

	// add newline character for input strings.
	strcat(str, "\n");
	
	char* start_next = find_line_start(addr, want_line_num+1);  // 입력(변경)할 라인의 밑라인 시작 지점 
	char* start = find_line_start(addr, want_line_num);	    // 입력(변경)할 라인 시작 지점

	int input_str_len = strlen(str); 	          // 입력한(변경할) 문자열 길이
	int before_str_len = (int)(start_next - start); // 입력(변경) 이전 문자열 길이

	printf("> 입력 이전 문자열 길이 (**개행문자가 포함된 길이입니다.)= %d\n", before_str_len);
	printf("> 입력한(변경할) 문자열 길이 (**개행문자가 포함된 길이입니다.)= %d\n", input_str_len);

	print_content(addr); //매핑한 메모리 내용 출력

	char *a, *b;
	if (input_str_len < before_str_len) {     // '입력한(변경할) 문자열 길이' < '변경이전 문자열 길이' 조건일때 
		memcpy(start, str, input_str_len);  // '입력한(변경할) 문자열 길이' 만큼 '입력한(변경할) 문자열'을 '라인 시작지점'에 복사
		
	      //for(a = 시작지점 + 입력한(변경할) 문자열 길이, b = 입력한(변경할) 라인의 밑라인 시작 지점 ; *b ; a++ b++); 
		for (a = start + input_str_len, b = start_next; *b; a++, b++) { 
		
			*a = *b;	// '*a'에 '*b' 대입
		}
		
		for (; *a; a++)	
			*a = '\0';
	} 
	else {					   // '입력한(변경할) 문자열 길이' >= '변경이전 문자열 길이' 조건일때
		memcpy(start, str, input_str_len);  // '입력한(변경할) 문자열 길이' 만큼 '입력한(변경할) 문자열'을 '라인 시작지점'에 복사
		b = addr + statbuf.st_size;	   // b = addr + 매핑파일 크기
		
// for(a = addr + 매핑된 파일 크기 + (입력한(변경할) 문자열 길이 - 변경이전 문자열 길이); b > 입력(변경)할 라인 밑라인 시작 지점; b--, a--)
		for (a = b + (input_str_len - before_str_len); b > start_next; b--, a--) {
			*a = *b;	// '*a'에 '*b' 대입
		}
	}

	print_content(addr);

    munmap(addr, len);
    close(fd);

    return 0;
}
