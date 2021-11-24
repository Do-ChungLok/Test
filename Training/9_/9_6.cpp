#include <stdio.h>
#define SIZE 123456*2 + 1
int main()
{
    int n;
    int i,j;
    int arr[SIZE]={};	// 빈 배열에는 0으로 초기화
    int count=0;	
    
    while(1)
    {
        scanf("%d",&n);
        
        if(n == 0)
        {
            break;
        }  
        
        arr[0]=1, arr[1]=1;    // 0과 1은 소수가 아님
        for(i=2; i<=2*n; i++)
        {
            if(arr[i]==1)      // 이미 소수가 아닌 수는 반복문 바로 탈출, 연산할 필요가 x
            {
                continue;    
            }
            
            else
            {
                for(j=2; i*j<=2*n; j++)    // 자신의 배수는 소수가 아님
                {
                    arr[i*j]=1;
                }
            }
        }
        
        for(i=n+1; i<=2*n; i++)    // 소수값( arr[i]==0 인 값) 출력, 입력값보다 +1 수로 시작해야 하는 조건만족
        {        
            if(arr[i]==0)
            {
                count++;
            }
        }
        printf("%d\n",count);
        count = 0;            
    }
    return 0;
}
