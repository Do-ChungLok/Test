#include <stdio.h>

int factorial(int num)  // ex)num=3 -> 3 * factorial(2) -> 3 * 2 * factorial(1) -> 3 * 2 * 1
{
    if(num>1)
        return num * factorial(num-1);   
    else
        return 1;
}
int main()
{
    int N;
    
    scanf("%d", &N);
    
    printf("%d\n", factorial(N));
    return 0;
    
}

