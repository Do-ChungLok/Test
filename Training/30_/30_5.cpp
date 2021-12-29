#include <algorithm>
#include <vector>
#include <tuple>
#include <stdio.h>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int planet_num;      // 행성의 개수
int x, y, z;         // 좌표
int parent[ARRAY_SIZE_MAX];
int result;          // 결과값
int a, b, c;

vector <pair <int, int> > X;    // x좌표
vector <pair <int, int> > Y;    // y좌표
vector <pair <int, int> > Z;    // z좌표
vector <tuple <int, int, int> > PLANET;    // 거리, x좌표, y좌표

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

int main()
{
    scanf("%d", &planet_num);    // 행성의 개수 입력
    
	for (int i = 0; i < planet_num; i++){    // 일단 처음엔 부모노드에 자기자신 저장
		parent[i] = i;
    }

	for (int i = 0; i < planet_num; i++){
        scanf("%d %d %d", &x, &y, &z);    // 좌표 입력
		X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
	}
    
    sort(X.begin(), X.end());    // x좌표 오름차순 정렬
    sort(Y.begin(), Y.end());    // y좌표 오름차순 정렬
    sort(Z.begin(), Z.end());    // z좌표 오름차순 정렬
	
	for (int i = 0; i < planet_num - 1; i++) {    // 좌표 사이의 거리 계산
        PLANET.push_back({X[i + 1].first - X[i].first, X[i].second, X[i + 1].second});
        PLANET.push_back({Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second});
        PLANET.push_back({Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second});
	}

	sort(PLANET.begin(), PLANET.end());    // 오름차순 정렬

	for (int i = 0; i < PLANET.size(); i++) {    // MST 계산
        a = get<0>(PLANET[i]);    // 거리
		b = get<1>(PLANET[i]);
		c = get<2>(PLANET[i]);

		if (union_func(b, c)) {
            result += a;	
        }
	}

	printf("%d", result);    // 결과 출력
    
    return 0;
}
