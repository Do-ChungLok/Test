#include <stdio.h>
int main(){
    int A,B;
    scanf("%d %d",&A, &B);
    printf("%d\n",A+B);
    printf("%d\n",A-B);
    printf("%d\n",A*B);
    printf("%d\n",A/B);		// 나누기에서 몫을 구해야 하니 int형으로 정수
    printf("%d\n",A%B);
   
    return 0;
}
