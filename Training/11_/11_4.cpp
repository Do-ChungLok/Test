#include <stdio.h>
#define small(x,y)x<y?x:y
int main()
{
    int N,M;
    char board[50][50]={};
    int count_B=0, count_W=0;
    int min=80;
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++)
    {
        scanf("%s", board[i]);
    }
    
    for(int i=0; i< N-7; i++)   
        for(int j=0; j< M-7; j++)
        {
            count_B=0;
            count_W=0;
            for(int a=i; a<i+8; a++)           
                for(int b=j; b<j+8; b++)
                {
                    if((a+b)%2 == 0)    // 행,열 index 값의 합이 짝수인 경우
                    {
                        if(board[a][b] == 'W')   // 경우1) 행,열 index 값의 합이 짝수일때 흰색인 경우에서 배열값이 검은색일때
                            count_B++;           // 흰색으로 바꿔야하는 변수 카운트 +1
                        if(board[a][b] == 'B')  // 경우2) 행,열 index 값의 합이 짝수일때 검은색인 경우에서 배열값이 흰색일때
                            count_W++;           // 검은색으로 바꿔야하는 변수 카운트 +1 
                    }
                    
                    else                // 행,열 index 값의 합이 홀수인 경우
                    {
                        if(board[a][b] == 'B')   // 경우1) 행,열 index 값의 합이 홀수일때 검은색인 경우에서 배열값이 흰색일때
                            count_B++;           // 검은색으로 바꿔야하는 변수 카운트 +1
                        if(board[a][b] == 'W')   // 경우2) 행,열 index 값의 합이 홀수일때 흰색인 경우에서 배열값이 검은색일때
                            count_W++;           // 흰색으로 바꿔야하는 변수 카운트 +1      
                    }
                }
            min=small(min,count_W);
            min=small(min,count_B); 
        }
    printf("%d",min);
    return 0;
}
