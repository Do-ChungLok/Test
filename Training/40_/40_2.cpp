#include <stdio.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 1001

using namespace std;

int row, col;    // 행, 열 변수
int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 데이터 저장할 배열
int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];
int Right[ARRAY_SIZE_MAX];    // 오른쪽으로 이동하는 배열
int Left[ARRAY_SIZE_MAX];     // 왼쪽으로 이동하는 배열

int main(void)
{
	scanf("%d %d", &row, &col);    // 행, 열 입력

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &map[i][j]);    // 데이터 입력
        }
    }
		
	dp[0][0] = map[0][0]; // 시작값

	for (int j = 1; j < col; j++) { // 1행 dp 생성
		dp[0][j] += dp[0][j - 1] + map[0][j];
    }


	for (int i = 1; i < row; i++) {
		// 맨 왼쪽 = > 오른쪽으로 검사
		Right[0] = dp[i - 1][0] + map[i][0];
		for (int j = 0; j < col - 1; j++) {
			Right[j + 1] = max(Right[j], dp[i - 1][j + 1]) + map[i][j + 1];
        }

		// 맨 오른쪽 = > 왼쪽으로 검사
		Left[col - 1] = dp[i - 1][col - 1] + map[i][col - 1];
        
		for (int j = col - 2; j >= 0; j--) {
			Left[j] = max(Left[j + 1], dp[i - 1][j]) + map[i][j];
        }

		// Right배열과 Left배열중 큰 값 dp에 저장
		for (int k = 0; k < col; k++) {
			dp[i][k] = max(Right[k], Left[k]);
        }
	}

	printf("%d", dp[row - 1][col - 1]);    // 출력
    
    return 0;

}
