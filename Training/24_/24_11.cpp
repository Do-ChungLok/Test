#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 20001

using namespace std;

vector<int> map[ARRAY_SIZE_MAX];    // 좌표 배열 벡터 선언

int color[ARRAY_SIZE_MAX];      // 1일때는 빨강, 2일때는 파랑, 0일때는 접근X
 
void DFS(int node, int c)
{
    color[node] = c;
    
    for(int i = 0; i < map[node].size(); i++){
        int next = map[node][i];
        if(color[next] == 0){
            DFS(next, 3-c); //빨강 다음에는 파랑이여야하고 파랑 다음은 빨강이여야 함.
                            //따라서 3-1 = 2, 3-2 = 1
        }
    }
}

int main(){
    int case_num;    // 테스트 케이스 수
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    while (case_num--) {    // 케이스 수가 음수가 될떄까지 반복
        int spot_num, line_num;
        
        scanf("%d %d", &spot_num, &line_num);    // 정점 수, 간선 수 입력
      
        for(int i = 1; i <= spot_num; i++){
            map[i].clear();    // 벡터를 초기화 시키는데 사용
            color[i]=0;        // color 배열 초기화
        }
        
        for(int i = 0; i < line_num; i++){    // 간선을 연결
            int a, b;
            scanf("%d %d", &a, &b);
                
            map[a].push_back(b);
            map[b].push_back(a);
        }
        
        for(int i = 1; i <= spot_num; i++){    // ==0 인 경우 방문을 안 한거니까 방문하기 위해 dfs수행
            if(color[i]==0){
                DFS(i, 1);
            }
        }
        
        bool isBin=true;
        
        for(int i = 1; i <= spot_num; i++){
            for(int j = 0; j < map[i].size(); j++){
                int k = map[i][j];
                
                if(color[i] == color[k])    // 같은 집단에서 값이 같다는 것은 이분 그래프에 해당x 'false' 
                    isBin = false;
            }
        }
        
        if(isBin){
            printf("YES\n");
        }
            
        else{
            printf("NO\n");
        }
        
    }
    return 0;
}

