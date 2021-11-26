#include <stdio.h>

int main()
{
    int N;         // 전체 사람의 수
    int No=0;      // 등수
    
    scanf("%d",&N);
    
    int x[N];
    int y[N];
    
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);    // 전체 사람 수 만큼 x, y 배열에 저장
    }       
    
    for(int i=0; i<N; i++)
    {
        No=0;
        for(int j=0; j<N; j++)
        {
            if(x[i] < x[j] && y[i] < y[j])    // x값, y값 하나씩 비교
            {
                No++;
            }
        }
        printf("%d ", No+1);
    }
    return 0; 
}

/*
#include <stdio.h>

int main()
{
    int N;         // 전체 사람의 수
    int x[50]={};
    int y[50]={};
    int No=0;      // 등수
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);    // 전체 사람 수 만큼 x, y 배열에 저장
    }       
    
    for(int i=0; i<N; i++)
    {
        No=0;
        for(int j=i+1; j<N; j++)
        {
            if(x[i] < x[j] && y[i] < y[j])    // x값, y값 하나씩 비교
                No++;
        }
        printf("%d", No+1);
    }
    
    return 0;
        
        
    
}
*/
