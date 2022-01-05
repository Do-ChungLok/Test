#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INF 987654321
#define ARRAY_SIZE_MAX 20
using namespace std;

int num;    // 사람, 일의 수
int arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX] = { };
int dp[20][1 << ARRAY_SIZE_MAX + 1] = { };

int dfs(int now_node, int visited_bit) 
{
	if (visited_bit == (1 << num) - 1) {    // 모든 사람에 대해 탐색 -> ex) num : 3 -> 1000 - 1 = 0111
        return 0;
    }
    
	if (dp[now_node][visited_bit] != -1) {    // 이미 방문한 적 있음
        return dp[now_node][visited_bit];
    }

	dp[now_node][visited_bit] = INF;    // 초기화
	for (int i = 0; i < num; i++) {
		if (visited_bit & (1 << i)) {    // 이미 방문한 경우
            continue;
        }        
        
		dp[now_node][visited_bit] = min( dp[now_node][visited_bit], 
			dfs( now_node + 1, visited_bit | (1 << i) ) + arr[now_node][i] );    // dp에 최솟값을 갱신
	}
    
	return dp[now_node][visited_bit];
}

int main()
{

    scanf("%d", &num);    // 사람, 일의 수 입력

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
            scanf("%d", &arr[i][j]);    // 데이터 입력
        }
    }

	memset(dp, -1, sizeof(dp));    // '-1'로 초기화
        
    printf("%d", dfs(0, 0));    // 출력

    return 0;
}
