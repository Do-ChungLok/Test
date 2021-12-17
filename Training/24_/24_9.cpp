#include <queue>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE_MAX 1001
#define DRIECTION_ARRAY_SIZE_MAX 4
using namespace std;
 
typedef struct {
    int x, y;
}Dir;
 
Dir moveDir[DRIECTION_ARRAY_SIZE_MAX] = { {1,0},{0,1},{-1,0},{0,-1} };
 
bool map[ARRAY_SIZE_MAX ][ARRAY_SIZE_MAX];
int visited[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX][2]; // x, y, block 뚫을수 있는 횟수

int row;    // 행 수
int col;    // 열 수

bool is_inside(int _nx, int _ny) {
    return (_nx >= 1 && _nx <= row && _ny >= 1 && _ny <= col);
}
 
int bfs() {
    queue<pair<pair<int, int>, int > > q;
    q.push({ {1,1} , 1}); // x, y, block 뚫을수 있는 횟수
    visited[1][1][1] = 1;
 
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second;
        q.pop();
 
        if (x == row && y == col) {
            return visited[x][y][block];
        }
 
        for (int i = 0; i < DRIECTION_ARRAY_SIZE_MAX; i++) {
            int nx = x + moveDir[i].x;
            int ny = y + moveDir[i].y;
        
 
            // 맵을 벗어나지 않고,
            if (is_inside(nx, ny)) {    // 맵을 벗어나지 않는지 체크
                // 갈 수 없는 길(벽)이고, 벽을 아직 안뚫었을때
                if (map[nx][ny] == 1 && block) {    // '1' : 이동x , '0' : 이동가능
                    visited[nx][ny][block - 1] = visited[x][y][block] + 1;
                    q.push({ { nx,ny }, block - 1 });
                }
                // 갈 수 있는 길이고, 방문하지 않았다면
                if (map[nx][ny] == 0 && visited[nx][ny][block] == 0) {
                    visited[nx][ny][block] = visited[x][y][block] + 1;
                    q.push({ { nx,ny }, block });
                }
            }
        }
    }

    return -1;    // 목적지에 도착하지 못하고 탐색이 종료되었을때
}

int main()
{
    scanf("%d %d", &row, &col);    // 행, 열 수 입력
    
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    printf("%d\n", bfs());    // 결과 출력
    
    return 0;
}
