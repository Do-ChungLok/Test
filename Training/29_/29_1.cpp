#include <stdio.h>
#include <vector>
#define ARRAY_SIZE_MAX 1000001
using namespace std;

int input_num, calculation_num;    // 집합 원소 개수, 연산 개수

int parent[ARRAY_SIZE_MAX];    // 부모역할을 하는 배열

int findParent(int node) 
{
	if (parent[node] == node){	// 자기자신이 부모노드라면 노드 반환
		return node;
    }
    
	else {
		return parent[node] = findParent(parent[node]);       	// 노드를 부모노드로 바꿈 
    }
}

void union_func(int node1, int node2) 	// find 연산으로 각각의 루트를 찾아줌
{
	node1 = findParent(node1);
	node2 = findParent(node2);
	parent[node2] = node1;    // ex) node1 = 3, node2 = 7 -> node1 = 3, node2 = 7 -> parent[7] = 3
}

int main() 
{
	scanf("%d %d", &input_num, &calculation_num);    // 원소 개수, 연산 개수 입력

    for (int i = 0; i <= input_num; i++) {
		parent[i] = i;    // 일단 처음엔 부모노드에 자기자신 저장
    }
    
	for(int i = 0; i < calculation_num; i++){
        int cmd, input1, input2;
		scanf("%d %d %d", &cmd, &input1, &input2);    // cmd, input1, 2 입력
       
		if (cmd == 0) {    // 처음에 0으로 시작
			union_func(input1, input2);    // union 함수 호출
		}
        
		else if (cmd == 1) {    // 처음에 1로 시작
			if (findParent(input1) == findParent(input2)) {    // findParent 함수 호출
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
    }
  
	return 0;
}
