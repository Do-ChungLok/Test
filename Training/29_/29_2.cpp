#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE_MAX 1000001

using namespace std;

int parent[ARRAY_SIZE_MAX];    // 부모역할을 하는 배열

int findParent(int node)
{
    if (parent[node] == node){    // 자기자신이 부모노드라면 노드 반환
        return node;
    }
    
    else{
        return parent[node] = findParent(parent[node]);    // 노드를 부모노드로 바꿈
    }

}

void union_func(int node1, int node2)    // find 연산으로 각각의 루트를 찾아줌
{
    node1 = findParent(node1);
    node2 = findParent(node2);

    if (node1 < node2){
        parent[node2] = node1;
    }

    else {
        parent[node1] = node2;
    }
}

int main()
{
    int city_num;    // 도시의 수
    int city_plan_num;    // 여행계획에 속한 도시의 수
    scanf("%d", &city_num);    // 도시의 수 입력

    for (int i = 0; i < city_num; i++){
        parent[i] = i;    // 일단 처음엔 부모노드에 자기자신 저장
    }

    scanf("%d", &city_plan_num);    // 여행계획에 속한 도시의 수 입력

    int input;
    
    for (int i = 0; i < city_num; i++){    // 인접한 도시를 한 집합으로 합침
        for (int j = 0; j < city_num; j++){
            scanf("%d", &input);    // 도시의 연결 정보 입력

            if (input == 1)
                union_func(i, j);
        }
    }

    // 여행 계획 입력
    int isPossible = 0;
    scanf("%d", &input);
    
    int prevParent = findParent(input - 1);
    for (int i = 1; i < city_plan_num; i++){
        scanf("%d", &input);    // 도시의 여행계획 입력

        if (findParent(input - 1) != prevParent) {
            isPossible = -1;
            break;
        }
    }

    if (isPossible == 0){     // 출력   
        printf("YES");
    }
    
    else {
        printf("NO");    // 출력
    }
    
    return 0;
}
