#include <stdio.h>
#define SIZE 100

int main()
{    
    int N, M;
    int card[SIZE];
    int max_sum=0, sum=0;
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++)
    {
        scanf("%d",&card[i]);
    }
    
    
    sum=card[0];
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                
                sum=card[i]+card[j]+card[k];    // 카드 3개 총합
            
                if(max_sum < sum && sum <= M)    // M과 근접한 값 저장
                {
                    max_sum = sum;
                }
        
            }
        }
    }
    
    
    printf("%d\n",max_sum);    
    return 0;
}
