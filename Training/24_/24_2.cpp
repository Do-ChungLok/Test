#include <stdio.h>

#define ARRAY_SIZE_MAX 101

using namespace std;

int com_num = 0;    // 컴퓨터 수 (정점의 수)
int pair_com_num = 0;    // 컴퓨터 쌍의 수
int virus_count = 0;    // 바이러스 감염된 수
int pair_arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 간선이 연결하는 두 정점의 번호가 저장될 배열 
int from = 0, to = 0;    // 정점의 번호
int visited[ARRAY_SIZE_MAX];

void dfs(int start_spot)
{
    int i = 0;
    
    visited[start_spot] = 1;    // 방문했다는 표시
    virus_count++;    // 연결되어있으면 바이러스 카운트++
    
    for (i = 1; i <= com_num; i++){    // 인접 정점 체크
        if (pair_arr[start_spot][i] == 1 && visited[i] == 0){    // 이동가능하고, 방문하지 않았다면 dfs(i) 호출
            dfs(i);
        }
    }
   
    return;    
    
}



int main()
{
	scanf("%d", &com_num);    // 컴퓨터 수 입력 (정점의 수)
    scanf("%d", &pair_com_num);    // 컴퓨터 쌍의 수 입력
    
    for (int i = 0; i < pair_com_num; i++){
        scanf("%d %d", &from, &to);
        
        pair_arr[from][to] = 1;
        pair_arr[to][from] = 1;
    }
    
    dfs(1);
    
    printf("%d", virus_count - 1);    // 컴퓨터1의 수는 제외해야 하므로 '-1'
    
    return 0;

}
