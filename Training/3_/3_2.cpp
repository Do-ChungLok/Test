#include <stdio.h>
int main(){
    int A,B;
    int T;
    
    scanf("%d",&T);
   
    for(int i=1 ; i<T+1 ; i++){
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);  
    }
 
    return 0;    
}
