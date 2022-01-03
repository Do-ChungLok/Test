#include <algorithm>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

int pair_num, x, y;    // 좌표 쌍 개수, x, y 좌표
double result;    // 결과
vector <pair <double, double> > vec;    // 좌표 저장할 벡터

double ccw(int v1, int v2, int v3)    // 외적 계산 함수
{
	double x1 = vec[v1].first;
	double x2 = vec[v2].first;
	double x3 = vec[v3].first;
	double y1 = vec[v1].second;
	double y2 = vec[v2].second;
	double y3 = vec[v3].second;

	double tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	double tmp2 = x2 * y1 + x3 * y2 + x1 * y3;

	double result = tmp1 - tmp2;
	return result / 2;
}

int main()
{
    scanf("%d", &pair_num);    // 좌표 쌍 개수 입력

	for (int i = 0; i < pair_num; i++) {
        scanf("%d %d", &x, &y);    // x, y 좌표 입력
		vec.push_back({ x,y });
	}

	for (int i = 1; i < pair_num - 1; i++)    // 외적 계산을 위한 범위 설정
		result += ccw(0, i, i + 1);

    printf("%.1lf\n", abs(result));    // 소수 둘째자리에서 반올림하여 첫째 자리까지 출력
    
    return 0;
}
