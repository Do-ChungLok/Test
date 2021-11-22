#include <stdio.h>
int main(){
    int max;
    int num[9];
    int line;
    
    for(int i=1; i<=9; i++){    // 9개 숫자 입력
        scanf("%d\n",&num[i]);
    }
    
    max=num[1];
    for(int i=1; i<=9; i++){    // 비교
        if(num[i] > max){
            max = num[i];
            line = i;
        }
    }
    
    printf("%d\n", max);   
    printf("%d\n", line);    // line은 0부터 시작이니 +1
    return 0;
    
}


