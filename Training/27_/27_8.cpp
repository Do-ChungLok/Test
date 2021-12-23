#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ARRAY_SIZE_MAX 20001

using namespace std;

int INF = INT_MAX;
int city_num = 0;    // 도시의 수
int bus_num = 0;     // 버스의 수

vector<pair<int, int>> graph[ARRAY_SIZE_MAX];

void dijkstra(int start, int end) {
	priority_queue<pair<int, int>> que;
	vector<int> dist(city_num + 1, INF);
	vector<int> route(city_num + 1); // 최소 비용을 가지는 경로상에 포함된 도시

	dist[start] = 0;
	que.push({ 0,start });

	while (!que.empty()) {
		int idx = que.top().second; // 가장 경로가 짧은 정점의 도착지
		int cost = -que.top().first; // 가장 짧은 경로의 경로값 , '-'를 붙여 우선순위 반전
		que.pop();

		if (dist[idx] < cost) {
			// 큐에 저장된 값보다 dist의 값이 더 작으면 패스
			continue;
		}
		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i].second;
			// nextCost는 확인한 경로값에 cost를 더한 값
			int nextCost = graph[idx][i].first + cost;

			if (dist[next] > nextCost) {    // 업데이트 할때마다 route[]도 업데이트
				dist[next] = nextCost;
				route[next] = idx;
				que.push({ -nextCost,next });
			}
		}
	}

	printf("%d\n", dist[end]);    // 최소 비용 출력
    
	vector<int> route_v; // 백트래킹
	int tmp = end;
    
	while (tmp) {
		route_v.push_back(tmp);
		tmp = route[tmp];
	}
    
	printf("%ld\n", route_v.size());    // 최소 비용 갖는 경로에 포함된 도시의 개수 출력
    
	for (int i = route_v.size() - 1; i >= 0; i--) {    // 역순으로 저장되어있으므로 역순 범위 설정
		printf("%d ", route_v[i]);    // 최소 비용 갖는 경로를 방문한 도시 순서대로 출력
	}

	return;
}

int main()
{
    int start_city;    // 출발 도시 번호
    int target_city;   // 도착지 도시 번호
    int bus_cost = 0;      // 출발 도시 ~ 도착지 도시 비용
    int start = 0, end = 0;    // 구하고자 하는 출발점의 도시, 도착점의 도시
    
    scanf("%d", &city_num);    // 도시의 수 입력
    scanf("%d", &bus_num);     // 버스의 수 입력
    
    for (int i = 0; i < bus_num; i++){
        scanf("%d %d %d", &start_city, &target_city, &bus_cost);    // 출발, 도착 도시 번호, 비용 입력
        graph[start_city].push_back({ bus_cost, target_city });
    }
    
    scanf("%d %d", &start, &end);    // 구하고자 하는 출발, 도착 도시 입력
    dijkstra(start, end);
    
    return 0;   
}
