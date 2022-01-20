#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>

#define ARRAY_SIZE_MAX 100001

using namespace std;

pair <int, int> home[ARRAY_SIZE_MAX];
int case_num;    // 테스트 케이스 수
int island_num;  // 섬의 수
long long input_x, input_y;    // x, y 좌표 변수
int x, y;
int segment[4 * ARRAY_SIZE_MAX]; // y의 좌표를 세그먼트 트리의 인덱스로 만듬
int y_index[ARRAY_SIZE_MAX];

bool cmp(pair <int, int> x, pair <int, int> y) 
{
	if (x.first == y.first) {    // x 값이 같다면 y값으로 내림차순 정렬
		return x.second > y.second;
	}

	return x.first < y.first;    // x 값으로 오름차순 정렬
}

int update(int pos, int val, int node, int x, int y)  // x ~ y 인덱스까지의 세그먼트 트리 인덱스값 업데이트
{
	if (y < pos || pos < x) { // 범위를 벗어났을 경우, 노드 값 그대로 반환
		return segment[node];
	}

	if (x == y) { // 리프 노드인 경우, 해당 세그먼트 값 업데이트
		return segment[node] = val;
	}
    
    else {
	    int mid = (x + y) / 2; // 자식 tree size 정의

	    return segment[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y); // 왼쪽 자식 트리 업데이트 값 + 오른쪽 자식 트리 업데이트 값
	    // 왼쪽 자식의 경우, 인덱스는 부모 인덱스 * 2, x는 부모 x값, y는 mid값
        // 오른쪽 자식의 경우, 인덱스는 부모 인데스 * 2 + 1, x값은 mid+1, y는 부모 y값
    }
}

int query(int from, int to, int node, int x, int y)  //  x ~ y 인덱스까지의 노드 쿼리, from ~ to 까지의 인덱스 검색
{
	if (y < from || to < x) { // x ~ y가 찾으려는 범위를 벗어났으면 0 반환
		return 0;
	}

	if (from <= x && y <= to) { // x ~ y가 찾으려는 범위 내면 세그먼트에 저장된 값 반환
		return segment[node];
	}
    
    else {
	    int mid = (x + y) / 2; // 자식 tree size 정의

	    return query(from, to, node * 2, x, mid) + query(from, to, node * 2 + 1, mid + 1, y); // 왼쪽 자식 쿼리 + 오른쪽 자식 쿼리
	    // 왼쪽 자식의 경우, 인덱스 = 부모 인덱스 * 2, x = 부모 x값, y = mid값
	    // 오른쪽 자식의 경우, 인덱스 = 부모 인덱스 * 2 + 1, x = mid+1, y = 부모 y값
    }
}


int main(void) 
{
	scanf("%d", &case_num);    // 테스트 케이스 수 입력

	for (int i = 0; i < case_num; i++) {

		memset(segment, 0, sizeof(segment));    // 0으로 초기화
		memset(y_index, 0, sizeof(y_index));    // 0으로 초기화

		long long cnt = 0;

		scanf("%d", &island_num);    // 섬의 수 입력

		vector <int> ypos;    // y 좌표 벡터

		for (int j = 0; j < island_num; j++) {
			scanf("%lld %lld", &input_x, &input_y);    // x, y 좌표 입력
			home[j] = { input_x, input_y };    // x, y 좌표 배열 저장
			ypos.push_back(input_y);    // y좌표 따로 벡터에 push
		}

		sort(home, home + island_num, cmp);    // x, y 좌표 정렬
		sort(ypos.begin(), ypos.end());
		ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end()); // 좌표 압축을 위한 중복 값 제거


		for (int j = 0; j < island_num; j++) {
			int invert_y = lower_bound(ypos.begin(), ypos.end(), home[j].second) - ypos.begin(); // z는 지금 위치한 섬의 y좌표 압축 결과 인덱스
			cnt += (long long) query(invert_y, island_num - 1, 1, 0, island_num - 1); // 쿼리는 지금 위치한 섬으로 올 수 있는 섬들의 갯수 반환 
			y_index[invert_y]++; // 압축한 y 인덱스 해당 좌표의 섬 갯수 증가
			update(invert_y, y_index[invert_y], 1, 0, island_num - 1); // 세그먼트 트리 값 업데이트
		}

		printf("%lld\n", cnt);    // 출력

	}

	return 0;

}
