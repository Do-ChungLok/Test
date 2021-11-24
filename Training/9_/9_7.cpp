#include <stdio.h>
#define SIZE 10001

int main()
{
    int T, input_num;
    int i, j;
    int arr[SIZE] = {};    // 빈 배열에는 0으로 초기화
    
    arr[0]=1, arr[1]=1;    // 0과 1은 소수가 아님
    for(i=2; i<=SIZE; i++)
    {
        if(arr[i]==1)      // 이미 소수가 아닌 수는 반복문 바로 탈출, 연산할 필요가 x
        {
            continue;    
        }
            
        else
        {
            for(j=2; i*j<=SIZE; j++)    // 자신의 배수는 소수가 아님
            {
                arr[i*j]=1;
            }
        }
        
    }
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        scanf("%d", &input_num);
        
        for(j= input_num/2; j>0; j--)
        {
            if(arr[j] !=1 && arr[input_num-j] !=1)    // 소수인 배열의 값이 0일때
            {
                printf("%d %d\n",j, input_num-j);
                break;
            }
        }
    }
    return 0;
}
