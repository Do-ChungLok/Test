#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <climits>

#define ARRAY_SIZE_MAX 501

using namespace std;

int INF = INT_MAX;

int city_num, route_num ;    // 도시의 수, 버스 노선의 수
int A, B, C;    // 버스 노선 A, B, C
int a, b;
long long dist[ARRAY_SIZE_MAX];    // 거리 저장할 배열
bool cycle;

vector< pair<int, int> > vec[501];

int main()
{

    scanf("%d %d", &city_num, &route_num);    // 도시의 수, 버스 노선의 수 입력

	for (int i = 0; i < route_num; i++){
        scanf("%d %d %d", &A, &B, &C);    // 버스 노선 A, B, C 입력
		vec[A].push_back({ B,C });
	}
	
	for (int i = 1; i <= city_num; i++)
		dist[i] = INF; // 벨만포드 알고르짐을 사용하기 위해 초기값 모든 노드를 INF로 설정

	dist[1] = 0; // 시작점 '0'으로 초기화
	
	for (int i = 1; i <= city_num; i++){    // city_num -1 만큼 범위 설정
		for (int j = 1; j <= city_num; j++){    // 모든 정점 탐색
			for (int k = 0; k < vec[j].size(); k++){
				int next = vec[j][k].first;
				int cost = vec[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + cost){
					dist[next] = dist[j] + cost;    // 값이 무한대가 아니고, 현재 값 + cost보다 다음 값이 더 크다면 업데이트
					if (i == city_num) {
                        cycle = true;
                    }
				}
					
			}
		}
    }

	if (cycle == 1) {    // 가중치 합이 음수인 경우
        printf("-1\n");
    }
    
	else{
        
		for (int i = 2; i <= city_num; i++){    
            if (dist[i] != INF){        // 무한값이 아니라면 저장된 'dist[i]' 출력
                cout << dist[i] << '\n';
            }
            
            else if (dist[i] = INF){    // 무한값이 있다면 '-1' 출력
               
                cout << -1 << '\n';
            }
        }
	}
    return 0;	
}
