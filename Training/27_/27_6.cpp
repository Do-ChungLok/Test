#include <cstdio>
#include <queue>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

queue <int> q;    // 수빈 위치 저장할 벡터
vector <int> bro_location;    // 동생 위치 저장할 벡터

int subin;    // 수빈이 위치
int brother;    // 동생 위치
int visit[ARRAY_SIZE_MAX];    // 방문 여부 확인
int discover[ARRAY_SIZE_MAX];    // discover[현재 위치] = 이전 위치

bool range(int next)     // 범위가 유효한지 체크
{
    return next >= 0 && next < ARRAY_SIZE_MAX;
}

void bfs(int subin) 
{
	visit[subin] = 0;
	q.push(subin);    // 수빈의 처음 위치 push
    
	while (!q.empty()) {
		int current = q.front();    // 현재 위치에 저장     
        q.pop();
        
		if (current == brother) {    // 목적지(동생위치) 도달 시 
			return;
		}
        
        // 범위가 유효하고, 방문하지 않았다면 push후 현재 위치 저장하고 방문했다고 체크
		if (range(current - 1) && visit[current-1] == 0) {
			q.push(current - 1);
			discover[current - 1] = current;
			visit[current - 1] = visit[current] + 1;
		}
		if (range(current + 1) && visit[current + 1] == 0) {
			q.push(current + 1);
			discover[current + 1] = current;
			visit[current + 1] = visit[current] + 1;
		}
		if (range(current * 2) && visit[current * 2] == 0) {
			q.push(current * 2);
			discover[current * 2] = current;
			visit[current * 2] = visit[current] + 1;
		}
	}
}

int main() 
{
	scanf("%d %d", &subin, &brother);    // 수빈, 동생 위치 입력
	bfs(subin);    // 수빈위치 변수로 bfs 함수 호출
    
	printf("%d\n", visit[brother]);    // 동생을 찾는 가장 빠른 시간
    
	int idx = brother;
	bro_location.push_back(brother);
    
	while (idx != subin) {
		bro_location.push_back(discover[idx]);
		idx = discover[idx];
	}
    
	for (int i = bro_location.size() - 1; i >= 0; i--) {    // 동생 위치에서 수빈 위치까지 역순으로 탐색
		printf("%d ", bro_location[i]);    // 동생의 이동 위치 출력
	}
    
	return 0;
}
