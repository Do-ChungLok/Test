#include <stdio.h>
#include <math.h>
void hanoi(int n, int start, int second, int third)
{
    if(n==1)
        printf("%d %d\n",start ,third);
    else
    {
        hanoi(n-1, start, third, second);    // 1번 장독대 n-1개 -> 2번 장독대
        printf("%d %d\n", start, third);     // 1번 장독대 -> 3번 장독대
        hanoi(n-1, second, start, third);    // 2번 장독대 -> 3번 장독대
    }
}

int main()
{    
    int N;
    int K;
    scanf("%d",&N);
    
    K=pow(2,N)-1;
    printf("%d\n", K);
    
    hanoi(N, 1, 2, 3);
    
    return 0;
  
}

