#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define n_MAX_SIZE 100001
#define d_MAX_SIZE 20

using namespace std;

int node_num;    // 노드 개수
int pair_num;    // 쌍의 개수
int a, b;
queue <int> q;
vector <int> node[n_MAX_SIZE];
bool visited[n_MAX_SIZE];
int parent[n_MAX_SIZE][d_MAX_SIZE];    // n의 2^d 번째 부모
int depth[n_MAX_SIZE];

void BFS()
{
    while (!q.empty()) {
        int x = q.front(); // 부모 노드
        q.pop();

		for (int i = 0; i < node[x].size(); i++) {
			int child = node[x][i];

			if (!visited[child]) {    // 현재노드를 방문한적 없다면
                depth[child] = depth[x] + 1;    // 깊이 +1
				visited[child] = true;    // 방문표시
				parent[child][0] = x;
                
				for (int j = 0; j < 20; j++) {    // 부모노드 입력
				
					// 현재노드에서 2^(j+1) 위에 있는 부모 노드는 
					// 2^j 위에 있는 부모노드의 2^j 위에 있는 부모노드
                    parent[child][j + 1] = parent[parent[child][j]][j];

					if (parent[child][j + 1] == 0)    // 2^(j+1) 위에 부모노드가 없을 경우     
                        break;
				}

				q.push(child);    // 큐에 추가
			}
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] > depth[b])    // v가 u보다 더 깊은 노드로 세팅     
        swap(a, b);

	while (depth[a] != depth[b]) {    // 두 노드의 깊이가 같아질때까지 v노드는 위로 거슬러 올라감
		int dist = depth[b] - depth[a];    // 두 노드의 깊이 차이

		for (int i = 0; i < 20; i++) {    // 2^i 만큼 거슬러 오라감
			if (dist <= (2 << i)) {
				b = parent[b][i];
				break;
			}
		}
	}

	while (a != b) {    // 두 노드가 같아질때 까지 위로 거슬러 올라감
		for (int i = 0; i < 20; i++) {
			if (parent[a][i + 1] == parent[b][i + 1]) {
				a = parent[a][i];
				b = parent[b][i];
				break;
			}
		}
	}
    
	return a; // LCA 리턴
}

int main()
{
    scanf("%d", &node_num);    // 노드 개수 입력
    
	// 해당노드에 연결된 노드 push
	for (int i = 0; i < node_num - 1; i++) {
        scanf("%d %d", &a, &b);    // 쌍 입력
		node[a].push_back(b);
		node[b].push_back(a);
	}

	visited[1] = true;
	q.push(1); // 트리의 루트 

    BFS();    // BFS 함수 호출
    scanf("%d", &pair_num);    // 쌍의 개수 입력

	for (int i = 0; i < pair_num; i++) {
        scanf("%d %d", &a, &b);    // 쌍 입력

        printf("%d\n", LCA(a,b));    // 출력
	}

    return 0;
}
