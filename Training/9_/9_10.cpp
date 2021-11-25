#include <stdio.h>
#define PI 3.14159265359
int main()
{
    int r;
    double result1, result2;
    
    scanf("%d",&r);
    result1 = (double)r * r * PI;    // 유클리드 기하학에서 반지름 r 일때 원 넓이
    result2 = (double)r * r * 1/2 * 4; // 택시 기하학에서 반지름 r 일때 원 넓이 -> 마름모(밑변, 높이가 r인 삼각형 4개)
    
    printf("%.6lf\n%.6lf",result1, result2);    // 소수점 5자리
    return 0;
    
    
}
