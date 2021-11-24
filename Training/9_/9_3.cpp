#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=2; i<N; i++)
    {
        while(N%i==0)
        {
            printf("%d\n",i);
            N/=i;
        }       
    }
    if(N!=1)    // N이 2일때 
        printf("%d\n",N);
    return 0;
}
