#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

#define ARRAY_SIZE_MAX 10001
using namespace std;

int town_num;    // 마을의 수
int town1, town2;    // 마을의 번호
int citizen[ARRAY_SIZE_MAX];    // 마을 주민 배열
int dp[ARRAY_SIZE_MAX][2];
bool visit[ARRAY_SIZE_MAX];
vector<int> graph[ARRAY_SIZE_MAX];

void dfs(int now_node) // 현재, 합계, 우수마을여부
{
	visit[now_node] = true;

	dp[now_node][0] = 0;    // 해당 노드가 우수 마을이 아닌 경우
	dp[now_node][1] = citizen[now_node];    // 해당 노드가 우수마을인 경우

	for (int next_node : graph[now_node]) {
		if (!visit[next_node]) {
			dfs(next_node);

			// 현재마을 != 우수마을인 경우 : 다음마을은 우수마을이거나 우수마을이 아님
			dp[now_node][0] += max(dp[next_node][0], dp[next_node][1]);

			// 현재마을 == 우수마을인 경우 : 다음마을은 우수마을이 아님
			dp[now_node][1] += dp[next_node][0];
		}
	}
}

int main()
{

    scanf("%d", &town_num);    // 마을의 수 입력

	for (int i = 1; i <= town_num; i++){
        scanf("%d", &citizen[i]);    // 마을 주민 수 
    }

	for (int i = 1; i <= town_num - 1; i++){
        scanf("%d %d", &town1, &town2);    // 인접한 두 마을의 번호 입력
		graph[town1].push_back(town2);
		graph[town2].push_back(town1);
	}

	dfs(1);    // 초기값 1 대입

    printf("%d", max(dp[1][0], dp[1][1]));    // 출력
    
    return 0;

}
