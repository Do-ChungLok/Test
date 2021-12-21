#include <iostream>
#include <algorithm>
#include <climits>

#define ARRAY_SIZE_MAX 101

using namespace std;

int INF = INT_MAX;
int city_num, route_num ;    // 도시의 수, 버스 노선의 수
int start, arrival, cost; // 출발, 도착, 가중치
int arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX]; // 도시가 최대 100개니까 101로 설정

void floydWarshall() {    // 플로이드와셜 함수
    for (int k = 1; k <= city_num; k++) {     // 거쳐가는 노드
        for (int i = 1; i <= city_num; i++) {   // 출발 노드
            for (int j = 1; j <= city_num; j++) { // 도착 노드
                if (arr[i][k] != INF && arr[k][j] != INF) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]); // 거쳐가는 것의 가중치가 더 적다면 갱신
                }
            }
        }
    }

    for (int i = 1; i <= city_num; i++) {
        for (int j = 1; j <= city_num; j++) {
        
            if(i == j || arr[i][j] == INF){  // 본인에서 본인, 갈길 없음은 0을 출력
                printf("0 ");
             }

            else{
                printf("%d ", arr[i][j]);
            }
        
        } 
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &city_num, &route_num);    // 도시 수, 버스 수 입력

    for (int i = 1; i <= city_num; i++) {
        for (int j = 1; j <= city_num; j++) {
            arr[i][j] = INF;    // 우선 INF로 arr을 초기화
        }
    } 

    for (int i = 0; i < route_num; i++) {
        scanf("%d %d %d", &start, &arrival, &cost);    // 시작 도시, 도착 도시, 비용 입력

        if (arr[start][arrival] > cost) {
            arr[start][arrival] = cost; // 기존값보다 가중치가 작다면 갱신
        }
    }

    floydWarshall();

    return 0;
}
