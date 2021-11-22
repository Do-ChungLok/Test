#include <stdio.h>
int main(void){
    int N;
    
    scanf("%d",&N);
    
    char num[N];
    int sum=0;
    
    //scanf("%d",&N);
    scanf("%s",num);
    
    for(int i=0; i<N; i++){
        sum += num[i] -'0';	// 문자형 아스키 코드니까 -48(=0)을 해서 숫자로 변환
    }
    printf("%d",sum);
    
}
