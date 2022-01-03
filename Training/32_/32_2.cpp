#include<stdio.h>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)    // 외적
{
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp = temp - y1*x2 - y2*x3 - y3*x1;
    
    if (temp > 0) {    // 외적 값이 0 보다 크다면 '1' 반환
        return 1;      
    } 
    
    else if (temp < 0) {    // 외적 값이 0 보다 작다면 '-1' 반환
        return -1; 
    } 
    
    else {    // 외적 값이 0이라면 '1' 반환
        return 0;
    }
}

int main()
{
    int a1, b1, a2, b2, a3, b3;    // 좌표 3쌍
    scanf("%d %d", &a1, &b1);    // 좌표1 입력
    scanf("%d %d", &a2, &b2);    // 좌표2 입력
    scanf("%d %d", &a3, &b3);    // 좌표3 입력

    printf("%d", ccw(a1, b1, a2, b2, a3, b3));    //출력
    
    return 0;
}
