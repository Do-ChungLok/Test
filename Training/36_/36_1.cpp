#include <stdio.h>
#define ARRAY_SIZE_MAX 10001

using namespace std;
 
int parent[ARRAY_SIZE_MAX];
bool visited[ARRAY_SIZE_MAX];
 
int main() 
{
    int case_num;    // 테스트 케이스 수
    int node_num;    // 노드의 수
    int A, B;    // 노드 데이터
    int U, V;    // 공통 조상을 구할 노드
    
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    for(int t = 0; t < case_num; t++) {
        scanf("%d", &node_num);    // 노드의 수 입력
        for(int i = 1; i <= node_num; i++) {
            parent[i] = i;    // 자기자신을 부모로 초기화
            visited[i] = false;
        }
        
        for(int i = 0; i < node_num - 1; i++) {
            scanf("%d %d", &A, &B);    // 노드 데이터 입력
            parent[B] = A;
        }
        
        scanf("%d %d", &U, &V);    // 공동 조상을 구할 두 노드
        
        visited[U] = true;
        
        while (parent[U] != U) {    // 데이터가 루트가 아닌 경우
            U = parent[U];    // 부모노드로 올라감
            visited[U] = true;    // 방문했다고 체크
        }
        
        while(1) {
            if (visited[V] == true || V == parent[V])     // 방문했고, 노드가 부모와 같다면 탈출
                break;
            
            else { 
                V = parent[V];
            }
        }
        
        printf("%d\n", V);    // 출력
    }
    
    return 0;
}
