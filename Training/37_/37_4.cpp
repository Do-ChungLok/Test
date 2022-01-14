#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>

#define ARRAY_SIZE_MAX 500001

using namespace std;

vector <int> vec[ARRAY_SIZE_MAX], revrse_vec[ARRAY_SIZE_MAX], vv[ARRAY_SIZE_MAX];
// vec는 주어진 방향 그래프 , revrse_vec 는 주어진 역방향 그래프 , vv 는 사이클을 정점화한 새로운 그래프

int cash[ARRAY_SIZE_MAX], scc_cash[ARRAY_SIZE_MAX];
// cash : 초기 그래프에서 하나의 정점의 수금할 수 있는 돈, scc_cash 는 scc 사이클의 돌면서 수금한 돈

bool check[ARRAY_SIZE_MAX], rc[ARRAY_SIZE_MAX]; 
// 해당 정점에 레스토랑이 있는지, 해당 정점 또는 사이클에 레스토랑이 있는지

int visited[ARRAY_SIZE_MAX];    // 방문여부

stack <int> st; // 코살라주 알고리즘을 위한 스택

void dfs(int u)
{
	visited[u] = 1;
	for (auto a : vec[u]) {
		if (visited[a] == 0) {
            dfs(a);
        }
	}
	st.push(u); 
}

int solve(int st,int cnt) // 사이클을 구하는 함수
{    
	visited[st] = cnt; // 해당 정점이 어느 그룹에 속하는지 체크
	int cost = cash[st];
	if (check[st]) {
        rc[cnt] = 1; // 사이클을 구하는 도중 레스토랑이 포함되있다면 cnt 번째 사이클은 레스토랑이 포함
    }

	for (auto a : revrse_vec[st]) {
		if (visited[a] == 0) {
            cost += solve(a,cnt);
        }
	}
    
	return cost; // 사이클의 수금액
}


int bfs(int s) 
{
	memset(visited, 0, sizeof(visited));
	priority_queue <pair<int, int>> q; // 우선순위 큐
	q.push( {scc_cash[s], s} );
	visited[s] = scc_cash[s]; // 시작지에서 수금한 돈

	int res = 0;
	while (!q.empty()) {
		
		int n = q.top().second;
		int cost = q.top().first;

		if (rc[n] == 1) {
            res = max(res, cost); // 레스토랑이라면 최댓값 갱신
        }
		
		q.pop();

		for (auto a : vv[n]) {
			if (cost + scc_cash[a] > visited[a]) { 
                // 현재 큐에서 쌓인 비용과 다음 정점의 비용의 합이 
                // a 정점에 지금까지 갱신된 값보다 크다면
				q.push({ cost + scc_cash[a],a});
				visited[a] = cost + scc_cash[a];
			}
		}
	}

	return res;
}

int main() 
{
	int intersection_num, road_num, from_num, to_num;
    
    scanf("%d %d", &intersection_num, &road_num); // 교차로의 수, 도로의 수 입력

	for (int i = 0; i < road_num; i++) {
        scanf("%d %d", &from_num, &to_num);    // 교차로 시작 번호, 끝 번호 입력
		
		vec[from_num].push_back(to_num);
		revrse_vec[to_num].push_back(from_num);
	}
    
	for (int i = 0; i < intersection_num; i++) {
        scanf("%d", &cash[i + 1]);    // atm이 보유한 현금의 액수 입력
    }
	
	int start_number, rest_num;    // 출발 교차로 번호, 레스토랑 개수  
    scanf ("%d %d", &start_number, &rest_num);    // 출발 교차로 번호, 레스토랑 개수 입력
    
	for (int i = 0; i < rest_num; i++) {
        scanf("%d", &from_num);    // 레스토랑이 있는 교차로 번호 입력
        check[from_num] = 1;
	}

	for (int i = 1; i <= intersection_num; i++) {
		if (visited[i] == 0) {
            dfs(i);
        }
	}

	memset(visited, 0, sizeof(visited));

	int cnt = 1; // 새로 생길 사이클의 정점
	while (!st.empty()) {
		int t = st.top();
		st.pop();

		if (visited[t]) {
            continue;
        }

		scc_cash[cnt] = solve(t,cnt);
		cnt++;
	}

	for (int i = 1; i <= intersection_num; i++) {
		for (auto from_num : vec[i]) {
			if (visited[from_num] == visited[i]) {
                continue;
            }
            
			int c = visited[i], cash = visited[from_num];
			vv[c].push_back(cash);
		}
	}
    printf("%d\n", bfs(visited[start_number]));    // 출력
           
    return 0;
}
