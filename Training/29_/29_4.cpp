#include <stdio.h>

#define ARRAY_SIZE_MAX 500000

using namespace std;
int spot_num;    // 점의 개수
int turn_num;    // 차례 수      
int parent[ARRAY_SIZE_MAX];    // 부모역할을 하는 배열

int findParent(int node)
{
    if(parent[node] == node) {    // 자기자신이 부모노드라면 노드 반환
        return node;
    }
    
    else {
        return parent[node] = findParent(parent[node]);    // 노드를 부모노드로 바꿈
    }
    
}
bool union_func(int node1, int node2)    // find 연산으로 각각의 루트를 찾아줌
{
    node1 = findParent(node1);
    node2 = findParent(node2);
    
    if(node1 == node2) {    // 부모노드가 같은 경우 1 리턴
        return 1;
    }
    
    else{                   // 부모노드가 다른 경우 0 리턴
        parent[node1] = node2;
        return 0;
    }

}

int main()
{
    scanf("%d %d", &spot_num, &turn_num);    // 점의 개수, 차례 수 입력
    
    for(int i = 0; i < spot_num; i++) {
        parent[i] = i;    // 일단 처음엔 부모노드에 자기자신 저장
    }
    
    for(int i = 1; i <= turn_num; i++){
        int input1, input2;    // 입력 정수들
        
        scanf("%d %d", &input1, &input2);    // 정수 입력
        
        if(union_func(input1, input2)){    // 리턴값이 1이면 싸이클 생성
            printf("%d", i);    // 출력
            
            return 0;
        }
    }
    
    printf("0");
    
    return 0;
}
