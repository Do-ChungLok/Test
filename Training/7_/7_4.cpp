#include <stdio.h>
#include <string.h>
#define ALPHABET_ARRAY_MAX 26
#define ALPHABET_LOWER_START_A_Z 97
#define ALPHABET_UPPER_START_A_Z 65
#define MAX_STRING_WORD 1000001    // 널문자를 포함할 수 있게 1개 더 큰 1000001
#define ALPHABET_UPPER_LOWER_DIFF 32

int main() {
    char input[MAX_STRING_WORD];
    int i;
    int num[ALPHABET_ARRAY_MAX]={};
    int max=0;
    int max_index=0;
    int len;
    
    scanf("%s",input);
    len=strlen(input);
    
    for(i=0; i<=len; i++)    
    {
        if(input[i]<ALPHABET_LOWER_START_A_Z)    // a~z : 97 ~ 122 / A~Z : 65 ~ 90
        {       
            input[i] +=ALPHABET_UPPER_LOWER_DIFF;    // 대문자를 소문자로 변환
        }
        else{}
        
        if(input[i]-ALPHABET_LOWER_START_A_Z < ALPHABET_ARRAY_MAX)
        {
            num[input[i]-ALPHABET_LOWER_START_A_Z]++;    // 나타난 문자 개수 증가시킴
        }
        else
        {
            printf("ADDR_ARRAY ERROR");
        }
    }
    
    
    max=num[0];
    
    for(i=1; i<ALPHABET_ARRAY_MAX; i++)
    {
        if(num[i]>max)
        {
            max = num[i];
            max_index = i;
        }
        else if(max == num[i] && num[i] !=0)    //num[i] != 0 은 한 글자만 입력한 경우
        {
            max_index = -1;
        }
    }
    
    if(max_index != -1)
        printf("%c", max_index + ALPHABET_UPPER_START_A_Z);    // 대문자로 표현        
    else
        printf("?\n");    // 2개 이상 사용된 알파벳이 있다면 '?' 출력
       
    return 0;
}
