#include <stdio.h>
int main(){
    double A,B;
    scanf("%lf %lf",&A, &B);
    printf("%.11lf",A/B);    //10^-9이하 오차를 만들기 위해 11자리까지 출력
   
    return 0;
}
