#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int domino_num, relation_num;    // 도미노 개수, 관계 개수
int count, dfsn[ARRAY_SIZE_MAX];
bool finished[ARRAY_SIZE_MAX];
vector <int> adj[ARRAY_SIZE_MAX];
vector <vector <int> > SCC;
stack <int> s;
int group[ARRAY_SIZE_MAX];
bool in_degree[ARRAY_SIZE_MAX]; // 각각의 정점의 진입차수가 몇인지 확인

int dfs(int x) 
{
	dfsn[x] = ++count;
	s.push(x);    // 스택s 에 x번호를 push
	int parent = dfsn[x];
    
	for (int i = 0; i < adj[x].size(); i++) {
		int next = adj[x][i];
        
		if (dfsn[next] == 0) {    // 방문 안 한 경우
			parent = min(parent, dfs(next)); 
        }
        
		else if (finished[next] == 0) { // 방문은 했지만 scc로 분류되지 않은 경우
			parent = min(parent, dfsn[next]);
        }
	}
    
	if (parent == dfsn[x]) { // 현재 데이터와 자손들이 같은경우 scc 분류
		vector<int> scc; // scc 선언
        
		while (1) {
			int t = s.top(); 
			s.pop(); // 스택에서 꺼낸다.
			scc.push_back(t);
			group[t] = SCC.size() + 1; // 특정한 SCC에 속해있는 모든 
			// 정점들이 SCC크기에 1을 더해준값을 넣어주는것
			// 첫번째 SCC에 들어있는 애들은 1값을 가질것이고
			// 두번째 SCC에 들어있는 애들은 2값을 가짐
			// 그룹값을 기준으로 어떤 SCC에 포함되어있는지 구별 가능
			finished[t] = true;
			if (t == x)
				break;
		}
		SCC.push_back(scc); // 만들어진 scc를 SCC에 넣는다.
	}
	return parent;
}

int main() 
{
	int case_num; // 테스트케이스의 수
	scanf("%d", &case_num);
    
	while (case_num--) { // 테스트케이스만큼 반복.
		SCC.clear();

		memset(dfsn, 0, sizeof(dfsn)); // d 값을 초기화
		memset(finished, 0, sizeof(finished)); // 끝났는지 판별 초기화 0
		memset(in_degree, 0, sizeof(in_degree)); // 진입차수 초기화 0        
        
		scanf("%d %d", &domino_num, &relation_num); // 정점과 간선정보
        
		for (int i = 1; i <= domino_num; i++) {
			adj[i].clear();
		}
        
		for (int i = 0; i < relation_num; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y); // x넘어뜨리면 y도 넘어진다.
		}
        
		for (int i = 1; i <= domino_num; i++) { // 모든 노드에 대해서 dfs
			if (dfsn[i] == 0)
				dfs(i);
		}

		for (int i = 1; i <= domino_num; i++) { 
			for (int j = 0; j < adj[i].size(); j++) { // i도미노에 연결된 도미노들을 순회하며
				int y = adj[i][j]; // 연결되어진 정점을 y로 함
				if (group[i] != group[y]) // y와 i가 속한 그룹이 다르다면
					in_degree[group[y]] = true; // y가 속한 SCC의 그룹 값을 true로 즉 진입차수가 존재
			}
		}

		int result = 0;    // 결과값
        
		for (int i = 1; i <= SCC.size(); i++) { // SCC들을 확인하면서
			if (!in_degree[i]) // 진입차수가 0인경우에만 (손으로 도미노를 넘기는경우)
				result++; // 갯수 증가
		}
		printf("%d\n", result);    // 결과값 출력
	}
	return 0;
}
