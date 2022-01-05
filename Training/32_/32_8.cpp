#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;
 
int main()
{
    int x, y, d, t;
    while (scanf("%d %d %d %d", &x, &y, &d, &t) > 0){
        double dist = sqrt(x * x + y * y);
        int jump = dist / d;    // jump : 집의 방향으로만 점프하여 집을 지나치지 않을 수 있는 최대 횟수
        double spare = dist - jump * d;    // spare : jump번 집의 방향으로만 점프한 후 남은 집과의 거리
        double result = dist;    // 첫 번째 후보: 점프하지 않고 끝까지 걸어가기
        result = min(result, spare + jump * t);    // 두 번째 후보: jump번 점프한 후 걸어가기
        
        if (jump > 0) {
            result = min(result, (jump+1) * t * 1.0);    // 세 번째 후보: jump+1번 점프로 방향을 꺾어서 도착하기
        }
        
        else {
            result = min(result, d - spare + t);    // 네 번째 후보: 1번 점프한 후 역방향으로 걸어오기
            if (dist < d) {    // 다섯 번째 후보: 2번 점프로 도착하기
                result = min(result, t * 2.0);
            }
        }
        printf("%.10lf\n", result);    // 오차는 10^-9 까지 허용
    }
    
    return 0;
}


