#include <stdio.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

#define ARRAY_SIZE_MAX 1001

using namespace std;

int road_num;    // 동서방향 도로 수
int case_num;    // 처리해야하는 사건의 수
int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];  
// ex) dp[i][j] i: 1번 경찰차가 마지막으로 방문한 곳 j: 2번 경찰차가 마지막 방문 했을때 최소값

pair <int, int> work[ARRAY_SIZE_MAX];

int dist(pair <int, int> a, pair <int, int> b)
{
    return abs(b.first - a.first) + abs(b.second - a.second);
}

int dp_func(int x, int y)
{
    if (x == case_num || y == case_num){
        return 0;
    }
    
    int &cache = dp[x][y];
    if (cache != -1){
        return dp[x][y];
    }
    
    int next = max(x, y) + 1;    // 다음 사건 번호 = 지금까지 처리한 사건 번호 중 최댓값 + 1
    int dist1, dist2;
    
    if (x ==0){    // 'x'가 next로 움직이는 경우
        dist1 = dist({1, 1}, work[next]);
    }
    
    else {
        dist1 = dist(work[x], work[next]);
    }
    
    if (y == 0){    // 'y'가 next로 움직이는 경우
        dist2 = dist({road_num, road_num}, work[next]);
    }
    
    else {
        dist2 = dist(work[y], work[next]);
    }
    
    cache = min(dp_func(next, y) + dist1, dp_func(x, next) + dist2);
    return cache;
}

void tracking(int x, int y)
{
    if (x == case_num || y == case_num){
        return;
    }
    
    int next = max(x, y) + 1;    // 다음 사건
    int dist1, dist2;

    if (x ==0){    // 'x'가 next로 움직이는 경우
        dist1 = dist({1, 1}, work[next]);
    }
    
    else {
        dist1 = dist(work[x], work[next]);
    }
    
    if (y == 0){    // 'x'가 next로 움직이는 경우
        dist2 = dist({road_num, road_num}, work[next]);
    }
    
    else {
        dist2 = dist(work[y], work[next]);
    }
    
    if (dp[next][y] + dist1 > dp[x][next] + dist2) {
        printf("2\n");
        tracking(x, next);
    }
    
    else {
        printf("1\n");
        tracking(next, y);
    }
    
    return;    
}

int main()
{
    scanf("%d", &road_num);    // 도로의 수 입력
    scanf("%d", &case_num);    // 사건의 수 입력
    
    for (int i = 1; i <= case_num; i++){
        scanf("%d %d", &work[i].first, &work[i].second);    // 사건 발생 위치
    }
    
    memset(dp, -1, sizeof(dp));    // dp '-1'로 초기화
    
    printf("%d\n", dp_func(0, 0));    // 출력
    tracking(0,0);
    
    return 0;
}
