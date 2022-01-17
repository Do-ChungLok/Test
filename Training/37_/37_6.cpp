#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ARRAY_SIZE_MAX 20001

using namespace std;

int variable_num;  // 변수 개수
int clause_num;    // 절의 개수
int node_num, scc_num;    // 노드 개수, scc 개수
vector <int> go[ARRAY_SIZE_MAX];
bool finish[ARRAY_SIZE_MAX];
stack <int> st;	// 정점의 번호를 담는 스택	
vector <vector<int>> SCC;

int visited[ARRAY_SIZE_MAX];    // x번 정점을 몇 번째로 방문했는지
int low[ARRAY_SIZE_MAX];    // cross edge(이외의 나머지 모든 간선)를 제외한 간선을 통해서 이동할 수 있는 정점들 중 최소 visited
int in_degree[ARRAY_SIZE_MAX];

int notX(int x) 
{
	if (x > variable_num) {
		return x - variable_num;
	}
	
	else {
		return x + variable_num;
	}
}

void dfs(int x) 
{
	visited[x] = low[x] = ++node_num;
	st.push(x);

	for (int next : go[x]) {
		if (visited[next] == 0) { // Tree Edge(DFS 트리 상의 간선)인 경우
			// 방문하지 않은 정점이므로 dfs 실행
			// 자식의 low값으로 현재 정점의 low값을 update
			dfs(next);
			low[x] = min(low[x], low[next]);
		}
		else if (finish[next] == 0) { // Back Edge(자식에서 조상으로 가는 간선)인 경우
			// 자식의 visited 현재 정점의 low값을 update
			low[x] = min(low[x], visited[next]);
		}
	}

	// low[x] < visited[x] 일 경우에 더 위로 올라갈 수 있음
	if (visited[x] == low[x]) { // 위로 올라갈 방법이 없음
		vector <int> v;
		while (true) {
			int p = st.top();
			st.pop();

			v.push_back(p);
			finish[p] = true;
			in_degree[p] = SCC.size();
			if (x == p) {
                break;
            }
		}
		SCC.push_back(v);
	}
}


int main()
{
    scanf("%d %d", &variable_num, &clause_num);    // 변수 개수, 절의 개수 입력

	for (int i = 0; i < clause_num; i++) {
		int x, y;
        scanf("%d %d", &x, &y);    // xi 입력

		if (x < 0) {
            x = abs(x) + variable_num;
        }
        
		if (y < 0) {
            y = abs(y) + variable_num;
        }

		go[notX(x)].push_back(y);    // ~x -> y
		go[notX(y)].push_back(x);    // ~y -> x
	}

	for (int i = 1; i <= 2 * variable_num; i++) {
		if (visited[i] == 0)    // 방문하지 않은 경우 
            dfs(i);
	}

	for (int i = 1; i <= variable_num; i++) {
		finish[i] = finish[i + variable_num] = false;
	}

	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			int x = SCC[i][j];
			if (x > variable_num) {
				if (finish[x] || finish[notX(x)]) {
					printf("0 ");    // '0' 출력			
				}
			}
            
			else {
				if (finish[x] || finish[notX(x)]) {
					printf("0 ");    // '0' 출력	    	
				}
			}
            
			finish[x] = true;
		}
        
		for (int j = 0; j < SCC[i].size(); j++) {
			finish[SCC[i][j]] = false;
		}
	}
    
    printf("1\n");    // '1' 출력

	for (int i = 1; i <= variable_num; i++) {
		if (in_degree[i] > in_degree[notX(i)]) {
            printf("0 ");    // '0' 출력
        }
        
		else {
            printf("1 ");    // '1' 출력
        }
	}

	return 0;
}
