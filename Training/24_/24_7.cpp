#include <stdio.h>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

#define ARRAY_SIZE_MAX 101
#define DIRECTION_ARRAY_SIZE_MAX 7

using namespace std;
typedef struct {
int x, y, z;
}xyz;

queue<xyz> q;
int tomato[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];
int row_num;    // 상자 가로 칸 수
int col_num;    // 상자 세로 칸 수
int high_num;   // 상자 높이 칸 수
int dx[DIRECTION_ARRAY_SIZE_MAX] = { 1,0,-1,0,0,0 };    // x축 이동
int dy[DIRECTION_ARRAY_SIZE_MAX] = { 0,1,0,-1,0,0 };    // y축 이동
int dz[DIRECTION_ARRAY_SIZE_MAX] = { 0,0,0,0,1,-1 };    // z축 이동
int result;    // 최소날짜 + 1

void bfs() 
{
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        
        for (int i = 0; i < DIRECTION_ARRAY_SIZE_MAX; i++) {    // 이동 가능한 인접한 좌표 탐색
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_z = z + dz[i];
            
            if (next_z < 0 || next_z >= high_num || next_x >= row_num || next_x < 0 || next_y >= col_num || next_y < 0) 
                continue;
            if (tomato[next_z][next_x][next_y]!=0) 
                continue;
            q.push({ next_x, next_y, next_z });    // 큐에 새로운 좌표 삽입
            tomato[next_z][next_x][next_y] = tomato[z][x][y] + 1;    // 기존 좌표 날짜에 +1 해서 삽입
        }
    }
}

int main(void)
{
    cin >> col_num >> row_num >> high_num;    // 상자 가로 칸, 세로 칸, 높이 칸 입력
    int flag = 0;
    
    for (int k = 0; k < high_num; k++) {
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                cin >> tomato[k][i][j];    // 좌표 입력
                if (tomato[k][i][j]==1) 
                    q.push({ i,j,k });    // 익은 토마토(==1)라면 큐에 삽입
                if (tomato[k][i][j] == 0) 
                    flag = 1;
            }
        }
    }    
    
    if (flag==0) { //전부 0이면
    cout << 0;
    return 0;
    }
        
    bfs();
    
    for (int k = 0; k < high_num; k++) {    // 익지않은 토마토가 있는지 체크
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (tomato[k][i][j] == 0) {    // '0'이면 '-1' 출력
                    cout << -1;
                    return 0;
                }
                
                else if (tomato[k][i][j] >= result) 
                    result = tomato[k][i][j];
            }
        }
    }
    cout << result-1;
    return 0;
}


