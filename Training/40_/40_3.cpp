#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 10005
#define TURN_NUM_SIZE 10

using namespace std;

int main()
{
	int dp[ARRAY_SIZE_MAX][TURN_NUM_SIZE];    // DP[숫자 나사 번호][왼쪽 회전수] = 최소 회전수
	memset(dp, 0x3f, sizeof(dp));    // '0x3f' : 무한대 크기로 설정 
	int screw_num;    // 나사의 개수
	int now[ARRAY_SIZE_MAX];    // 현재 상태
	int target[ARRAY_SIZE_MAX];    // 원하는 상태
    
	scanf("%d", &screw_num);    // 나사 개수 입력
	for (int i = 1; i <= screw_num; i++) {
        	scanf("%1d", &now[i]);    // 현재 상태 입력, '%1d'로 1자리씩 입력
	}
    
 	for (int i = 1; i <= screw_num; i++) {
		scanf("%1d", &target[i]);    // 원하는 상태 입력, '%1d'로 1자리씩 입력
	}
    
	for (int i = 0; i <= TURN_NUM_SIZE - 1; i++) {
		dp[0][i] = i;    // 회전수에 따른 dp
	}
    
	for (int i = 1; i <= screw_num; i++) {
		for (int j = 0; j <= TURN_NUM_SIZE - 1; j++) {
			int left_cnt = (target[i] - j - now[i] + 20) % 10;    //  음수 방지를 위해 '+20', 나머지가 반복 되니 % 10
			int right_cnt = TURN_NUM_SIZE - left_cnt;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + right_cnt);
			dp[i][(j + left_cnt) % 10] = min(dp[i][(j + left_cnt) % 10], dp[i - 1][j] + left_cnt);
 		}
	}    
    
	int result = 1e9;
    
	for (int i = 0; i <= TURN_NUM_SIZE - 1; i++) {
		result = min(result, dp[screw_num][i]);
	}    
    
	printf("%d\n", result);    // 출력
    
	return 0;
}
