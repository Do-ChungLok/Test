#include <stdio.h>
#include <string.h>
#include <vector>

#define ARRAY_SIZE_MAX 100002

using namespace std;
 
int node_num;    // 노드 개수
int visited[ARRAY_SIZE_MAX] = { };
vector< pair<int, int> > node[ARRAY_SIZE_MAX];
 
int diameter = 0; // 지름 길이
int end_point = 0; // 지름에 해당하는 끝점

void dfs(int point, int length)
{
    if(visited[point]){    // 방문했으면 리턴
        return;
    }
    
    visited[point] = 1;
    
    if(diameter < length){    // 거리 업데이트
        diameter = length;
        end_point = point;
    }
    
    for(int i = 0; i < node[point].size(); i++){
        dfs(node[point][i].first, length + node[point][i].second);
    }
}
 
int main()
{

    scanf("%d", &node_num);    // 노드 개수 입력
    int parent, child, length;
    
    for(int i = 0; i < node_num - 1; i++){
        scanf("%d %d %d", &parent, &child, &length);    // 부모, 자식 노드, 길이 입력
        node[parent].push_back(make_pair(child, length));
        node[child].push_back(make_pair(parent, length));
    }
    
    dfs(1,0);     //가장 멀리 있는 정점(end_point) 구하기
 
    diameter = 0;    // 지름 0으로 초기화
    memset(visited, 0, sizeof(visited));    // 배열 데이터 0으로 초기화
    
    dfs(end_point, 0);    //end_point와 가장 멀리 있는 정점과의 거리 구하기
    
    printf("%d\n", diameter);    // 지름 출력

    return 0;
}

