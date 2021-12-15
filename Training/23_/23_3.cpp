#include <iostream>
#include <cstring>

#define ARRAY_SIZE_MAX 503
#define DIRECTION_ROW 4
#define DIRECTION_COL 2

using namespace std;

int row_num, col_num;    // 행, 열의 수
int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 데이터 입력 배열
int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];
int dir[DIRECTION_ROW][DIRECTION_COL] = { {-1,0},{1,0},{0,-1},{0,1} };    // 상하좌우 4 방향 배열

int descent(int i, int j)
{
	if (i == row_num && j == col_num){    // 목적지에 도착하면 1 반환
        return 1;
    }
    
	if (dp[i][j] == -1){
        
		dp[i][j] = 0;    // 방문했다는 걸 표시
        
		for (int k = 0; k < 4; k++){
			int new_i = i + dir[k][0];
			int new_j = j + dir[k][1];
            
			if (new_i >= 1 && new_i <= row_num && new_j >= 1 && new_j <= col_num)
				if (map[i][j] > map[new_i][new_j]) {
                    dp[i][j] += descent(new_i, new_j);    // 도착지점에서부터 출발지점까지 역순으로 경우의 수를 추가
                }
		}
	}
    
	return dp[i][j];    // 현재 위치에서 갈 수 있는 곳이 없으면 지금 갈 수 있는 경우의 수 반환
}

int main() {
    scanf("%d %d", &row_num, &col_num);    // 행, 열 수 입력
	
	memset(dp, -1, sizeof(dp));    // dp배열 -1로 초기화
    
	for (int i = 1; i <= row_num; i++) {
        for (int j = 1; j <= col_num; j++) {
            scanf("%d", &map[i][j]);  // 행, 열 데이터 입력
        }
    }
    
    printf("%d\n", descent(1, 1));    // 출력

	return 0;
}
