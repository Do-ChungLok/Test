#include <stdio.h>

#define MAX_STRING_WORD 16
#define APLHABET_UPPER_START 65

int main() {
    char input[MAX_STRING_WORD];
    int time[]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10};
    int result = 0;
    
    scanf("%s",input);
    for(int i=0; input[i]!= '\0'; i++)
        result += time[input[i]-65]; // 대문자에서 65만큼 빼줘서 0부터 시작하게 만듬
    printf("%d", result);
    
    //return 0;
}
