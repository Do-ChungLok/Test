#include <iostream>
#include <vector>
#include <climits>

#define ARRAY_SIZE_MAX 110

using namespace std;

int city_num;    // 도시의 수
int bus_num;     // 버스의 수
long long Cost[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 최소비용 배열
int Route[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // Route[a][b] = c : 정점 a -> 정점 b 최소 비용으로 갈 때 거쳐가는 정점은 c
int INF = INT_MAX;

vector<int> V;
 
int Min(int A, int B) 
{ 
    if (A < B) {
        return A;
    } 
    
    else {
        return B;         
    }
}

void Floyd_Warshall(){
    for (int k = 1; k <= city_num; k++){    // 중간 거쳐가는 지점
        for (int i = 1; i <= city_num; i++){    // 시작 지점
            for (int j = 1; j <= city_num; j++){    // 도착 지점
                if (i == j) {
                    continue;
                }
                
                if (Cost[i][j] > Cost[i][k] + Cost[k][j]) {
                    Cost[i][j] = Cost[i][k] + Cost[k][j];
                    Route[i][j] = k;              
                }
            }
        }
    }
}
 
void Find_Route(int Start, int End)
{
    if (Route[Start][End] == 0) {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    
    Find_Route(Start, Route[Start][End]);
    V.pop_back();    // a -> b, b -> c 일때 'a b b c'를 방지하고자 'b' 하나 삭제하여 'a b c'로 출력
    Find_Route(Route[Start][End], End);
}
 

int main()
{
    scanf("%d", &city_num);    // 도시의 수 입력
    scanf("%d", &bus_num);     // 버스의 수 입력
    for (int i = 1; i <= city_num; i++) {
        for (int j = 1; j <= city_num; j++) {
            Cost[i][j] = INF;
        }
    }
 
    for (int i = 0; i < bus_num; i++){
        int start_city, target_city, bus_cost; 
        
        scanf("%d %d %d", &start_city, &target_city, &bus_cost);    // 출발, 도착 도시 번호, 비용 입력
        Cost[start_city][target_city] = Min(Cost[start_city][target_city], bus_cost);
    }    
    
    Floyd_Warshall();
    
    for (int i = 1; i <= city_num; i++){
        for (int j = 1; j <= city_num; j++){
            if (Cost[i][j] == INF) {
                printf("0 ");
            }
            
            else {
                printf("%lld ", Cost[i][j]);
            }
        }
        printf("\n");
    }
    
    for (int i = 1; i <= city_num; i++){
        for (int j = 1; j <= city_num; j++){
            if (Cost[i][j] == INF) {
                printf("0");
            }
            
            else {
                V.clear();
                Find_Route(i, j);
                printf("%d ", V.size());
                
                for (int k = 0; k < V.size(); k++) {
                    printf("%d ", V[k]);
                }
            }
            printf("\n");
        }
    }    
    return 0;
}

