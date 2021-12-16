#include <stdio.h>
#include <queue>

#define ARRAY_SIZE_MAX 101

using namespace std;

int target_row;    // 목표 x 좌표
int target_col;    // 목표 y 좌표
int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 배추의 위치
bool visited[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 방문여부
int length[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 이동거리
int dx[4] = {0, 0, 1, -1}; // x 축 이동 
int dy[4] = {1, -1, 0, 0}; // y 축 이동 

void bfs(int x, int y) {
    queue< pair<int, int> > q;    // 큐 선언
    
    q.push(make_pair(y, x));
    length[y][x] = 1;
    visited[y][x] = true;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {    // 이동 가능한 인접한 좌표 탐색
            int next_x = x + dx[i]; 
            int next_y = y + dy[i];

            if (next_x >= 0 && next_y >= 0     // 지도를 벗어나지 않고
                && next_x < target_col 
                && next_y < target_row && map[next_y][next_x] == 1 // 칸의 값이 1이라서 이동할 수 있다면
                && visited[next_y][next_x] == false) {    // 아직 방문하지 않았다면
                
                length[next_y][next_x] = length[y][x] + 1; // 총 이동 거리 계산 (이전 방문값 +1)
                visited[next_y][next_x] = true;
                q.push(make_pair(next_y, next_x));
            }
        }
    }
}

int main()
{
    scanf("%d %d", &target_row, &target_col);    // 목표 x좌표, y좌표 입력
    
    for (int i = 0; i < target_row; i++){ 
        for (int j = 0; j < target_col; j++){
             scanf("%1d", &map[i][j]);    // 좌표 입력
        }
    }
    
    bfs(0, 0);    // bfs 호출
    
    printf("%d\n", length[target_row - 1][target_col - 1]);    // 최단거리 출력

    return 0;
}
