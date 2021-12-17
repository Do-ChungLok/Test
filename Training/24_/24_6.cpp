#include <stdio.h>
#include <queue>

#define ARRAY_SIZE_MAX 1001
#define DIRECTION_ARRAY_SIZE_MAX 4

using namespace std;

int row_num;    // 상자 가로 칸 수
int col_num;    // 상자 세로 칸 수
int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 토마토 농장 좌표가 저장
int result = 0;    // 최소날짜 + 1

int dx[DIRECTION_ARRAY_SIZE_MAX] = {0, 0, 1, -1}; // x 축 이동 
int dy[DIRECTION_ARRAY_SIZE_MAX] = {1, -1, 0, 0}; // y 축 이동 

queue< pair<int, int> > q;    // 큐 선언

void bfs() {

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < DIRECTION_ARRAY_SIZE_MAX; i++) {    // 이동 가능한 인접한 좌표 탐색
            int next_x = x + dx[i]; 
            int next_y = y + dy[i];

            if (next_x >= 0 && next_y >= 0     // 지도를 벗어나지 않고
                && next_x < row_num 
                && next_y < col_num && map[next_y][next_x] == 0){ // 익지 않은 토마토가 '0' 이라면
                map[next_y][next_x] = map[y][x] +1;
                q.push({next_y, next_x});
              
            }
        }
    }
}

int main()
{
    scanf("%d %d", &row_num, &col_num);    // 상자 가로 칸, 세로 칸 입력
    
    for (int i = 0; i < col_num; i++){ 
        for (int j = 0; j < row_num; j++){
             scanf("%d ", &map[i][j]);    // 좌표 입력
            if (map[i][j] == 1){    // 익은 토마토라면 큐에 삽입
                q.push({i, j});
            }
        }
    }
    
    bfs();    // bfs 호출
    
    for (int i = 0; i < col_num; i++){     // 날짜 계산
        for (int j = 0; j < row_num; j++){
             
            if (map[i][j] == 0){    // 익지않은 토마토(=0)가 존재할 경우
                printf("-1\n");
                
                return 0;
            }
            
            if (result < map[i][j]){    // 며칠만에 익는지 판단
                result = map[i][j];
            }
        }
    }    
    printf("%d\n", result - 1);   

    return 0;
}
