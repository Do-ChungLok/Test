#include <stdio.h>

int fb(int num)
{
    if(num>=2)
    {
        return fb(num-1) + fb(num-2);
    }
    else
        return num;
}



int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fb(n));
    
    return 0;
}
