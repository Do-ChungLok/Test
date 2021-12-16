#include <stdio.h>
#include <queue>
#include <memory.h>

#define ARRAY_SIZE_MAX 1001

using namespace std;

int spot_num = 0;    // 정점의 개수
int line_num = 0;    // 간선의 개수
int start_spot = 0;    // 탐색 시작할 정점의 번호
int spot_arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 간선이 연결하는 두 정점의 번호가 저장될 배열 
int from = 0, to = 0;    // 정점의 번호
int visited[ARRAY_SIZE_MAX];

void dfs(int start_spot)
{
    int i = 0;
    
    visited[start_spot] = 1;    // 방문했다는 표시
    printf("%d ", start_spot);    // 방문한 정점 출력
    
    for (i = 1; i <= spot_num; i++){    // 인접 정점 체크
        if (spot_arr[start_spot][i] == 1 && visited[i] == 0){    // 이동가능하고, 방문하지 않았다면 dfs(i) 호출
            dfs(i);
        }
    }
    if (i == spot_num){    // 'i'가 모든 정점을 탐색했다면 반환
        return;    
    }
}

void bfs(int start_spot)
{
    int i = 0;
    
    queue<int> q;    // 큐 생성
    
    q.push(start_spot);    // 시작점 큐에 삽입
    
    while (!q.empty()){
        int next_start_spot = q.front();    // 큐 맨앞 원소를 다음 탐색할 점으로 지정
        visited[next_start_spot] = 1;    // 방문했다는 표시
        
        printf("%d ", next_start_spot);    // 방문한 정점 출력
        
        q.pop();    // 큐 맨 앞 데이터 삭제
        
        for (i = 1; i <= spot_num; i++){
            if (spot_arr[next_start_spot][i] == 1 && visited[i] == 0){    // 'next_start_spot' 정점과 'i' 정점이 연결 되어있고, 방문하지 않았다면    
                q.push(i);    // 큐에 'i' 정점 삽입
                visited[i] = 1;    // 'i' 정점은 미리 방문 표시 (미리 하지 않으면 중복으로 체크될 가능성 있음)
            }
        }
    }
}

int main()
{
	scanf("%d %d %d", &spot_num, &line_num, &start_spot);    // 정점의 개수, 간선의 개수, 탐색 시작할 정점의 번호 입력
    
    for (int i = 0; i < line_num; i++){
        scanf("%d %d", &from, &to);
        
        spot_arr[from][to] = 1;
        spot_arr[to][from] = 1;
    }
    
    dfs(start_spot);
    
    printf("\n");
    memset(visited, 0, sizeof(visited)); // 방문기록 초기화
    
    bfs(start_spot);
    
    return 0;

}
