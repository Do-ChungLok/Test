#include <stdio.h>
int main(){
    int N, M=0;
    float score[1000], total=0, avg=0;
    
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%f", &score[i]);
    }   
    
    for(int i=0; i<N; i++){	// 최대 점수 찾기
        if(score[i]>M)
            M = score[i];
    }
    
    for(int j=0; j<N; j++){
        score[j] = score[j]/M*100.0; 
        total += score[j];	// 새로운 점수의 합
    }
    
    avg = total / N;	// 새로운 평균
    
    printf("%f\n",avg);	

    return 0;
    
}


