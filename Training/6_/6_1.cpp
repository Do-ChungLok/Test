#include <stdio.h>
int sum(int n)    // 셀프 넘버가 아닌 수를 구하는 함수
{
    int sum = n;    // 원래 자기 자신의 수를 더함
    
    while(n>0)
    {
        sum += n%10;    // 10으로 나눈 후 나머지 즉 1의자리수, 10의자리수 더함
        n/=10;
    }
    return sum;
}

int main(void)
{
    int arr[10001], i, check;
    
    for(i=1; i<10001; i++)
    {
        check = sum(i);
        if(check < 10001)    // 셀프 넘버가 아닌 수 확인하는 조건
            arr[check]=1;
    }
    
    for(i=1; i<10001; i++)
    {
        if(arr[i]!=1)        // 셀프 넘버 수 확인
            printf("%d\n",i);
    }
    return 0;
}

    
