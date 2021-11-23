#include <stdio.h>
#include <string.h>

#define MAX_STRING_WORD 1000001    // 널문자를 포함할 수 있게 1개 더 큰 1000001

int main() {
    char input[MAX_STRING_WORD];
    int i;
    int len;
    int blank_count=0;
    int word_count=0;
    
    scanf("%[^\n]s",input);
    len=strlen(input);
    
    
    for(i=0; i<len; i++)
    {
        if(input[i] == ' ')    // 문자 배열에서 공백 카운트
        {
            blank_count++;
        }
        else{}
    }
    
    if(input[0]==' ' && input[len-1]==' ')    // 입력문자열의 처음과 끝이 공백일때 공백 수 -2
    {
        blank_count-=2;
    }
    else if(input[len-1]==' ')    // 입력문자열의 끝이 공백일때 공백 수 -1
    {
        blank_count-=1;
    }
    else if(input[0]==' ')        // 입력문자열의 처음이 공백일때 공백 수 -1
    {
        blank_count-=1;
    }
    
    word_count = blank_count +1;    // 단어의 수는 공백 수 +1
    printf("%d",word_count);
    
    return 0;
}
