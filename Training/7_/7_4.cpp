#include <stdio.h>
#include <string.h>

int main() {
    int T;
    int R;
    char S[20];
    
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        scanf("%d %s",&R, S);
        for(int j=0; j<strlen(S); j++)
        {
            for(int k=0; k<R; k++)    // R 수 만큼 s[j] 반복
                printf("%c",S[j]);
        }
                printf("\n");
     }   
}
