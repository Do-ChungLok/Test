#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

#define X first
#define Y second
#define ARRAY_SIZE_MAX 3001

int line_num, group_num, line_of_group_num;    // 선분의 개수, 그룹의 개수, 그룹에 속한 선분의 개수
bool visit[ARRAY_SIZE_MAX];    // 방문여부
int parent[ARRAY_SIZE_MAX];    
vector <int> graph[ARRAY_SIZE_MAX];
vector <pair<int, int>> vec[ARRAY_SIZE_MAX];
queue<int> q;

int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
	int tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
	tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

	if (tmp > 0) 
        return 1; // 반시계
    
	else if (tmp == 0) 
        return 0; // 일직선
    
	else if (tmp < 0) 
        return -1; // 시계방향
        
        return 0;
}

bool check(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D) // 두 선분 교차 여부
{
	int ans1 = ccw(A, B, C) * ccw(A, B, D);    // 선분 AB 기준으로 C, D 체크
	int ans2 = ccw(C, D, A) * ccw(C, D, B);    // 선분 CD 기준으로 A, B 체크

	if (ans1 == 0 && ans2 == 0) { // 평행 혹은 양 끝점이 접촉해 있을 때
		if (A > B) {    // A>B인 경우 위치 바꾸기
            swap(A, B);
        }
        
		if (C > D) {    // C>D인 경우 위치 바꾸기
            swap(C, D);
        }
		
		if (A <= D && B >= C) {    // A<=D  && B>=C인 경우 교차     
            return true;
        }
        
		else {
            return false;
        }
	}
    
	else  {
		// 교차 혹은 한 점이 선분 위에 있을 때(끝점 x)
		if (ans1 <= 0 && ans2 <= 0) {    // 교차o
            return true;
        }
        
		else {
            return false;
        }
	}
}

int find_parent(int node) // 부모 노드 찾기
{
	if (node == parent[node]) {
        return node;
    }
    
	else {
        return parent[node] = find_parent(parent[node]);
    }
}

bool union_segment(int u, int v) // 노드 연결
{
	u = find_parent(u);
	v = find_parent(v);

	if (u == v) {    // 부모 노드가 같다면 싸이클이 생기므로 건너뜀
        return false;
    }
    
	else {
		parent[u] = v;    // 부모 노드 지정

		graph[u].push_back(v);    // 노드 연결 표시
		graph[v].push_back(u);

		return true;
	}
}

void bfs(int x) // 연결된 노드 수 판별
{
	int num = 1; // 현재 그룹에 속한 선분 수 1로 초기화
	q.push(x); // 시작노드

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		visit[now] = true;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (!visit[next]) { // 방문하지 않았다면
				num++;    // 선분 수 ++
				q.push(next);
			}
		}
	}

	line_of_group_num = max(line_of_group_num, num);
}

int main()
{
    scanf("%d", &line_num);    // 선분의 수 입력

	int x1, x2, y1, y2;
	for (int i = 1; i <= line_num; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);    // 좌표 입력
		vec[i].push_back({ x1, y1 }); 
		vec[i].push_back({ x2, y2 });
	}

	for (int i = 1; i <= line_num; i++)    // 자기자신을 부모로 지정
		parent[i] = i;

	for (int i = 1; i <= line_num; i++) {
		for (int j = i + 1; j <= line_num; j++) {
			bool state = check(vec[i][0], vec[i][1], vec[j][0], vec[j][1]);

			if (state == true) // 두 선분이 이어져 있다면,
				union_segment(i, j); // 노드 연결
		}
	}

	for (int i = 1; i <= line_num; i++) {
		if (!visit[i]) {
			group_num++; // 그룹 수 추가
			bfs(i); // i 노드 기준으로 연결된 노드 수 체크  
		}
	}
    
    printf("%d\n", group_num);    // 그룹의 수 출력
    printf("%d\n", line_of_group_num);    // 그룹에 속한 선분 수 출력
    
    return 0;
}
