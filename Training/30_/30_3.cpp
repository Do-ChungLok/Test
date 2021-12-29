#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <stdio.h>

#define ARRAY_SIZE_MAX 101

using namespace std;

int star_num;    // 별의 개수
double x, y;    // 좌표
int parent[ARRAY_SIZE_MAX];
double d, result;    // 두 별의 거리, 결과값

vector <pair <double, double> > star;
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

double Cal_dist(double x1, double y1, double x2, double y2)    // 별들의 거리 구하는 함수
{
	double x_dist = pow(x1 - x2, 2);
	double y_dist = pow(y1 - y2, 2);

	return sqrt(x_dist + y_dist);
}

int main()
{
    scanf("%d", &star_num);    // 별의 개수 입력
    
	for (int i = 1; i <= star_num; i++){    // 일단 처음엔 부모노드에 자기자신 저장
		parent[i] = i;
    }

	star.push_back({ 0, 0 });    // 별들의 초기 좌표 입력
    
	for (int i = 1; i <= star_num; i++){
        scanf("%le %le", &x, &y);    // 별들 좌표 입력
		star.push_back({x, y});
	}
	
	for (int i = 1; i <= star_num - 1; i++) {    // i번째 별과 j번째 별 사이의 거리 계산
		for (int j = i + 1; j <= star_num; j++) {
			double r = Cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
			DIST.push_back({ r, i, j });
		}
	}

	sort(DIST.begin(), DIST.end());    // 오름차순 정렬

	for (int i = 0; i < DIST.size(); i++) {    // MST 계산
        d = get<0>(DIST[i]);    // 거리
		x = get<1>(DIST[i]);
		y = get<2>(DIST[i]);

		if (union_func(x, y)) 
            result += d;		
	}

	printf("%.2f", result);    // 결과 출력
    
    return 0;
}
