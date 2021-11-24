#include <stdio.h>

int main()

{
    int N, num, count = 0;
    
    scanf("%d", &N);
    
    int i, j;
    for(i=0; i<N; i++)
    {
        scanf("%d", &num);        //소수 검사
        for (j = 2; j < num; j++)    //2부터 시작
        {
            if (num % j == 0)    
                break;
        }
        
        if (j == num)
            count++;
    }
    printf("%d\n", count);
    
    return 0;
}
