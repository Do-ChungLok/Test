#include <stdio.h>
#include <stdlib.h> // atoi() 사용 //

int main(){
    int A;
    char B[2];
    int x,y,z,w;
    
    scanf("%d",&A);
    scanf("%s",B);
    
    x=B[2] -'0'; // 아스키 코드에서 문자 0 => 10진수 48, 1 => 49, 2 => 50 ... ->> '48'차이니까 48을 빼주자 문자 48 = '0'
    y=B[1] -'0';
    z=B[0] -'0';
    w=atoi(B);	 // char형을 int형으로 변환
    
    printf("%d\n",A*x);
    printf("%d\n",A*y);
    printf("%d\n",A*z);
    printf("%d\n",A*w);
    
    return 0;
  
}

