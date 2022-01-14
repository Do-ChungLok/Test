#include <stdio.h>
#include <stack>
#include <vector>
#include <string.h>
 
#define ARRAY_SIZE_MAX 100001

using namespace std;
 
vector <vector <int>> adj;
stack <int> s;
 
bool finish[ARRAY_SIZE_MAX]; // SCC 분리가 완료된 정점 = true
int dfsn[ARRAY_SIZE_MAX]; // 각 노드 dfs 번호
int SCCnum[ARRAY_SIZE_MAX]; // SCC의 인덱스 번호
int in_degree[ARRAY_SIZE_MAX];
int count; // dfs 번호
int SCC_total_num; // SCC 총 개수
 
int dfs(int current)
{
    dfsn[current] = ++count;    // dfsn에는 current 구역의 고유 번호 count 를 저장
                            // 구역 번호는 0 ~ N - 1 이니까 ++count
    s.push(current);    // 스택s 에 cur 구역 번호를 push
 
    int parent = dfsn[current];    
    int len = adj[current].size();
 
    for (int i = 0; i < len; i++) {
        int next = adj[current][i];    // current(현재) 구역에서 갈 수 있는 구역의 번호를 next 라고 선언
 
        if (dfsn[next] == 0)    // next 구역이 한 번도 dfs를 수행하지 않아 부모값이 초기화 되지 않은 경우                        
            parent = min(parent, dfs(next));    // 현재 부모값과 next구역을 dfs해서 얻은 부모값 중 더 작은 값을 parent값으로 갱신
 
        else if (finish[next] == 0)    // next 구역이 dfs를 수행한 적이 있지만, 아직 dfs가 종료되지 않은 경우
            parent = min(parent, dfsn[next]);    // 현재 parent값과 dfsn에 갱신된 부모값중 더 작은 값을 parent로 갱신
    }    
 
    if (parent == dfsn[current]) {    // 만약 dfsn 에 저장된 부모값과 현재 부모값이 같다면 (자기 자신이 부모라면) SCC를 생성
        while (1) {
            int t = s.top();
            s.pop();
            finish[t] = true;
            SCCnum[t] = SCC_total_num;
 
            if (t == current)
                break;
        }
        SCC_total_num++;    // SSC 총 횟수 ++
    }
 
    return parent;
}
 
int main()
{
    int case_num;    // 테스트 케이스 수
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    while (case_num--)
    {
        int area_num, movement_num;    // 구역 수, 움직임 수 
        scanf("%d %d", &area_num, &movement_num);    // 구역 수, 움직임 수 입력
 
        memset(finish, false, sizeof(finish));    // 초기화
        memset(dfsn, 0, sizeof(dfsn));    // 초기화
        memset(SCCnum, 0, sizeof(SCCnum));    // 초기화
        memset(in_degree, 0, sizeof(in_degree));    // 초기화
        
        adj.clear();    // 초기화
        adj.resize(area_num + 1);
        count = 0;
        SCC_total_num = 0;
 
        for (int i = 0; i < movement_num; i++){
            int from, to;
            scanf("%d %d", &from, &to);    // 움직임 정점 입력
            adj[from].push_back(to);
        }
 
        for (int i = 0; i < area_num; i++) {
            if (dfsn[i] == 0) {
                dfs(i);
            }
        }
 
        // 진입 차수(in_degree[]) 구하기
        for (int i = 0; i < area_num; i++) {
            for (int j : adj[i]) {
                if (SCCnum[i] != SCCnum[j]) {
                    in_degree[SCCnum[j]]++;
                }
            }
        }
 
        // 진입 차수가 0인 부분 즉, 시작 부분이 있다면 target과 count_degree를 계산 
        int count_degree = 0;
        int target = 0;
        
        for (int i = 0; i < SCC_total_num; i++) {
            if (in_degree[i] == 0) {
                target = i, count_degree++;
            }
        }
 
        // 진입 차수가 2개 이상이면 Confused
        if (count_degree > 1) {
            printf("Confused\n");
        }
 
        // 진입차수가 1일 때 그 SCC 넘버와 같은 정점을 모두 출력
        else {
            for (int i = 0; i < area_num; i++) {
                if (SCCnum[i] == target) {
                    printf("%d\n", i);
                }
            }
        }
 
        printf("\n");
    }
    return 0;
}


