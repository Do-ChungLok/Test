#include <stdio.h>
#include <queue>
#include <vector>
#include <climits>


#define ARRAY_SIZE_MAX 20002

using namespace std;

int spot_num;    // 정점의 개수
int line_num;    // 간선의 개수
int start_spot;    // 시작 정점의 번호
int from, to, val;    // 간선을 나타내는 정수, val :  가중치(from ~ to)

vector< pair<int ,int> > vec[ARRAY_SIZE_MAX];
priority_queue < pair<int, int> > pq;
bool visited[ARRAY_SIZE_MAX];
int dist[ARRAY_SIZE_MAX];
int INF = INT_MAX;

void dijkstra_func(int start)
{
    //스타트 지점은 0으로 시작.
    pq.push({0,start});    // 시작점 먼저 대입
    dist[start] = 0;    // 자신과의 거리는 '0'
    
    while(!pq.empty())
    {
        int weight=pq.top().first;    
        int node = pq.top().second;
        pq.pop();
        
        if(visited[node] == true)    //이미 방문했다면 최소일 것이므로 패스 
            continue;
              
        visited[node] = true;      //최소값으로 선택 됐을때 방문했다고 체크

        for(int i = 0; i < vec[node].size(); i++){
            int nn = vec[node][i].first;  // next node의 노드 인덱스
            int nw = vec[node][i].second; // next node의 weight정보(cost)

            //방문하지 않았던 노드이고, 새롭게 오는 거리정보가 기존 거리정보 보다 작으면 
            if(visited[nn] == false && dist[nn] > dist[node] + nw){
                dist[nn] = dist[node] +nw; // 값을 갱신
                pq.push({-(dist[node] +nw),nn});       
            }
        }
    }
}

int main()
{
    scanf("%d %d", &spot_num, &line_num);    // 정점의 개수, 간선의 개수 입력
    scanf("%d", &start_spot);    // 시작 정점의 번호 입력
    
    for (int i = 1; i <=spot_num; i++){    // 간선간의 거리 초기화
        dist[i] = INF;
    }
    
    for (int i = 0; i < line_num; i++){    // 간선 연결
        scanf("%d %d %d", &from, &to, &val);    // 'from' ~-> 'to'로 이어지는 간선에 'val' : 가중치
        vec[from].push_back({to, val});
    }
    
    dijkstra_func(start_spot);    // 다익스트라 함수 호출
    
    for (int j = 1; j <= spot_num; j++){    // 출력
        if (dist[j] == INF){
            printf("INF\n");
        }
        else{
            printf("%d\n", dist[j]);
        }
    }
}
