#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <stdio.h>

#define ARRAY_SIZE_MAX 11
#define NUM_SIZE_MAX 7
#define DRIECTION_SIZE_MAX 4

using namespace std;

int col, row, result;    // 세로, 가로, 결과
int island_num;          // 섬 개수
int map[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 맵 사이즈
int visited[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 방문 배열
int island_visit[NUM_SIZE_MAX];    // 섬 방문 배열
int parent[NUM_SIZE_MAX];
int island[NUM_SIZE_MAX][DRIECTION_SIZE_MAX]; // X1, X2, Y1, Y2
int dx[DRIECTION_SIZE_MAX] = { 1, -1, 0, 0 };
int dy[DRIECTION_SIZE_MAX] = { 0, 0, 1, -1 };

vector <tuple <int, int, int> > vec; // {거리, 섬1, 섬2}
vector <int> graph[NUM_SIZE_MAX];
queue <int> q;

int findParent(int node)
{
	if (parent[node] == node) {    // 자기자신이 부모일 경우   
		return node;
    }
    
	else {                         // 부모 노드 찾기
		return parent[node] = findParent(parent[node]);
    }
}

bool union_func(int node1, int node2)    // 노드1, 2를합쳐주는 함수
{
	node1 = findParent(node1);
	node2 = findParent(node2);

	if (node1 != node2) {    // 결합 & 부모노드로 기록
		parent[node1] = node2;

		graph[node1].push_back(node2);    // 섬 간의 연결관계 대입
		graph[node2].push_back(node1);
		return true;
	}
    
	else {
        return false;
    }
		
}

void DFS(int x, int y)    // 섬 번호 부여하기
{
	if (visited[x][y]) {
        return;
    }
	
	visited[x][y] = true;    // 방문 표시
	map[x][y] = island_num;  // 섬 번호

	island[island_num][0] = min(island[island_num][0], x); // X1 : x축 최소값
	island[island_num][1] = max(island[island_num][1], x); // X2 : x축 최대값
	island[island_num][2] = min(island[island_num][2], y); // Y1 : y축 최소값
	island[island_num][3] = max(island[island_num][3], y); // Y2 : y축 최대값

	for (int i = 0; i < 4; i++){
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 1 && next_x <= col && next_y >= 1 && next_y <= row){
			if (map[next_x][next_y] != 0 && !visited[next_x][next_y])
				DFS(next_x, next_y);
		}
	}
}

void distance(int now, int x, int y)    // 섬 간의 최소거리 구하기
{
	for (int i = 0; i < DRIECTION_SIZE_MAX; i++){
		int now_x = x;
		int now_y = y;
		int dist = 0;

		while(1){
			now_x += dx[i];
			now_y += dy[i];
			
			if (now_x < 1 || now_x > col || now_y < 1     // 범위 이탈 또는 현재 섬일 경우 탈출
                || now_y > row || map[now_x][now_y] == now) 
                break;

			if (map[now_x][now_y] != 0) {
				vec.push_back({ dist , now, map[now_x][now_y] });    // {거리, 출발한 섬, 도착한 섬} 
				break;
			}
			dist++;
		}
	}
}

int main()
{
    scanf("%d %d", &col, &row);

	for (int i = 1; i <= 6; i++)    // 초기 세팅
		parent[i] = i;              // 자기 자신을 부모로 지정

	for (int i = 1; i <= col; i++)    // 섬 정보 입력받기
		for (int j = 1; j <= row; j++)
            scanf("%d", &map[i][j]);        

	for (int i = 1; i <= col; i++)    // 섬 번호 부여하기
		for (int j = 1; j <= row; j++){
			if (map[i][j] != 0){
				if(!visited[i][j]) island_num++;
				DFS(i, j);
			}
		}

	for (int i = 1; i <= col; i++){    // 섬 간의 거리 구하기
		for (int j = 1; j <= row; j++){
			if (map[i][j] != 0){
				distance(map[i][j], i, j);
			}
		}
    }

	sort(vec.begin(), vec.end());    // 벡터 오름차순으로 정렬

	for (int i = 0; i < vec.size(); i++){    // MST 구하기
		int dist = get<0>(vec[i]);
		int island_1 = get<1>(vec[i]);
		int island_2 = get<2>(vec[i]);

		if (dist < 2) {    // 다리길이가 2미만이면 탈출
            continue;
        }

		if (union_func(island_1, island_2)) {    // 두 섬간의 다리 건설 시
			result += dist;
        }
	}

	int cnt = 1;    
	q.push(1);

	while (!q.empty()) {    // 섬이 모두 연결되어 있는지 확인
		int now_island = q.front();
		q.pop();
		island_visit[now_island] = true;

		for (int i = 0; i < graph[now_island].size(); i++){
			int next_island = graph[now_island][i];
            
			if (!island_visit[next_island]){
				q.push(next_island);
				cnt++;
			}
		}
	}

	if (cnt != island_num) {
        printf("-1\n");    // 출력
    }
    
	else {
        printf("%d\n", result);    // 출력
    }
}
