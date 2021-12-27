#include <stdio.h>
#include <algorithm>
#include <vector>
#define ARRAY_SIZE_MAX 501
using namespace std;

int spot_num;    // 정점 수
int line_num;    // 간선 수
int input1, input2;    // 입력
int result, cnt;    // 트리 수, 케이스 수 카운트
bool visited[ARRAY_SIZE_MAX];    // 방문여부

vector <int> graph[ARRAY_SIZE_MAX];

bool dfs(int num, int post_num)
{
    visited[num] = true;    
    
    for (int i = 0; i < graph[num].size(); i++){
        if (graph[num][i] == post_num){
            continue;
        }
        
        if (visited[graph[num][i]] == 1){    // cycle이 생기면
            return false;
        }
        
        if (dfs(graph[num][i], num) == false){
            return false;
        }
    }
    
    return true;
}


int main()
{
    while(1){
        scanf("%d %d", &spot_num, &line_num);    // 정점, 간선의 개수 입력
        if (spot_num == 0 && line_num == 0){     // 정점, 간선의 개수가 0, 0 일때 탈출
            break;
        }
        
        cnt++;    // 케이스 수 카운트
        result = 0;    // 트리 수 초기화
        
        for (int i = 1; i < ARRAY_SIZE_MAX; i++){
            graph[i].clear();    // 벡터 초기화
            visited[i] = false;
        }
        for (int i = 0; i < line_num; i++){
            scanf("%d %d", &input1, &input2);    // 간선 정수 입력
            graph[input1].push_back(input2);    // 벡터에 넣기
            graph[input2].push_back(input1);    // 벡터에 넣기
        }        
        
        for (int i = 1; i <= spot_num; i++){
            if (!visited[i]){    // 방문하지 않았고
                if (dfs(i, 0)){    // 트리가 만들어졌다면
                    result++;    // 트리수 ++
                }
            }
        }
        
        printf("Case %d: ", cnt);
        if (result > 1){    // 트리 수가 다수인 경우
            printf("A forest of %d trees.\n", result);
        }
        
        else if (result == 1){ // 트리 수가 1인 경우
            printf("There is one tree.\n");
        }
        
        else if (result == 0){    // 트리 수가 0인 경우
            printf("No trees.\n");
        }
    }
}
