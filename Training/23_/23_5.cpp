#include<stdio.h>
#include <cmath>
#include <cstring>

#define ARRAY_SIZE_MAX 31
#define CHU_WEIGHT_NUM_MAX 31
#define CHU_WEIGHT_MAX 31 * 500
#define BEAD_WEIGHT_MAX 8
#define CHU_WEIGHT_FULL 30 * 500

using namespace std;

int chu_num;                    // 추의 개수
int chu_weight_arr[ARRAY_SIZE_MAX];    // 추의 무게를 저장할 배열
int bead_num;    // 구슬의 개수
int bead_weight_arr[BEAD_WEIGHT_MAX]; // 구슬의 무게를 저장할 배열
int dp[CHU_WEIGHT_NUM_MAX][CHU_WEIGHT_MAX];    // 추의 개수 MAX, 추의 무게 MAX 배열 생성
// dp[x][y] : x번까지의 추를 사용하여 y무게를 측정할 수 있는지 판단

void dfs(int i, int weight)
{
    if (i > chu_num){    // 추를 이미 다 올린 경우
        return;
    }
    
    if (dp[i][weight] != -1){    // 갱신된 값인 경우
        return;
    }
    
    dp[i][weight] = true;
    
    dfs(i + 1, abs(weight - chu_weight_arr[i]));    // i번째 무게추를 구슬쪽 저울에 올리기
    dfs(i + 1, weight);    // 어느곳이든 추를 안 올림
    dfs(i + 1, weight + chu_weight_arr[i]);    // i번째 무게추를 구슬 반대쪽 저울에 올리기
}

int main()
{
	scanf("%d", &chu_num);    // 추의 개수 입력
    
	for (int i = 0; i < chu_num; i++)
	{
		scanf("%d ", &chu_weight_arr[i]);    // 추의 무게 입력
	}
	
    memset(dp, -1, sizeof(dp));    // dp배열 -1로 초기화
    
    dfs(0, 0);
    
	scanf("%d", &bead_num);    // 구슬의 개수 입력

	for (int i = 0; i < bead_num; i++)
	{
		scanf("%d ", &bead_weight_arr[i]);    // 구슬의 무게 입력
        
        if (bead_weight_arr[i] > CHU_WEIGHT_FULL){    // 추의 개수 30개 * 무게 500g 이하니까 30 * 500 보다 클 수가 없음 크다면 'N' 출력
            printf("N ");
        }
        
        else if (dp[chu_num][bead_weight_arr[i]] == 1){
            printf("Y ");
        }
        
        else{
            printf("N ");
        }

	}
    return 0;

}
