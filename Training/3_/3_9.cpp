#include <stdio.h>
int main(){
    int N;
  
    scanf("%d", &N);
    for(int i=1 ; i<=N ; i++){
        
        for(int j=1 ; j <= i ; j++){ // * 갯수 반복
				printf("*"); 
        }
        printf("\n");
    }    
    return 0;    
}
