#include <stdio.h>
#include <vector>
#include <queue> 

using namespace std;
int team_num;    // 팀의 수
int pair_num;    // 등수가 바뀐 쌍의 수 
vector <vector<bool>> adj;
vector <int> ranking; 
vector <int> in_degree; 

void topological_sort()    // 위상정렬 알고리즘
{ 
    vector<int> result; 
        queue<int> q; 
    for (int i = 1; i <= team_num; i++) { 
        if (in_degree[i] == 0)    // 들어오는 간선의 수가 '0'인 정점인 경우 큐에 push
            q.push(i); 
    }
    
    bool is_cycle = false;
    bool is_certain = true; // 위상 정렬을 정점의 개수만큼 반복 
    for (int i = 0; i < team_num; i++) { 
        if (q.empty()) {    // 큐가 비었다면 사이클
            is_cycle = true; 
            break; 
        } 
        
        else if (q.size() >= 2) {    // 두 정점 이상 큐에 들어갔다는 것은 순서가 불확실하다는 의미 
            is_certain = false; 
            break; 
        } 
        
        int cur = q.front();
        q.pop(); 
        result.push_back(cur); 
        
        for (int j = 1; j <= team_num; j++) { 
            if (adj[cur][j]) { 
                in_degree[j]--; 
                
                if (in_degree[j] == 0)
                    q.push(j); 
            } 
        } 
    } 
    
    if (is_cycle) 
        printf("IMPOSSIBLE\n");
    
    else if (!is_certain) 
        printf("?\n");
    
    else {
        for (int i = 0; i < team_num; i++) 
            printf("%d ", result[i]);
        printf("\n"); 
    } 
} 

int main() 
{

    int case_num;
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    while (case_num--) { 
        scanf("%d", &team_num);    // 팀의 수 입력
        ranking = vector <int>(team_num + 1);
        in_degree = vector <int>(team_num + 1, 0);
        adj = vector <vector<bool>>(team_num + 1, vector<bool>(team_num + 1, false)); 
        
        for (int i = 1; i <= team_num; i++)   
            scanf("%d", &ranking[i]);    // 순위 입력
        
        for (int i = 1; i < team_num; i++) 
            for (int j = i + 1; j <= team_num; j++) { 
                adj[ranking[i]][ranking[j]] = true;    // 순위 기준 인접 배열 만듬
                in_degree[ranking[j]]++; 
            } 
        
        scanf("%d", &pair_num);    // 등수 바뀐 쌍의 수 입력
        
        for (int i = 0; i < pair_num; i++) {
            int a, b; 
            scanf("%d %d", &a, &b);    // 쌍 입력
            
            if (adj[a][b]) {    // 원래 a > b (a가 b보다 앞이었던 경우)
                adj[a][b] = false;
                adj[b][a] = true;
                in_degree[a]++; in_degree[b]--;
            
            } 
            
            else {    // 원래 b > a (b가 a보다 앞이었던 경우)
                adj[a][b] = true; 
                adj[b][a] = false; 
                in_degree[a]--; 
                in_degree[b]++; 
            } 
        } 
        topological_sort();
    } 
    return 0;
}


