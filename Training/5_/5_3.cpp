#include <stdio.h>
int main(){
    int A, B, C;
    int result;
    int count[10]={};
    
    scanf("%d\n%d\n%d\n", &A,&B,&C);
    result = A * B * C; 
    
    while(result != 0){
        count[result % 10]++; // result 나누기 10하고 자릿수를 얻음
        result= result/10;    // 매 회 자리수를 줄이기 위해 10으로 나눔
        
    }
    
    for(int i=0; i<10; i++){
        printf("%d\n",count[i]);
    }
    return 0;
    
}


