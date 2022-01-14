#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 10001

using namespace std;

vector <int> vec[ARRAY_SIZE_MAX];    // 정방향
vector <int> revrse_vec[ARRAY_SIZE_MAX];    // 역방향
vector <int> scc[ARRAY_SIZE_MAX];    // 결과
vector <pair <int, int>> scc_vec;
int visited[ARRAY_SIZE_MAX];    // 방문여부
stack <int> st;

void dfs(int x)    // 정방향
{
    visited[x] = 1;
    for (auto k : vec[x]) {
        if (visited[k] == 0) 
            dfs(k);
    }
    st.push(x);
}
 
void dfs2(int x, int y)    // 역방향
{
    visited[x]=1;
    scc[y].push_back(x);
    for (auto k : revrse_vec[x]) {
        if (visited[k] == 0) 
            dfs2(k, y);
    }
}
 
int main() 
{
    int spot_num;    // 정점의 개수
    int line_num;    // 간선의 개수  
    int count = 0;   // scc 개수
    scanf("%d %d", &spot_num, &line_num);    // 정점, 간선의 개수 입력
    
    for (int i = 1; i <= line_num; i++) {
        int a, b;    // 정점 데이터
        scanf ("%d %d", &a, &b);    // 정점 입력
        vec[a].push_back(b);
        revrse_vec[b].push_back(a);
    }
    
    for(int i = 1; i <= spot_num; i++) {    // 모든 정점에 대해서
        if (visited[i] == 0)
            dfs(i);
    }
 
    for (int i = 1; i <= spot_num; i++) {     // visited 배열 값'0'으로 초기화
        visited[i] = 0;
    }
 
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (visited[x] == 1)    // 방문 했다면 이미 다른 scc 그룹
            continue;
        dfs2(x, count);
        count++;    // scc의 수++
    }
    
    printf("%d\n", count);    // scc 수 출력
    
    for(int i = 0; i < count; i++) {
        sort(scc[i].begin(), scc[i].end());    // scc 그룹 정렬
        scc_vec.push_back({ scc[i][0], i });    // 첫번째 데이터
    }
    
    sort(scc_vec.begin(), scc_vec.end());    // scc 그룹 첫번째 데이터를 가지고 정렬

    for (auto a : scc_vec) {
        for (auto k : scc[a.second]) {
            printf("%d ", k);    // 출력
        }
        printf("-1\n");
    }
    
    return 0;
}

