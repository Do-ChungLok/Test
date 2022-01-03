#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int spot_num;    // 정점의 수
 
int dp[ARRAY_SIZE_MAX][2];
int visited[ARRAY_SIZE_MAX];
 
vector<vector<int> > lines; // 노드 연결된 간선 정보  
vector<int> weights; // 노드의 가중치  
vector<int> nodes; // 노드에 간선이 몇 개 연결되어 있는지. 간선이 1개 있는 노드에서 DP 시작하기 위해서  
vector<int> set; // 최대 독립 집합에 속한 노드들 저장  
 
 
// 최대 독립집합의 크기 구하기  
// case0 : 현재 정점 포함 X
// case1 : 현재 정점 포함
// dp[now_node][case0] += max(dp[next_node][0], dp[next_node][1]);
// dp[now_node][case1] += dp[next_node][0];

void dfs(int now_node)
{
    visited[now_node] = 1;
    dp[now_node][0] = 0;
    dp[now_node][1] = weights[now_node];
    
    for(int i = 0; i < lines[now_node].size(); i++){
        int next_node = lines[now_node][i];
        
        if(visited[next_node]) {
            continue;
        }
        
        dfs(next_node);
        
        dp[now_node][0] += max(dp[next_node][0], dp[next_node][1]);
        dp[now_node][1] += dp[next_node][0];
    }
}
 
 
// 최대 독립 집합에 속한 노드들 구하기  
void track(int node, bool check)
{
    visited[node] = 1;
    
    // 현재 노드가 속하면, 배열에 넣어준다. 
    if (check){
        set.push_back(node);
        
        for (int i = 0; i < lines[node].size(); i++){
            int next_node = lines[node][i];
            
            if(visited[next_node == 1]){ 
                continue;
            }
            
            track(next_node, false);
        }
    }

    else {    // 현재 노드가 속하면, 다음 노드를 선택 or 선택x
        for (int i = 0; i < lines[node].size(); i++){
            int next_node = lines[node][i];
            
            if(visited[next_node] == 1){ 
                continue;
            }
            
            // 최대 가중치만 DP에 저장했으므로 값이 큰 쪽으로 따라감
            if (dp[next_node][0] > dp[next_node][1])    // 다음 노드 포함 x
                track(next_node, 0);
            else 
                track(next_node, 1);        // 다음 노드 포함 o
        }
    }
}
 
 
int main(void)
{
    scanf("%d", &spot_num);    // 정점의 수 입력
    
    lines.resize(spot_num + 1);
    weights.resize(spot_num + 1);
    nodes.resize(spot_num + 1);
    
    int weight;  // 가중치
    for (int i = 1; i <= spot_num; i++){
        scanf("%d", &weight);    // 가중치 입력
        weights[i] = weight;
    }
    
    int line1, line2;
    while(cin >> line1 >> line2){
        
        lines[line1].push_back(line2);
        lines[line2].push_back(line1);
        
        nodes[line1]++;
        nodes[line2]++;
    }
    
    // 간선이 1개 있는 노드 찾기  
    int root;
    for (int i = 1; i <= spot_num; i++){
        if(nodes[i] == 1) {
            root = i;
        }
    }
    
    // 최대 독립집합 구하기  
    dfs(root);
    
    printf("%d\n", max(dp[root][1], dp[root][0]));    // 출력
    
    // 최대 독립집합의 노드들 구하기
    memset(visited, 0, sizeof(visited));    // 방문배열 크기 0으로 초기화
    if(dp[root][1] > dp[root][0]) {
        track(root, true);
    }
    
    else {
        track(root, false);
    }
    
    sort(set.begin(), set.end());    // 오름차순 정렬
    
    for (int i = 0; i < set.size(); i++) {
        printf("%d ", set[i]);    // 출력
    }
    
}
