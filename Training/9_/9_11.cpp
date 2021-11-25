#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    double distance, subtract; // 거리, 차
    int x1,y1,r1, x2,y2,r2, result;
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &x1,&y1,&r1, &x2,&y2,&r2);
        distance = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));    // (x1, y1)과 (x2, y2)의 거리
        subtract = r1 > r2 ? r1 - r2 : r2 - r1;
        
        if(distance == 0 && r1 == r2)    // 좌표를 이었을때 생기는 두 원이 완전히 일치하는 경우
        {
            result = -1;
        }
        else if(distance < r1 + r2 && (subtract < distance))    // 두 원의 교점이 2개인 경우
        {
            result = 2;
        }
        else if(distance == r1 + r2 || distance == subtract)    // 두 원의 교점이 1개인 경우
        {
            result = 1;
        }
        else    // 두 원의 교점이 없는 경우
            result = 0;
        
        printf("%d\n", result);
    }
}

