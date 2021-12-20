#include <stdio.h>
#include <queue>
#include <vector>
#include <climits>

#define ARRAY_SIZE_MAX 801

using namespace std;

int spot_num;    // 정점의 개수
int line_num;    // 간선의 개수
int num1, num2, dist_num12;    // 입력하는 정점1, 2, 정점1, 2와의 거리

vector< pair<int ,int> > vec[ARRAY_SIZE_MAX];
priority_queue < pair<int, int> > pq;
bool visited[ARRAY_SIZE_MAX];
int dist[ARRAY_SIZE_MAX];
int INF = INT_MAX;

int dijkstra(int start, int end)
{
    vector<int> dist(spot_num + 1, INF);
    
    pq.push({0, start});      // 시작점 먼저 대입
    dist[start] = 0;          // 자신과의 거리는 '0'
    
    while(!pq.empty()){
        pair<int ,int> t = pq.top(); 
        pq.pop();
        
        int cur = t.second; 
        int d = t.first * -1;
        
        if(dist[cur] < d)     // 만일 이번 코스트가 최단경로가 아니라면 패스
            continue;
        
        for(int i = 0; i < vec[cur].size(); i++){
            int next = vec[cur][i].first;    
            int next_dist = vec[cur][i].second + d;
            
            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next_dist * -1, next});
            }
        }
    }
    
    return dist[end];
}

int main()
{
    scanf("%d %d", &spot_num, &line_num);    // 정점의 개수, 간선의 개수 입력
      
    for (int i = 0; i < line_num; i++){    
        scanf("%d %d %d", &num1, &num2, &dist_num12);        // 정점1, 2, 정점간의 거리 입력
        vec[num1].push_back({num2, dist_num12});
        vec[num2].push_back({num1, dist_num12});
    }
    
    int v1, v2;    // 반드시 거쳐야하는 정점 v1, v2
    scanf("%d %d", &v1, &v2);    // 반드시 거쳐야하는 v1, v2 입력
    
    int start_to_v1 = dijkstra(1, v1);    // 1에서 v1까지 최단거리
    int start_to_v2 = dijkstra(1, v2);    // 1에서 v2까지 최단거리
    
    int v1_to_v2 = dijkstra(v1, v2);      // v1에서 v2까지 최단거리 (== v2에서 v1까지 최단거리)
    int v1_to_spot_num = dijkstra(v1, spot_num);    // v1에서 마지막 정점까지 최단거리
    
    int v2_to_spot_num = dijkstra(v2, spot_num);    // v2에서 마지막 정점까지 최단거리
    
    int result1 = INF;
    int result2 = INF;
    int result = 0;
    
    result1 = start_to_v1 + v1_to_v2 + v2_to_spot_num;    // 1 -> v1 -> v2 -> 마지막 정점까지 최단거리
    result2 = start_to_v2 + v1_to_v2 + v1_to_spot_num;    // 1 -> v2 -> v1 -> 마지막 정점까지 최단거리
                                                          // v2_to_v1 == v1_to_v2 와 같다
    
    result = min(result1, result2);   
    
    if (result >= INF || v1_to_v2 == INF){    // 출력
        printf("-1");
    }
    else{
        printf("%d", result);
    }
    
    return 0;
  
}
