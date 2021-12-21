#include<iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

#define AIRPORT_SIZE_MAX 101
#define COST_SIZE_MAX 10001

using namespace std;

int min_time[AIRPORT_SIZE_MAX][COST_SIZE_MAX];    // min_time[i][j] : j비용으로 i공항까지 가는 최소 시간

vector< tuple<int, int, int> > graph[AIRPORT_SIZE_MAX];

int INF = INT_MAX;
int case_num;       // 테스트 케이스 수
int airport_num;    // 공항의 수
int all_cost;       // 총 지언 비용
int ticket_num;     // 티켓정보의 수
int start, arrival; // 출발공항, 도착공항
int cost, time;     // 비용, 소요시간
int ans;


void init() // 초기화
{
	for (int i = 1; i <= 100; i++){
		graph[i].clear();

		for (int j = 0; j <= 10000; j++){
			min_time[i][j] = INF;
        }
	}
	ans = INF;
}

void dijkstra()
{
	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > pq;

	min_time[1][0] = 0;
	pq.push({ 0, 1, 0 }); // 누적 시간, 출발지, 누적 비용 

	while ( !pq.empty() ){
		int cumulative_time = get<0>(pq.top()); // 누적 시간
		int current_airport = get<1>(pq.top()); // 현재 공항
		int cumulative_money = get<2>(pq.top()); // 누적 비용
		
		pq.pop();

		if (min_time[current_airport][cumulative_money] < cumulative_time){
            continue;    
        }

		for (int i = 0; i < graph[current_airport].size(); i++){ // i : 목적지
			int next_time = cumulative_time + get<0>(graph[current_airport][i]); // 소요 시간
			int next_airport = get<1>(graph[current_airport][i]); // 다음 공항
			int next_money = cumulative_money + get<2>(graph[current_airport][i]); // 소요 비용
			
			if (next_money > all_cost) {    // 지원 비용으로 갈 수 없을 경우 pass
                continue;
            }

			// 해당 공항에 해당 비용으로 갈때의 최소 시간보다 크다면 pass
			if (min_time[next_airport][next_money] <= next_time){
                continue;
            }

			// 해당 공항에 최소시간으로 가는 비용보다 높은 비용으로 가는 방법들을
			// 최소시간으로 업데이트 (무의미한 계산을 막기 위함)
			for (int j = next_money; j <= all_cost; j++) {
				if (min_time[next_airport][j] > next_time) {
					min_time[next_airport][j] = next_time;
				}
			}
            
			pq.push({ next_time, next_airport, next_money });
		}

	}
}

int main()
{
    scanf("%d", &case_num);
    
    for (int i = 0; i < case_num; i++){
        init();
        
        scanf("%d %d %d", &airport_num, &all_cost, &ticket_num);
        
        for (int j = 0; j < ticket_num; j++){
            scanf("%d %d %d %d", &start, &arrival, &cost, &time);
            graph[start].push_back({ time, arrival, cost });
        }
        
        dijkstra();
        
        for (int i = 1; i <= all_cost; i++){
            ans = min(ans, min_time[airport_num][i]);
        }
        
        if (ans == INF){
            printf("Poor KCM\n");
        }
        
        else{
            printf("%d\n", ans);
        }
    }
}
