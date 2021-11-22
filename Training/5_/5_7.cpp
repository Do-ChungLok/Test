#include <stdio.h>

int main() {
    int C=0, N=0;
    scanf("%d\n", &C);
    
    for(int i=0; i<C ; i++)
    {
        scanf("%d", &N);
        int score[1000];
        int sum=0;
        double avg=0.00;
        
        for(int j=0; j<N; j++)
        {
            scanf("%d", &score[j]);
            sum += score[j];
        }        
            
        avg = (double)sum / N;
        int result=0;
        for(int j=0; j<N; j++)
        {
            if(score[j] > avg)
                result++;    
        }
        printf("%.3f%%\n",(double)result*100 / N); 
    }
    return 0;
}

