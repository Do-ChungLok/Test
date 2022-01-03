#include <stdio.h>
#include <vector>
 
#define ARRAY_SIZE_MAX 1000001
using namespace std;
 
int spot_num;    // 정점의 수
 
int dp[ARRAY_SIZE_MAX][2]; // 최소 얼리어댑터의 개수  
bool visited[ARRAY_SIZE_MAX];    // 방문 여부
vector<int> edges[ARRAY_SIZE_MAX];
 
void dfs(int now_node)
{
    visited[now_node] = 1;    // 1로 초기화
    dp[now_node][0] = 0; // 본인이 얼리어답터가 아니면 개수 0 
    dp[now_node][1] = 1; // 본인이 얼리어답터가 맞으면 개수 1 
    
    for (int i = 0; i < edges[now_node].size(); i++){
        int next_node = edges[now_node][i]; 
        
        if (visited[next_node] == 1) {
            continue; // 아래로 DFS 진행하기 위해서 위로 이동 방지  
        }
        
        dfs(next_node);
        
        dp[now_node][0] += dp[next_node][1]; // 현재 노드가 얼리어답터가 아니라면, 주변 노드는 얼리어답터이어야 한다. 
        dp[now_node][1] += min(dp[next_node][0], dp[next_node][1]); // 현재 노드가 얼리어답터라면, 주변은 얼리 또는 얼리어답터가 아니다. 
    }
}
 
int main(void)
{ 
    scanf("%d", &spot_num);    // 정점 개수 입력

    int edge1, edge2;
    for (int i = 0; i < spot_num - 1; i++){
        scanf("%d %d", &edge1, &edge2);    // 에지를 나타내는 두 정수 입력
        edges[edge1].push_back(edge2);
        edges[edge2].push_back(edge1);
    }
    
    dfs(1);    // 초기값 1 dfs 함수에 대입
    
    printf("%d", min(dp[1][0], dp[1][1]));    // 출력
    
    return 0;
}
