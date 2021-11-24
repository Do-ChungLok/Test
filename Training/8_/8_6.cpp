#include <stdio.h>

int main(){
    int N;    
    int count=0;

    scanf("%d",&N);
    
    while(N>0)
    {
        if(N%5 ==0)    // 입력무게가 5로 나누었을때 나머지가 0
        {
            N-=5;
            count++;
        }
        else if(N%3 ==0)    // 입력무게가 3으로 나누었을때 나머지가 0
        {
            N-=3;
            count++;
        }
        else if(N>5)        // 입력무게가 5보다 크면 일단 5kg봉지부터  소모 해야함
        {
            N-=5;
            count++;
        }
        else                // 정확한 무게가 아니면 '-1'출력해야하니까
        {
            count=-1;
            break;
        }
    }
    printf("%d",count); 
     
    return 0;
}
