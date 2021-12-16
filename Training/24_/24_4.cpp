#include <stdio.h>
#include <cstring>    // memset

#define ARRAY_SIZE_MAX 51

int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 배추의 위치
int row;    // 배추밭의 가로길이
int col;    // 배추밭의 세로길이

int dfs(int x, int y)
{
	map[x][y] = 0;    // 배추가 있는곳(방문한 곳)은 '0'으로 바꾸기
    
	if (x + 1 < row && map[x + 1][y] == 1)    // 오른쪽 데이터 값이 1인 경우
		dfs(x + 1, y);
	if (x - 1 >= 0 && map[x - 1][y] == 1)  // 왼쪽 데이터 값이 1인 경우
		dfs(x - 1, y);
	if (y + 1 < col && map[x][y + 1] == 1)    // 위쪽 데이터 값이 1인 경우
		dfs(x, y + 1);
	if (y - 1 >= 0 && map[x][y - 1] == 1)    // 아래쪽 데이터 값이 1인 경우
		dfs(x, y - 1);
    
	return 0;
}


int main()
{
    int case_num;       // 테스트 케이스 수
    int cabbage_num;    // 배추가 심어져 있는 위치의 개수
    int from, to;    // 배추의 위치 좌표
    int bug_count;    // 지렁이 수
    
    scanf("%d", &case_num);
    for (int i = 0; i < case_num; i++){
        
        memset(map, 0, sizeof(map));    // 배열 초기화
        
        scanf("%d %d %d", &row, &col, &cabbage_num);    // 배추밭의 가로, 세로, 배추 수 입력
        
        for (int j = 0; j < cabbage_num; j++){
            scanf("%d %d", &from, &to);    // 
            map[from][to] = 1;    // 배추 위치에 '1' 넣기
        }
        
        bug_count = 0;
        
        for (int i = 0; i < row; i++){    // 지렁이 수 찾기
            for (int j = 0; j < col; j++){
                if (map[i][j] ==1){    // 좌표가 1인경우엔 dfs 함수 호출 후 지렁이 수 ++
                    dfs(i, j);
                    bug_count++;
                }
            }
        }
        
        printf("%d\n", bug_count);    // 지렁이 수 출력
    }

    return 0;
}
