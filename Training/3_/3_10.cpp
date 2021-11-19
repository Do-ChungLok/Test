#include <stdio.h>
int main(){
    int N;
  
    scanf("%d", &N);
    for(int row=1 ; row<=N ; row++){   // '행'의 개수는 입력한 N 개수까지
        for(int i=1 ; i<=N-row ; i++){ // '한 행'의 '공백'의 개수는 N - 현재 행(row)과 동일
                printf(" ");     
        }
        for(int i=1 ; i<=row ; i++){   // '한 행'의 '*'의 개수는 현재 행(row)과 동일
                printf("*"); 
        }
        printf("\n");      
    }    
    return 0;    
}
