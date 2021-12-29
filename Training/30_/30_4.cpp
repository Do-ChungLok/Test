#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <stdio.h>

#define ARRAY_SIZE_MAX 1001

using namespace std;

int god_num;         // 우주신의 개수
int path_num;        // 통로의 개수
int x, y;            // 좌표
int path1, path2;    // 이미 연결된 통로
int parent[ARRAY_SIZE_MAX];
double d, result;    // 두 점의 거리, 결과값

vector <pair <int, int> > god;    // x좌표, y좌표
vector <tuple <double, int, int> > DIST;    // 거리, x좌표, y좌표

int findParent(int node)    // 노드의 부모를 찾는 함수
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
	node1 = findParent(node1);    // 노드1의 부모를 찾고,
	node2 = findParent(node2);    // 노드2

	if (node1 == node2) {    // 부모가 같다면 결합하면 사이클 이므로 연결x
        return false;
    }
    
	else {
		parent[node1] = node2; // 결합 & 부모노드로 기록
		return true;
	}
}

double Cal_dist(int x1, int y1, int x2, int y2)    // 좌표들의 거리 구하는 함수
{
	double x_dist = pow(x1 - x2, 2);
	double y_dist = pow(y1 - y2, 2);

	return sqrt(x_dist + y_dist);
}

int main()
{
    scanf("%d", &god_num);    // 우주신들의 개수 입력
    scanf("%d", &path_num);   // 통로의 개수 입력
    
	for (int i = 1; i <= god_num; i++){    // 일단 처음엔 부모노드에 자기자신 저장
		parent[i] = i;
    }

	god.push_back({ 0, 0 });    // 우주신들의 초기 좌표 입력
    
	for (int i = 1; i <= god_num; i++){
        scanf("%d %d", &x, &y);    // 좌표 입력
		god.push_back({x, y});
	}
	
	for (int i = 1; i <= path_num; i++){
        scanf("%d %d", &path1, &path2);    // 연결된 통로 입력
		union_func(path1, path2);
	}    
    
	for (int i = 1; i <= god_num - 1; i++) {    // 좌표 사이의 거리 계산
		for (int j = i + 1; j <= god_num; j++) {
			double r = Cal_dist(god[i].first, god[i].second, god[j].first, god[j].second);
			DIST.push_back({ r, i, j });
		}
	}

	sort(DIST.begin(), DIST.end());    // 오름차순 정렬

	for (int i = 0; i < DIST.size(); i++) {    // MST 계산
        d = get<0>(DIST[i]);    // 거리
		x = get<1>(DIST[i]);
		y = get<2>(DIST[i]);

		if (union_func(x, y)) {
            result += d;	
        }
	}

	printf("%.2f", result);    // 결과 출력
    
    return 0;
}
