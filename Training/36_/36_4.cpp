#include <vector>
#include <stdio.h>
#include <string.h>

#define TREE_HIGHT 20    // 2 ^ 20 > 100,000
#define NUM_SIZE_MAX 100000

using namespace std;

int city_num;    // 도시의 수 
int depth[NUM_SIZE_MAX];
int parent[NUM_SIZE_MAX + 1][TREE_HIGHT];
int min_road[NUM_SIZE_MAX + 1][TREE_HIGHT];
int max_road[NUM_SIZE_MAX + 1][TREE_HIGHT];
vector <pair <int, int>> adj[NUM_SIZE_MAX + 1];

void FindParent(int par, int now, int dep, int road_len)
{
    depth[now] = dep;    // 초기값
    parent[now][0] = par;    // 초기값
    min_road[now][0] = max_road[now][0] = road_len;    // 초기값

    for(int i = 0; i < adj[now].size() ; i++) {
        if (adj[now][i].first != par) {
            FindParent(now, adj[now][i].first, dep+1,adj[now][i].second);
        }
    }
    
    return;
}

pair<int,int> FindMinMaxRoad(int a, int b)
{
    int min_result = 1000001, max_result = 0;

    if (depth[a] != depth[b]) {
        if (depth[a] < depth[b]) // 깊이가 다르다면 a가 항상 더 깊게
          swap(a,b);
    
        int dif = depth[a] - depth[b];
    
        for (int i = 0; dif > 0 ; i++){
            if (dif % 2 == 1) {
                min_result = min(min_result, min_road[a][i]);
                max_result = max(max_result, max_road[a][i]);
                a = parent[a][i];
            }
        
        dif = dif>>1;
        }
    }

    if (a != b) {
        for (int k = TREE_HIGHT - 1; k >= 0 ; k--){
            if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
                min_result = min(min_result, min_road[a][k]);
                min_result = min(min_result, min_road[b][k]);

                max_result = max(max_result, max_road[a][k]);
                max_result = max(max_result, max_road[b][k]);
          
                a = parent[a][k];
                b = parent[b][k];
            }
        }

    min_result = min(min_result, min_road[a][0]);
    min_result = min(min_result, min_road[b][0]);
    
    max_result = max(max_result, max_road[a][0]);
    max_result = max(max_result, max_road[b][0]);
    }
  
    return make_pair(min_result, max_result);
}

int main()
{
    scanf("%d", &city_num);    // 도시의 수 입력

    int a, b, road;    // 도시 a, b, a-b 거리
    
    for (int i = 0; i < city_num - 1 ; i++) {
        scanf("%d %d %d",&a, &b, &road);    // 도시 a, b, a-b 거리 입력
      
        adj[a].push_back(make_pair(b, road));
        adj[b].push_back(make_pair(a, road));
    }

    memset(parent, 0 , sizeof(parent));
    memset(min_road, 1000001, sizeof(min_road));
    memset(max_road, 0, sizeof(max_road));

    FindParent(0, 1, 0, 0);    // 함수 호출, 초기값 설정

    for (int k = 1; k < TREE_HIGHT ; k++) {
        for (int idx = 2 ; idx <= city_num ; idx++) {
            if (parent[idx][k-1] != 0) {
                parent[idx][k] = parent[parent[idx][k-1]][k-1];
                min_road[idx][k] = min(min_road[parent[idx][k-1]][k-1], min_road[idx][k-1]);
                max_road[idx][k] = max(max_road[parent[idx][k-1]][k-1], max_road[idx][k-1]);
            }
        }
    }
    
    int pair_num;    // 쌍의 수
    pair <int,int> result;    // 결과값
    
    scanf("%d", &pair_num);    // 쌍의 수 입력

    while (pair_num--) {
        scanf("%d %d", &a, &b);    // 구하고자 하는 도시 a, b 
      
        result =FindMinMaxRoad(a, b);
        printf("%d %d\n", result.first, result.second);    // 출력
    }

    return 0;
}
