#include <stdio.h>
#define SIZE_MAX 1024

int main(){
    int N, temp;
    int num[SIZE_MAX]={};
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++)
        scanf("%d",&num[i]);
    
    for(int i=1; i<N; i++){    // num[i]와 num[i+1] 하나씩 비교해서 작으면 왼쪽으로 이동 반복   
        for(int j=0; j<N; j++){
        
            if(num[i]<num[j]){
                temp=num[j];
                num[j]=num[i];
                num[i]=temp;
                
            }
        }
   }
    
    for(int i=0; i<N; i++){
        printf("%d\n",num[i]);
    }
    
    return 0;
}
