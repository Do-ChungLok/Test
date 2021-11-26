#include <stdio.h>
int main()
{
    int N;
    int temp, check, count=1;
    int i;
    
    scanf("%d",&N);
    if(N==1)
    {
        printf("666");
        return 0;
    }
    
    for(i=667; ;i++)
    {
        temp = i;
        check = 0;
        
        while(temp)
        {
            if(temp % 1000 == 666)
            {
                check = 1;
            }
            temp /= 10;
        }
        
        if(check)
        {
            count++;
            if(count == N)
            {
                break;
            }
        }
    }
    printf("%d\n", i);
    return 0;    
}
