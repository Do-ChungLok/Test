#include <stdio.h>

#define ARRAY_SIZE_MAX 301

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main()
{
    
    int stacked_stairs[ARRAY_SIZE_MAX]={};
    int stair[ARRAY_SIZE_MAX]={};
    
    int N;    // 계단의 수  
    scanf("%d", &N);    // 계단의 수 입력
    
    for (int i = 1; i <= N; i++){
            scanf("%d", &stair[i]);
    }
    
    stacked_stairs[0] = 0;                      // 초기값 설정
    stacked_stairs[1] = stair[1];               // 초기값 설정
    stacked_stairs[2] = stair[1] + stair[2];    // 초기값 설정
    
    for (int i = 3; i <=N; i++){
        stacked_stairs[i] = stair[i] + (Max( stacked_stairs[i - 2], stair[i - 1] + stacked_stairs[i - 3] ));
    }    // 마지막 층을 기준 : stair[i] , 경우의수 2가지 존재 -> 
         // i) 마지막층 전전층에서 오는 경우 : stacked_stairs[i - 2]
         // ii) 마지막층 전층에서 오는 경우 : staris[i - 1] + stacked_staris[i - 3]
    
    printf("%d\n", stacked_stairs[N]);
    
    return 0;
}
