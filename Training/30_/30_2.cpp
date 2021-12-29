#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>

#define ARRAY_SIZE_MAX 10001

using namespace std;

int parent[ARRAY_SIZE_MAX];
long long result;	// 결과값
bool check;
vector<tuple<int, int, int>> graph;

int findParent(int node)    // 노드의 부모를 찾는 함수
{
	if (parent[node] == node) {    // 자기자신이 부모일 경우       
		return node;
    }
    
	else { 			// 부모 노드 찾기
		return parent[node] = findParent(parent[node]);
    }
}

void union_func(int node1, int node2)    // 노드1, 2를합쳐주는 함수
{
	check = false;

	node1 = findParent(node1);     // 노드1의 부모를 찾고,
	node2 = findParent(node2);     // 노드2

	if (node1 == node2) 		// 부모가 같다면 결합하면 사이클 이므로 연결x
		return; 
    
	else {
		parent[node1] = node2; // 결합 & 부모노드로 기록
		check = true;
	}
}

int main()
{
    int spot_num;    // 정점의 개수                                                                                                   
    int line_num;    // 간선의 수 
    int input1, input2;    // 정점
    int weight;    // 가중치
    
    scanf("%d %d", &spot_num, &line_num);    // 정점의 개수, 간선의 수 입력
    
	for (int i = 1; i <= spot_num; i++){    // 일단 처음엔 부모노드에 자기자신 저장
		parent[i] = i;    
	}
    
    for (int i = 0; i < line_num; i++){    // 그래프 정보 저장
        scanf("%d %d %d", &input1, &input2, &weight);    // 정점, 가중치 입력
        graph.push_back(make_tuple(weight, input1, input2));
    }
    
    sort(graph.begin(), graph.end());    // 가중치 오름차순으로 정렬
    
	for (int i = 0; i < line_num; i++){    // 간선들의 결합 탐색 (MST)
		/*
		get<0>(graph[i] : 가중치
		get<1>(graph[i] : 출발 노드
		get<2>(graph[i] : 도착 노드
		*/
		union_func(get<1>(graph[i]), get<2>(graph[i]));

		if (check == 1){
            result += get<0>(graph[i]); // 가중치 더하기
        }
	}        
    
    printf("%lld\n", result);    // 출력
    
    return 0;
    
}
