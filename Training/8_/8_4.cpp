#include <stdio.h>

int main(){
	int T, H, W, N;    // T: 데이터 갯수, H: 층수, W: 각 층의 방수, N: N번째 손님
    
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        scanf("%d %d %d", &H, &W, &N);
        if(N%H==0)    // N번째 손님 / 층수가 짝수일 경우
        {
            printf("%d%02d\n", H, N/H);    // 02%d -> 00 위웨 d를 덮어 적음
        }
        else         // N번째 손님 / 층수가 홀수일 경우
        {
            printf("%d%02d\n", N%H, (N/H)+1);
        }      
    }
	return 0; 
}
