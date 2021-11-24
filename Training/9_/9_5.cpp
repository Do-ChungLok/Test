#include <stdio.h>
#define size 1000001

int main()
{
    int min, max;
    int arr[size]={};    // 빈 배열에는 0으로 초기화
    int i,j;
    scanf("%d %d", &min, &max);
    
    arr[0]=1, arr[1]=1;    // 0과 1은 소수가 아님
    for(i=2; i<=max; i++)
    {
        if(arr[i]==1)      // 이미 소수가 아닌 수는 반복문 바로 탈출, 연산할 필요가 x
        {
            continue;    
        }
        else
        {
            for(j=2; i*j<=max; j++)    // 자신의 배수는 소수가 아님
            {
                arr[i*j]=1;
            }
        }
    }
    
    for(i=min; i<=max; i++)    // 소수값( arr[i]==0 인 값) 출력
    {
        if(arr[i]==0)
        {
            printf("%d\n",i);
        }
    }
    
    return 0;
}
