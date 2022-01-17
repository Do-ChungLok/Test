#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

#define ARRAY_SIZE_MAX 10004

using namespace std;
 
int lamp_num, game_num, a, b, c, cnt;
char f_a, f_b, f_c;    // 그래프의 인접 리스트 
vector <vector <int>> adj(ARRAY_SIZE_MAX);
vector <int> sccID;    // 각 정점의 컴포넌트 번호
vector <int> discovered;    // 각 정점의 발견 순서
stack <int> st;    // 정점의 번호를 담는 스택

int sccCounter, vertexCounter;
// now 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을
// 통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
// (이미 SCC로 묶인 정점으로 연결된 교차 간선은 무시한다.)
int scc(int now) 
{
    // 이 코드에서 now, next는 u,v 즉 연결된 정점이라고 생각하면 편하다
    int ret = discovered[now] = vertexCounter++;
    // 스택에서 now 넣는다. now 후손들은 모두 스택에서 now 후에 들어간다.
    st.push(now);
    for (int i = 0; i < adj[now].size(); ++i) {
        int next = adj[now][i];
        
        if (discovered[next] == -1) {
            ret = min(ret, scc(next)); // 아직 방문하지 않았다면
        }
        else if (sccID[next] == -1) { // next는 무시해야 하는 교차 간선이 아니라면 
            ret = min(ret, discovered[next]);
        }
 
    }
    if (ret == discovered[now]) {    // now 부모로 올라가는 간선을 끊어야 할지 확인
        while (1) {
            int t = st.top();
            st.pop();
            sccID[t] = sccCounter; // sccID의 각 index에는 각 정점이 몇 번째 컴포넌트인지 
            cnt = sccCounter;
            if (t == now) {
                break;
            }
        }
        ++sccCounter;
    }
    return ret;
}
 
vector <int> tarjanSCC()    // tarjan의 SCC알고리즘 
{
    sccID = discovered = vector <int>(adj.size(), -1);    // 배열들 전부 초기화    
    sccCounter = vertexCounter = 0;    // 카운터 초기화
    for (int i = 1; i <= 2 * lamp_num; i++) {    // 모든 정점에 대해 scc() 호출
        if (discovered[i] == -1) {
            scc(i);
        }
    }
    
    return sccID;
}
 
int main() 
{
    scanf("%d %d", &lamp_num, &game_num);    // 램프 수, 게임 수 입력

    for (int i = 0; i < game_num; i++) {
        scanf("%d %c %d %c %d %c", &a, &f_a, &b, &f_b, &c, &f_c);    // 데이터 입력
        a = f_a == 'R' ? a : -a;
        b = f_b == 'R' ? b : -b;
        c = f_c == 'R' ? c : -c;
        // a u b 라면 ~a -> b 와 ~b -> a 이 두 간선을 추가해야 함
        adj[a > 0 ? lamp_num + abs(a) : abs(a)].push_back(b > 0 ? b : lamp_num + abs(b));
        adj[b > 0 ? lamp_num + abs(b) : abs(b)].push_back(a > 0 ? a : lamp_num + abs(a));
        adj[c > 0 ? lamp_num + abs(c) : abs(c)].push_back(b > 0 ? b : lamp_num + abs(b));
        adj[b > 0 ? lamp_num + abs(b) : abs(b)].push_back(c > 0 ? c : lamp_num + abs(c));
        adj[a > 0 ? lamp_num + abs(a) : abs(a)].push_back(c > 0 ? c : lamp_num + abs(c));
        adj[c > 0 ? lamp_num + abs(c) : abs(c)].push_back(a > 0 ? a : lamp_num + abs(a));
    }

    vector <int> temp = tarjanSCC();    // tarjan 알고리즘으로 구했기 때문에 위상정렬의 역순 상태
 
    // x와 ~x가 한 scc안에 있는지 없는지 판단 -> 없다면 SAT
    // 간단한 정리 : p -> q라는 명제에서 p가 거짓이면 q는 참이든 거짓이든 상관없음.
    // but p가 참이면 q도 반드시 참이어야 함!
    // 그렇다면 한 scc안에 하나라도 true라면 전부 true여야 함. 
    // -> 이 때 x와 ~x가 같은 scc안에 있다면 위의 조건 불만족
    // 즉, 한 scc안에 자신과 반대되는 명제가 없다면 SAT
 
    int stop = 0;
    for (int i = 1; i <= lamp_num; i++) {
        if (temp[i] == temp[lamp_num + i]) {
            stop = 1;
            break;
        }
    }
    if (stop == 1) {    // 불가능한 경우
        printf("-1\n");    // '-1' 출력
        return 0;
    }
 
    vector <pair <int, int>> correct_scc;    // 위상정렬 된 상태의 벡터
    for (int i = 1; i <= 2 * lamp_num; i++) {
        correct_scc.push_back(make_pair(temp[i], i));
    }
    
    sort(correct_scc.begin(), correct_scc.end(), greater <pair <int, int>>()); // 오름차순 정렬
 
    vector <int> ans(2 * lamp_num + 1, -1);
    
    for (int i = 0; i < correct_scc.size(); i++) {
        int x = correct_scc[i].second;
        if (ans[x] == -1) { // 방문하지 않은 경우 : 자신은 false, 역은 true
            ans[x] = 0;
            ans[x <= lamp_num ? lamp_num + x : x - lamp_num] = 1;
        }
    }
    for (int i = 1; i <= lamp_num; i++) {
        if (ans[i] == 0) {  // 파란색인 경우
            printf("B");    // 'B 출력
        }
        
        else {              // 빨간색인 경우
            printf("R");    // 'R' 출력
        }
    }
    printf("\n");
 
    return 0;
}

