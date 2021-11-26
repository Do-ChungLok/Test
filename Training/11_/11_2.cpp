#include<stdio.h>

int sum_function(int num)
{
    int sum_total = num; // 자기 자신을 먼저 더함
    while(num>0)
    {
        sum_total += (num%10);    //1의자리의 수 부터 더해감
        num=num/10;
    }
    return sum_total;
}

int main()
{
    int N;  
    int result;
    
    scanf("%d",&N);
    
    for(int i=1; i<N; i++)
    {
        int sum_total = sum_function(i);    
        if(sum_total == N)    // i부터 시작하여 분해합 함수의 결과값가 입력한 N값이 같을때 i를 출력
        {
            result = i;
            break;
        }
    }
    
    printf("%d",result);
    
    return 0;
    
}

/*
#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    for (int i = 1; i < N; i++)
    {
        int num = i;
        int sum_total = i;
        
        while(num > 0)
        {
            sum_total += num % 10;
            num /= 10;
        }
        
        if (sum_total == N)
        {
            printf("%d", i);
            N = 0;
            break;
        }
    }
    
    if (N != 0)
        printf("0");
}
*/
