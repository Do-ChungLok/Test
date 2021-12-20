#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <climits>
 
#define ARRAY_SIZE_MAX 2001

using namespace std;
 
int INF = INT_MAX;

vector< pair<int, int> > vec[ARRAY_SIZE_MAX];
vector<int> find_this;
 
int case_num;    // 테스트 케이스 수
int inter_num, road_num, destination_num;    // 교차로 수, 도로의 수, 목적지 수
int start_spot, G, H;    // 출발지점, G, H 지점
int num1, num2, dist_num12;    // 정점1, 2, 1,2와의 거리
 
vector<int> dijkstra(const int& start) 
{

    vector<int> dist(inter_num + 1, INF);     // 각 노드로 이동하는데 필요한 시간을 저장, 처음에는 INF로 초기화
    
    dist[start] = 0;    // 자신과의 거리는 0, (시작지점은 0으로 설정)
 
    priority_queue< pair<int, int> > pq;
    
    pq.push({ 0, start });     // 시작점 먼저 대입
 
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (cost > dist[here]) {    // 만일 이번 코스트가 최단경로가 아니라면 패스
            continue;
        }
                                
        for (int i = 0; i < vec[here].size(); i++) {
            int there = vec[here][i].first;
            int next_cost = cost + vec[here][i].second;
            
            
            if (next_cost < dist[there]) {    // 다음 지점에 대해 최단경로가 갱신되는 경우
                dist[there] = next_cost;
                pq.push({ -next_cost, there });
            }
        }
    }
 
    return dist;
}
 
int main() 
{
    
    cin >> case_num;
    
    for (int i = 0; i < case_num; i++) {
        cin >> inter_num >> road_num >> destination_num;
        cin >> start_spot >> G >> H;
 
        for (int j = 1; j <= inter_num; j++)    //활용되는 범위에 대해 미리 초기화
            vec[j].clear();
      
        for (int j = 0; j < road_num; j++) {
            cin >> num1 >> num2 >> dist_num12;
            vec[num1].push_back({ num2, dist_num12 });
            vec[num2].push_back({ num1, dist_num12 });
        }
 
        int temp;
        find_this.clear();     // 항상 초기화 해줌
        
        for (int j = 0; j < destination_num; j++) {
            cin >> temp;
            find_this.push_back(temp);
        }
  
        sort(find_this.begin(), find_this.end());    // 오름차순으로 정렬
 
        vector<int> root = dijkstra(start_spot);
        vector<int> branch1 = dijkstra(G);
        vector<int> branch2 = dijkstra(H);
 
        vector<int> ret;
        for (int j = 1; j <= inter_num; j++) {
            // 시작지점에서 j번 도시까지 걸린 cost가
            // H, G점을 경유해서 돌아간 cost와 동일한 경우
            // ret에 담아 저장해준다.
            if (root[j] == root[G] + branch1[H] + branch2[j] 
                || root[j] == root[H] + branch2[G] + branch1[j]) {
                ret.push_back(j);
            }
        }
 
        //우리가 찾기 위해 등록한 노드가 최단 노드(ret에 담겨있는 노드)중 하나인 경우
        for (int j = 0; j < find_this.size(); j++) {
            int here = find_this[j];
            
            for (int k = 0; k < ret.size(); k++) {
                if (here == ret[k])
                    cout << here << " ";
            }
        }
        cout << endl;
    }
 
    return 0;
}

