#include <stdio.h>
#include <vector> 
#include <queue> 
#include <cstring>

#define ARRAY_SIZE_MAX 1001

using namespace std; 

int building_num;    // 건물의 수
int order_num;    // 건설 순서 규칙의 수
int last_building;    // 마지막 건설해야할 건물
int building_time[ARRAY_SIZE_MAX]; // 건설 시간 
int in_degree[ARRAY_SIZE_MAX]; // 선행 정점 개수 
int dp[ARRAY_SIZE_MAX]; // dp[i] = i번 건물을 건설 완료하는데 드는 최소 건설 시간

vector<int> graph[ARRAY_SIZE_MAX]; 

void topological_sort() 
{
    queue<int> q; 
    for (int i = 1; i <= building_num; i++) { 
        if (in_degree[i] == 0) {    // 들어오는 간선의 수가 '0'인 정점인 경우 큐에 push
            dp[i] = building_time[i];     // 초기화 
            q.push(i); 
        } 
    } 
    
    for (int i = 0; i < building_num; i++) { 
        int v = q.front(); 
        q.pop(); 
        
        for (int j = 0; j < graph[v].size(); j++) { 
            int next = graph[v][j];
            in_degree[next]--; 
            
            // 건물을 짓기 위해 걸리는 최소시간 
            // 앞순서 건물들이 모두 건설 완료되어야지만 건설을 시작할 수 있으므로 최댓값 구하기
            // 앞순서 건물 건설시간 + 현재 건물 건설시간 이 최대인 것을 저장해주면 해당 건물을 건설완료 하는데 드는 최소 시간

            dp[next] = max(dp[next], dp[v] + building_time[next]); 
            if (in_degree[next] == 0) {
                q.push(next); 
            } 
        } 
    } 
}

int main() 
{ 
    int case_num; 
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    while (case_num--) { 
        scanf("%d %d", &building_num, &order_num);    // 건물의 수, 건물 순서 규칙 수 입력
     
        memset(dp, 0, sizeof(dp));    // 초기화
        
        for (int i = 0; i < ARRAY_SIZE_MAX; i++) {
            graph[i].clear(); 
        }
        
        for (int i = 1; i <= building_num; i++) { 
            scanf("%d", &building_time[i]);    // 건설 시간
        } 
        
        while (order_num--) {
            int a, b; 
            scanf("%d %d", &a, &b);    // 순서 입력

            graph[a].push_back(b); 
            in_degree[b]++; 
        } 
        
        scanf("%d", &last_building);    // 마지막 건설해야할 건물 입력

        topological_sort(); 
        printf("%d\n", dp[last_building]);    // 출력
    } 
    
    return 0; 
}
