#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 10005
#define TURN_NUM_SIZE 10

using namespace std;
 
int screw_num;
int now[ARRAY_SIZE_MAX], target[ARRAY_SIZE_MAX];
int dp[ARRAY_SIZE_MAX][TURN_NUM_SIZE];
int backward[ARRAY_SIZE_MAX][TURN_NUM_SIZE];
// backward[i][j] := i번째 나사가 왼쪽으로 j번 회전한 상태일 때 최적해에 도달하기 위해 왼쪽으로 회전한 칸수
int reconstruct[ARRAY_SIZE_MAX];
 
inline int circular(int x)
{
    while (x < 0)
        x += 10;
    return x % 10;
}
 
int main()
{
    memset(dp, 0x3f, sizeof(dp));    // '0x3f' : 무한대 크기로 설정 

    scanf("%d", &screw_num);    // 나사의 개수 입력
 
    for (int i = 1; i <= screw_num; i++)
        scanf("%1d", &now[i]);    // 현재 상태 입력, '%1d'로 1자리씩 입력

    for (int j = 1; j <= screw_num; j++)
        scanf("%1d", &target[j]);    // 원하는 상태 입력, '%1d'로 1자리씩 입력
    
    for (int i = 0;  i <= TURN_NUM_SIZE - 1; i++)
        dp[0][i] = i;    // 회전수에 따른 dp
    
    for (int i = 1; i <= screw_num; i++) {
        for (int j = 0; j <= TURN_NUM_SIZE - 1; j++) {
            int left_cnt = circular(target[i] - now[i] - j);
            int right_cnt = circular(-left_cnt);
 
            if (dp[i][j] > dp[i - 1][j] + right_cnt) {
                dp[i][j] = dp[i - 1][j] + right_cnt;
                backward[i][j] = j;
            }
 
            if (dp[i][circular(j + left_cnt)] > dp[i - 1][j] + left_cnt) {
                dp[i][circular(j + left_cnt)] = dp[i - 1][j] + left_cnt;
                backward[i][circular(j + left_cnt)] = j;
            }
        }
    }
 
    int result = 1e9, minshft;
 
    for (int i = 0; i <= TURN_NUM_SIZE - 1; i++) {
        if (result > dp[screw_num][i]) {
            result = dp[screw_num][i];
            minshft = i;
        }
    }
    printf("%d\n", result);    // 결과

    int idx = screw_num;
    while (idx) {
        if (backward[idx][minshft] == minshft) {
            reconstruct[idx] = -(dp[idx][minshft] - dp[idx - 1][minshft]);
        }    // 오른쪽으로 돌린 경우
        
        else {
            reconstruct[idx] = dp[idx][minshft] - dp[idx - 1][backward[idx][minshft]]; 
        }    // 왼쪽으로 돌린 경우
        
        minshft = backward[idx--][minshft];
        
    }
 
    for (int i = 1; i <= screw_num; i++) {
        if (reconstruct[i]) {
            printf("%d %d\n", i, reconstruct[i]);
        }
    }
}

