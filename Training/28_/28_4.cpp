#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 26

using namespace std;

struct node{    // node 구조체 선언
	char left;
	char right;
};

vector<node> vec(ARRAY_SIZE_MAX);

void preOrder(char node){    // 전위 순회
	                         // root - left - right 순서로 출력
	if(node == '.') {    // 만약 '.' 이면 리턴
        return;
    }
	
	printf("%c", node);          // 먼저 출력
	preOrder(vec[node].left);    // 왼쪽 노드에 입력한 것을 또 함수 호출
	preOrder(vec[node].right);   // 오른쪽 노드에 입력한 것을 또 함수 호출
}

void inOrder(char node){     // 중위 순회
                             // left - root - right
	if(node == '.') {    // 만약 '.' 이면 리턴
        return;
    }
	    
	inOrder(vec[node].left);     // 왼쪽 노드에 입력한 것을 또 함수 호출
	printf("%c", node);          // 호출
	inOrder(vec[node].right);    // 오른쪽 노드에 입력한 것을 또 함수 호출
}

void postOrder(char node){    // 후위 순회
                              // left - right - root
	if(node == '.') {    // 만약 '.' 이면 리턴
        return;
    }
	
	postOrder(vec[node].left);    // 왼쪽 노드에 입력한 것을 또 함수 호출
	postOrder(vec[node].right);   // 오른쪽 노드에 입력한 것을 또 함수 호출
	printf("%c", node);           // 호출
} 

int main()
{	
	int node_num;    // 노드의 개수
	scanf("%d", &node_num);    // 노드의 개수 입력
	
	char route_node, left_node, right_node;    // 루트, 왼, 오 노드
    
	for(int i = 0; i < node_num; i++){
        scanf(" %c %c %c", &route_node, &left_node, &right_node);    // 루트, 왼, 오 노드 입력	
        
		vec[route_node].left = left_node;
		vec[route_node].right = right_node;
	}
	
	preOrder('A');    // 전위 순회 함수 호출
	printf("\n");
	
	inOrder('A');     // 중위 순회 함수 호출
	printf("\n");
	
	postOrder('A');   // 후위 순회 함수 호출
	
	return 0;
}
