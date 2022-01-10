#include<iostream>
#include<algorithm>
using namespace std;

#define ARRAY_SIZE_MAX 1001

#define MOD 1000000003

int color_num;    // 색의 수
int select_color_num;    // 선택할 색의 수
int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];   // dp[N][K] = N 개 짜리 색상환에서 K 개를 인접하지 않게 칠하는 경우의 수

int main()
{    
    scanf("%d", &color_num);    // 색의 수 입력
    scanf("%d", &select_color_num);    // 선택할  색의 수 입력

	for (int i = 0; i < color_num; i++) {
		dp[i][0] = 1;    // 초기값
		dp[i][1] = i;    // 1 개의 색을 선택하는 경우의 수는 색의 수와 같음 
	}

	for (int i = 2; i <= color_num; i++) {
		for (int j = 2; j <= select_color_num; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;    // i 번째 색을 사용하지 않는 경우 + i 번째 색을 사용하는 경우
        }
    }
    
    printf("%d", (dp[color_num - 1][select_color_num] + dp[color_num - 3][select_color_num - 1]) % MOD);    // 결과 출력
    
    return 0;
}
