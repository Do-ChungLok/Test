#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int node_num, from, to;    // 노드 개수, 연결된 두 정점
int parent[ARRAY_SIZE_MAX];    // 부모 노드 들어갈 배열
int visited[ARRAY_SIZE_MAX];    // 방문 여부 배열

vector<int> vec[ARRAY_SIZE_MAX];    // 노드 저장할 벡터

//     1    2    3    4    5    6    7
//     6    4    6    1    3    1    4
//     4         5    2         3    
//                    7
// --> DFS(1) -> DFS(6) 방문 : parent[6] = 1
// --> DFS(6) -> DFS(1) -> DFS(3) 방문 : parent[3] = 6
// --> DFS(3) -> DFS(6) -> DFS(5) 방문 : parent[5] = 3
// --> DFS(5) -> DFS(3) -> 다 방문 -> 끝
// --> DFS(1) -> DFS(4) 방문 : parent[4] = 1
// --> DFS(4) -> DFS(1) -> DFS(2) 방문 : parent[2] = 4
// --> DFS(4) -> DFS(2) -> DFS(7) 방문 : parent[7] = 4
// --> DFS(7) -> DFS(4) 방문 : 다 방문 -> 끝

void DFS(int start)    // 
{
	visited[start] = true;    // 방문
	for (int i = 0; i < vec[start].size(); i++) {
		int next = vec[start][i];
		if (!visited[next]) {    // 방문하지 않았다면
			parent[next] = start;    // 현재 노드 입력
			DFS(next);    // 다음 노드 반복
		}
	}
}

int main()
{
    scanf("%d", &node_num);    // 노드 개수
	for (int i = 1; i < node_num; i++) {
        scanf("%d %d", &from, &to);    // 연결된 두 정점 입력

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	DFS(1);    // 루트노드 1부터 시작

	for (int i = 2; i <= node_num; i++) {
        printf("%d\n", parent[i]);    // 부모노드 출력
	}    
}
