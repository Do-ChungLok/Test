#include <stdio.h>

int main()
{
    int x, y, w, h;
    int distance_x, distance_y;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    distance_x = w-x <= x ? w-x : x;    // 꼭짓점들의 'x 좌표 차'와 원점에서 x좌표 거리 3항 비교
    distance_y = h-y <= y ? h-y : y;    // 꼭짓점들의 'y 좌표 차'와 원점에서 y좌표 거리 3항 비교
    
    // distance_x와 distance_y 작은 값 3항 비교
    printf("%d", distance_x <= distance_y ? distance_x : distance_y);

}
