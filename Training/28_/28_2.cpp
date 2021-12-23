#include <stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int spot_num, spot1 ,spot2, spot12_dist;    // 정점 개수, 정점1, 2, 거리
int node, result;    // 노드, 결과값
bool visited[ARRAY_SIZE_MAX];    // 방문 여부

vector< pair<int, int> > graph[ARRAY_SIZE_MAX];

void DFS(int x, int dist)
{
	visited[x] = true;    // 방문 체크   

	if (dist > result){    // 거리 업데이트 과정
		result = dist;
		node = x;
	}

	for (int i = 0; i < graph[x].size(); i++){
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
        
		if (!visited[next_node]){
			visited[next_node] = true;
			DFS(next_node, next_dist);
			visited[next_node] = false;
		}
		
	}
}

int main()
{
    
    scanf("%d", &spot_num);    // 노드 개수 입력

	for (int i = 1; i <= spot_num; i++){
		scanf("%d", &spot1);    // 정점1 입력
        
		while (true){
			scanf("%d", &spot2);    // 정점2 입력
            
			if (spot2 == -1) {    // 정점2가 -1이면 탈출
                break;
            }
            
			scanf("%d", &spot12_dist);    // 정점1,2 거리 입력
			graph[spot1].push_back({ spot2,spot12_dist });
		}
	}

	DFS(1, 0);    // 정점1에서 시작, dist는 0으로 시작
	result = 0;    // 0으로 초기화
    
	for (int i = 1; i <= spot_num; i++){
		visited[i] = false;
    }
    
	DFS(node, 0);    // 찾아낸 노드에서 가장 먼 점 탐색 -> 트리의 지름
    
	printf("%d", result);    // 결과 출력
    
    return 0;
}
