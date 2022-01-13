#include <stdio.h>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair <ll, ll>;

#define ARRAY_SIZE_MAX 100001
#define SIZE_MAX 18    // log 100000 = 16.6 대략 18로 잡음

vector <pll> adj[ARRAY_SIZE_MAX];
ll parent[SIZE_MAX][ARRAY_SIZE_MAX], depth[ARRAY_SIZE_MAX], cost[ARRAY_SIZE_MAX];

void dfs(ll cur, ll prv) 
{
    parent[0][cur] = prv;
    depth[cur] = depth[prv] + 1;
    
    for (auto nxt : adj[cur]) {
        if (prv != nxt.first) {
            cost[nxt.first] = cost[cur] + nxt.second;
            dfs(nxt.first, cur);
        }
    }
}

ll lca(ll a, ll b) 
{
    if (depth[a] > depth[b]) {    // 깊이가 다르다면 a가 항상 더 깊게
        swap(a, b);
    }
    
    for (ll i = SIZE_MAX - 1; i >= 0; i--) {
        if (depth[b] - depth[a] >= (1LL << i)) {
            b = parent[i][b];
        }
    }

    if (a == b) {
        return a;
    }

    for (ll i = SIZE_MAX - 1; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main() 
{
    ll node_num;    // 정점 개수
    scanf("%lld", &node_num);    // 정점 개수 입력
    
    for (ll i = 0; i < node_num - 1; i++) {
        ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);    // 정점 a, b, 비용 c
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1, 0);    // 1번 정점부터 시작
    
    for (ll k = 1; k <= SIZE_MAX - 1; k++) {
        for (ll i = 1; i <= node_num; i++) {
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
        }
    }

    ll querry_num;    // 쿼리 개수 
    
    scanf("%lld", &querry_num);    // 쿼리 개수 입력
    
    while (querry_num--) {
        ll a;    // 1 u v : 일때 
        scanf("%lld", &a);
        
        if (a == 1) {    
            ll u, v;    // 쿼리 쌍 정점 번호 
            scanf("%lld %lld", &u, &v);    // 정점 u, v 입력
            printf("%lld\n", cost[u] + cost[v] - 2 * cost[lca(u, v)]);
            // (루트부터 각 정점 u, v 까지 거리) - (u, v의 최소 공통 분모노드 까지 비용 * 2)
        } 
        
        else {    // 2 u v k 일때
            ll u, v, k; scanf("%lld %lld %lld", &u, &v, &k);    // k : k 번째 정점번호
            ll l = lca(u, v);
            
            if (depth[u] - depth[l] + 1 < k) { 
                k = depth[u] + depth[v] - 2 * depth[l] - k + 1;    // 공통 분모 노드 까지 정점 개수
                
                for (ll i = 17; i >= 0; i--) {
                    if (k >= (1LL << i)) {
                        k -= (1LL << i);
                        v = parent[i][v];
                    }
                }
                printf("%lld\n", v);    // 출력
                
            } 
            
            else {
                k--;    // 최소 공통 분모 노드에서 아래로 내려가면서 카운트 해야할 정점의 수
                for (ll i = SIZE_MAX - 1; i >= 0; i--) {
                    if (k >= (1LL << i)) {
                        k -= (1LL << i);
                        u = parent[i][u];
                    }
                }
                printf("%lld\n", u);    // 출력
            }
        }
    }
    
    return 0;
}
