#include <stdio.h>
#include <vector>
#include <queue>
 
#define ARRAY_SIZE_MAX 32002

using namespace std;
 
int problem_num, info_num;
vector <int> graph[ARRAY_SIZE_MAX];
int in_degree[ARRAY_SIZE_MAX];
 
void topological_sort()    // 우선순위큐를 이용한 위상 정렬
{
    priority_queue <int> pq;    // 실시간으로 선택할 수 있는 것 중 가장 작은 데이터 선택을 위해 우선순위큐
    for (int i = 1; i <= problem_num; i++) {
        if (in_degree[i] == 0)    // 들어오는 간선의 수가 '0'인 정점인 경우 큐에 push
            pq.push(-i);    // 우선순위 큐는 내림차순 정렬이라서 '-'
    }
 
    while (!pq.empty()) {
        int node = -pq.top();
        pq.pop();
        
        printf("%d\n", node);

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            in_degree[next_node]--;
            
            if (in_degree[next_node] == 0) {    
            // 현재의 노드에 연결된 에지의 도착지들의 indegree를 
            // 감소시켜서 0이면 우선순위 큐에 push 
                pq.push(-next_node);
            }
        }
    }
}
 
int main()
{
    scanf("%d %d", &problem_num, &info_num);    // 문제의 수, 문제에 대한 정보의 수 입력
    
    for (int i = 0; i < info_num; i++) {
        int num1, num2;    // 두 정수
        scanf("%d %d", &num1, &num2);    // 두 정수의 순서쌍 입력
        
        graph[num1].push_back(num2);
        in_degree[num2]++;
    }
 
    topological_sort();
 
    return 0;
}
