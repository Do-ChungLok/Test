#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MOD 9901
#define COL_SIZE_MAX 14
#define ROW_SIZE_MAX 14

using namespace std;

int col;    // 세로 크기
int row;    // 가로 크기
int dp[COL_SIZE_MAX * ROW_SIZE_MAX][(1 << ROW_SIZE_MAX) - 1];


int go(int idx, int status)
{
    if (idx >= col * row){
        if (idx == col * row && status == 0)
            return 1;
        return 0;
    }
    
    int& ret = dp[idx][status];
    if (ret != -1)
        return ret;
    ret = 0;
    
    if (status & (1 << 0)) {	// 이미 idx번 째 칸이 채워져 있는 경우
        ret += go(idx + 1, status >> 1);
    }
    
    else {	// idx번 째 칸을 채워야 하는 경우
        	// idx번 째 칸에 2 X 1 도미노를 채우는 경우
        	// 현재 행에서 맨 마지막 열에 위치한 칸이면 2 X 1 도미노 채우지 못 함
        	// idx + 1번 째 칸이 비어 있는지 확인해야 함
        if (idx % row < (row - 1) && (status & (1 << 1)) == 0){
            ret += go(idx + 2, status >> 2);
        }
        
        // idx번 째 칸에 1 X 2 도미노를 채우는 경우
        // 어차피 i번 째 바로 밑에 있는 칸은 비어 있을 수밖에 없음
        
        ret += go(idx + 1, (status >> 1) | (1 << (row - 1)));
    }
    
    ret %= MOD;
    
    return ret;
}


int main()
{
    memset(dp, -1, sizeof(dp));	// dp 초기 크기 '-1'로 초기화
    scanf("%d %d", &col, &row);	// 세로, 가로 입력
    	
    printf("%d\n", go(0, 0));		// 출력
    
    return 0;
}
