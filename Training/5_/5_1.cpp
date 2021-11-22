#include <stdio.h>
int main(){
    int N, i;
    int max;
    int min;
    int num;
    max=-1000001;
    min=1000001;
    
    scanf("%d",&N);
   
    for(i=1; i<=N; i++){
    	scanf("%d",&num);

        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }
            
    }
    
    printf("%d %d",min, max);
    return 0;
    
}


