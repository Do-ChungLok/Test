#include <queue>
#include <stdio.h>
#include<cstring>

#define ARRAY_SIZE_MAX 300
#define DRIECTION_ARRAY_ROW_SIZE_MAX 8
#define DRIECTION_ARRAY_COL_SIZE_MAX 2

using namespace std;
 
int current_x, current_y, target_x, target_y;    // 현재 x, y 위치, 이동하려는  x, y 위치
int length;    // 체스판 한 변의 길이
int count;    // 이동 횟수 저장 변수

int dx[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };    // x축 이동
int dy[8] = { 2,1,-2,-1,-1,-2,1,2 };           // y축 이동

int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];         // 좌표 저장 배열
bool visited[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 방문 여부 배열

void bfs(int x, int y)
{
	visited[x][y] = true;
    
	queue<pair<pair<int, int>, int>> q;    // 큐 선언

    q.push(make_pair(make_pair(x, y), 0));    // 처음은 x, y 값과 이동 횟수가 0이니 0 대입

	while (!q.empty()){
        //  큐에 다음 나올 x, y 값이 도착 값과 같다면
		if (q.front().first.first == target_x && q.front().first.second == target_y){
        // 그때에 이동 횟수를 저장하고 끝냄
			count = q.front().second; 
			return;
		}
        
		for (int i = 0; i < DRIECTION_ARRAY_ROW_SIZE_MAX; ++i){
			int target_x = q.front().first.first + dx[i];
			int target_y = q.front().first.second + dy[i];
			int num = q.front().second;
            
			if (target_y >= 0 && target_y < length && target_x >= 0 && target_x < length)
            // 범위에 벗어나지 않는다면
				if (visited[target_x][target_y] == false){    // 방문 안 한곳은 했다고 표시
					visited[target_x][target_y] = true;    

					q.push(make_pair(make_pair(target_x, target_y), num + 1));    // num은 다음 칸으로 이동하니 +1
				}
		}
		q.pop();
	}
}

int main()
{
    int case_num;    // 테스트 케이스 수
    
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    for (int i = 0; i < case_num; i++){
        
		memset(map, 0, sizeof(map));    // 케이스 수가 여러개이므로 배열 초기화
		memset(visited, 0, sizeof(visited));  // 케이스 수가 여러개이므로 배열 초기화
        
        count = 0;
        
        scanf("%d", &length);    // 한 변의 길이 입력
        scanf("%d %d", &current_x, &current_y);    // 현재 x, y 입력
        scanf("%d %d", &target_x, &target_y);      // 목표 x, y 입력
        
        bfs(current_x,current_y);    //bfx 함수 호출
        
        printf("%d\n", count);    // 이동횟수 출력

    }
    
    return 0;
}
