#include <string.h>
#include <algorithm>
#include <stdio.h>

#define INF 987654321
#define ARRAY_SIZE_MAX 16

using namespace std;

int city_num;    // 도시의 수
int cost[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];        // i -> j 가는 비용
int dp_cost[ARRAY_SIZE_MAX][1 << ARRAY_SIZE_MAX];   // i -> j 가는 최소비용
int visited;    // 방문

int dfs(int now_node, int visited_bit){   //now_node : 현재 위치 , visited_bit : 현재 위치를 포함해서 방문했던 곳들 비트로 표현
    
    if(visited_bit == visited) {             // 모두 방문했을 경우
        if (cost[now_node][0] == 0) {    // 현재 위치에서 첫 시작 노드(0번)로 돌아갈 수 없다면
            return INF; 
        }
        
        else {
            return cost[now_node][0];    // 다 돌고 첫 시작노드로 돌아갈 수 있다면
        }
    }
    
    if (dp_cost[now_node][visited_bit] != -1 ) {    // -1이 아니라면 최소값(dp_cost[][])으로 리턴
        return dp_cost[now_node][visited_bit];
    }
    
    // -1이라면
    dp_cost[now_node][visited_bit] = INF;    // 초기화
    for(int i = 0; i < city_num; i++){
        
        if (cost[now_node][i] == 0) {    // 연결 안 되어 있어서 길이 없는 경우
            continue;   
        }
        
        if ((visited_bit) & (1 << i)) {    // 이미 방문한 경우
            continue;  
        }
        
        // dfs(i, visited_bit | 1 << i) : 현재 노드에서 다음 노드 방문.
        dp_cost[now_node][visited_bit] = min( dp_cost[now_node][visited_bit],
                    dfs(i, visited_bit | 1 << i) + cost[now_node][i] );
    }
    return dp_cost[now_node][visited_bit];
}

int main()
{    
    scanf("%d", &city_num);    // 도시 수 입력
    
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            scanf("%d", &cost[i][j]);    // 데이터 입력    
        }
    }
    
    visited = (1 << city_num) - 1;       //N개 노드 모두 다 방문한 경우
    memset(dp_cost, -1, sizeof(dp_cost));    // '-1'로 초기화
    
    int result = dfs(0,1); // 0 : 0번 노드가 첫 시작노드 / 1 : 1은 2^0 -> 즉 시작 노드인 0번 노드를 방문했음을 표시)
    // 어떤 도시에서 출발하던 비용은 같으므로 0번 노드를 첫 시작노드로 임의 설정.
    
    printf("%d", result);    // 결과 출력
    
    return 0;
}
