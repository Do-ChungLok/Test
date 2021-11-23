#include <stdio.h>

int main() {
    int A,B,C;
    int BEP=0;
    int n=0;
    
    scanf("%d %d %d", &A,&B,&C);
    n = A/(C-B);    // 판매량    n*c = A + n*B
    
    if( C>B )
        BEP= n + 1;
    else
        BEP=-1;
    
    printf("%d",BEP);
    
    return 0;
    
}
