#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

vector <int> tree[ARRAY_SIZE_MAX];

int spot_num;       // 정점의 수
int root_number;    // 루트의 번호
int query_num;      // 쿼리의 수
int dp[ARRAY_SIZE_MAX]; // i번째 노드 서브트리의 노드 수
bool visited[ARRAY_SIZE_MAX];    // 방문여부

void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i];
		if (visited[next_node] == 0) {    // 방문하지 않았다면
			dfs(next_node);               
			dp[node] += dp[next_node];    // 자식들의 값을 계속 더함
		}
	}
}

int main()
{
    scanf("%d %d %d", &spot_num, &root_number, &query_num);    // 저엄의 수, 루트의 번호, 쿼리의 수 입력
    
	for (int i = 1; i < spot_num; i++) {
		int line1, line2;    // 간선1, 2
        scanf("%d %d", &line1, &line2);    // 간선의 정보 입력

		tree[line1].push_back(line2);
		tree[line2].push_back(line1);
		dp[line1] = 1;    // 초기값 1로 설정
		dp[line2] = 1;    // 초기값 1로 설정
	}

	dfs(root_number);    // dfs 함수 호출

	while (query_num--) {
		int node;
        
        scanf("%d", &node);          // 노드 입력
        printf("%d\n", dp[node]);    // 출력
	}

	return 0;
}

