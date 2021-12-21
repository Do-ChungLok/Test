#include <iostream>
#include <algorithm>
#include <climits>
#define ARRAY_SIZE_MAX 401

using namespace std;

int INF = INT_MAX;
int town_num, road_num ;    // 마을의 수, 도로의 수
int from_town, to_town, distance_town; // 시작 마을, 도착 마을, 마을간의 거리
long long arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX]; // 마을이 최대 400개니까 401로 설정
long long result = INF;

void floydWarshall() {    // 플로이드와셜 함수
    for (int k = 1; k <= town_num; k++) {     // 거쳐가는 노드
        for (int i = 1; i <= town_num; i++) {   // 출발 노드
            for (int j = 1; j <= town_num; j++) { // 도착 노드
                 arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]); // i마을 -> j마을 거리가 i -> k + k -> j보다 크다면 우항의 값을 대입                                    
            }    
        }
    }

    for(int i = 1; i <= town_num; i++) {
        result = min(result, arr[i][i]);    // 최단거리 저장
    }
    
    if (result >= INF){
        printf("-1");    // 사이클이 없는 경우
    }
    
    else{
        printf("%lld", result);
    }

}

int main() {
    scanf("%d %d", &town_num, &road_num);    // 마을 수, 도로 수 입력

    for (int i = 1; i <= town_num; i++) {
        for(int j = 1; j <= town_num; j++) {
            arr[i][j] = INF;    // 우선 INF로 arr을 초기화
        }
    } 

    for (int i = 0; i < road_num; i++) {
        scanf("%d %d %d", &from_town, &to_town, &distance_town);    // 시작 마을, 도착 마을, 거리 입력
        arr[from_town][to_town] = distance_town;
    }

    floydWarshall();

    return 0;
}
