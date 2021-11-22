#include <stdio.h>
int han(int n)   
{
    int i, count=0; 
    int hund,ten,one;
    
    if(n<100)    // 100보다 작으면 무조건 한수
        return n;
    else
    {
        for(i=100; i <= n; i++)
        {
            hund = i/100;    // 100의 자릿수
            ten = (i%100)/10;     // 10의 자릿수
            one = (i%100)%10;    // 1의 자릿수
            
            if((hund - ten) == (ten - one)) // 등차수열 판별
                count++;
         }
        return(99 + count);    // 1~99가 99개니까 +99
    }
}

int main(void)
{
    int input, result; 
    scanf("%d",&input);
    result=han(input);
    printf("%d",result);
}

    
