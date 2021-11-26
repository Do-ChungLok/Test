#include <stdio.h>
int main()
{
    int N,M;
    char wb[50]={};
    int cnt=0;
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++)
    {
        scanf("%s%s%s%s%s%s%s%s", wb[i]);
        {
            if(wb[i]==wb[i+1])
            {
                cnt++;
            }
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
