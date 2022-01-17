#include <stdio.h>
#include <vector>
#include <stack>
#include <cstring>

#define ARRAY_SIZE_MAX 2003

using namespace std;

vector <vector<int>> vec, rev_vec;
stack <int> st;	// 정점의 번호를 담는 스택
bool visited[ARRAY_SIZE_MAX];    // 방문 여부
int scc[ARRAY_SIZE_MAX];
int idx;
int join_num, judge_num;    // 참가자의 수, 심사위원의 수

inline int T(int x) 
{ 
    return x << 1; 
}

inline int F(int x)
{ 
    return x << 1 | 1;
}

inline int NOT(int x) 
{ 
    return x ^ 1; 
}

void dfs(int now)    // 정방향
{
    visited[now] = true;
    for (auto next : vec[now]) {
        if (visited[next] == 0) {    // 방문하지 않은 경우
            dfs(next);
        }
    }
    st.push(now);
}

void rev_dfs(int now)    // 역방향
{
    visited[now] = true;
    scc[now] = idx;
    for (auto next : rev_vec[now]) {
        if (visited[next] == 0) {    // 방문하지 않은 경우
            rev_dfs(next);
        }
    }
}

int main() 
{
    while (scanf("%d %d", &join_num, &judge_num) > 0) {
        vec.clear();    // 벡터 초기화
        vec.resize((join_num << 1) + 2);
        rev_vec.clear();     // 벡터 초기화
        rev_vec.resize((join_num << 1) + 2);
        
        while (judge_num--) {
            int a, b; 
            scanf("%d %d", &a, &b);
            a = a > 0 ? T(a) : F(-a);
            b = b > 0 ? T(b) : F(-b);
            
            vec[NOT(a)].push_back(b);    // 데이터 push
            vec[NOT(b)].push_back(a);    // 데이터 push
            rev_vec[b].push_back(NOT(a));    // 데이터 push
            rev_vec[a].push_back(NOT(b));    // 데이터 push            
        }    

        memset(visited, 0, sizeof (visited));    // 크기 '0'으로 초기화    
        
        for (int i = 2; i <= 2 * join_num + 1; i++) {
            if (visited[i] == 0) {    // 방문하지 않은 경우
                dfs(i);
            }
        }

        memset(visited, 0, sizeof (visited));    // 크기 '0'으로 초기화  
        
        idx = 1;
        while (!st.empty()) {
            int now = st.top();
            st.pop();
        
            if (visited[now] == 0) {    // 방문하지 않은 경우
                rev_dfs(now);
                idx++;
            }
        }

        bool flag = false;
        
        for (int i = 1; i <= join_num; i++) {
            if (scc[T(i)] == scc[F(i)]) {
                flag = true;
            }
        }
        
        if (scc[T(1)] > scc[F(1)] && !flag) {
            printf("yes\n");
        }
        
        else {
            printf("no\n");
        }
    }
    
    return 0;
}
