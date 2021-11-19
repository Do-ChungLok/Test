#include <stdio.h>
int main(){
    int T;
    int A,B;
    
    scanf("%d", &T);
    for(int i=1 ; i<=T ; i++){
        scanf("%d", &A);
        scanf("%d", &B);
        printf("%d\n", A + B); 
    }
    return 0;    
}
