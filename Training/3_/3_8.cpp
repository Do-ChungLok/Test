#include <stdio.h>
int main(){
    int A,B;
    int T;
    
    scanf("%d", &T);
    for(int i=1 ; i<=T ; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i, A, B, A + B); 
    }
    return 0;    
}
