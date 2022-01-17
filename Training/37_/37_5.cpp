#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

#define ARRAY_SIZE_MAX 20005

using namespace std;

vector <vector<int>> vec;
vector <vector<int>> rev_vec;
vector <int> scc;
stack <int> st;	// 정점의 번호를 담는 스택
bool visited[ARRAY_SIZE_MAX];

void dfs(int now) 
{
    visited[now] = true;
    for (int next : vec[now]) {
        if (visited[next] == 0) {    // 방문하지 않은 경우
            dfs(next);
        }
    }
    st.push(now);
}

void rev_dfs(int now, int y)
{
    visited[now] = true;
    scc[now] = y;
    for (int next : rev_vec[now]) {
        if (visited[next] == 0) {    // 방문하지 않은 경우
            rev_dfs(next, y);
        }
    }
}

int re(int now, int variable_num) 
{
    return now > variable_num ? now - variable_num : now + variable_num;
}

int main()
{

    int variable_num;  // 변수 개수
    int clause_num;    // 절의 개수
    scanf("%d %d", &variable_num, &clause_num);    // 변수 개수, 절의 개수 입력

    vec.resize(2 * variable_num + 5);
    rev_vec.resize(2 * variable_num + 5);
    scc.resize(2 * variable_num + 5);
    
    for (int i = 0; i < clause_num; i++) {
        int input1, input2;
        scanf("%d %d", &input1, &input2);    // Xi들 입력
        
        if (input1 < 0) {
            input1 = -input1 + variable_num;
        }
        
        if (input2 < 0) {
            input2 = -input2 + variable_num;
        }
        
        vec[re(input1, variable_num)].push_back(input2);    // 데이터 push
        vec[re(input2, variable_num)].push_back(input1);    // 데이터 push
        rev_vec[input1].push_back(re(input2, variable_num));    // 데이터 push
        rev_vec[input2].push_back(re(input1, variable_num));    // 데이터 push
    }
    
    for (int i = 1; i <= 2 * variable_num + 1; i++) {
        if (visited[i] == 0) {    // 방문하지 않은 경우
            dfs(i);
        }
    }
    
    memset(visited, false, sizeof(visited));	// 초기화
    int idx = 1;
    
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        
        if (visited[x] == 0) {    // 방문 했는 경우
            rev_dfs(x, idx++);
        }
    }
    
    for (int i = 1; i <= variable_num; i++) {
        if (scc[i] == scc[i + variable_num]) {
            printf("0\n");    // true로 만들 수 없는 경우 '0' 출력
            return 0;
        }
    }
    printf("1\n");    // true로 만들 수 있는 경우 '1' 출력
    
    return 0;
}
