#include <stdio.h>
int main(){
    int A,B;
    
    /* 입력받을 테스트케이스의 개수, 종료 조건이 없으므로 더이상 읽을 데이터가 없는것을 뜻하는 EOF 값을 리턴 EOF 대신 '-1'도 가능*/
    while(scanf("%d %d", &A, &B) != EOF){  
        printf("%d\n", A+B);
    }
    
    return 0;   
}
