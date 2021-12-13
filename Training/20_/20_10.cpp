#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
 
#define COORDINATE_SIZE_MAX 100000000
 
using namespace std;
 
typedef pair<int, int> pii;
 
map<pii, int> mp;
 
double getDistance(pii a, pii b)    // 거리 구하는 함수
{
    int x = a.first - b.first;
    int y = a.second - b.second;
 
    return (double)(x*x + y*y);
}
 
int main()
{
    int spot_num;    // 점들의 수
    scanf("%d", &spot_num);    // 점들의 수 입력
 
    vector<pii> vec;
 
    for (int i = 0; i < spot_num; i++)
    {
        int x, y;    // x, y 좌표 
        scanf("%d %d", &x, &y);    // x, y 좌표 입력
 
        vec.push_back({x, y});    // vec 벡터에 입력한 x, y 좌표 넣기
    }
 
    sort(vec.begin(), vec.end());    // x축 정렬 -> x축의 좌표 차이로 탈락 후보들 제외하기 위해
 
    // 처음 두 값 map에 추가(y, x 순서)
    mp[{vec[0].second, vec[0].first}] = 1;
    mp[{vec[1].second, vec[1].first}] = 1;
 
    double result = getDistance(vec[0], vec[1]);    // 최소값(결과값) 초기화
 
    int last = 0;    // i 점 기준으로 map에서 가장 왼쪽에 위치한 좌표(점)
 
    for (int i = 2; i < spot_num; i++)
    {
        // while문은 최솟값보다 x간의 거리가 더 큰 것을 제거하는 과정
        // x간의 거리가 최솟값 보다 더 크면 y값을 비교할 필요가 없다.
        while (last < i)
        {
            // i > last 인 경우
            int dx = vec[i].first - vec[last].first;    // x축간의 거리 차이 
 
            if (dx * dx <= result)    // 최솟값이 더 크거나 같으면 탈출 
                break;

            mp.erase({ vec[last].second, vec[last].first });    // 최솟값 보다 더 큰 last에 해당하는 mp값 제거
            last++;
        }
 
        int limit = sqrt(result);    // result의 실제 거리
 
        // y좌표를 봤을 때 현재 알고있는 최솟값 기준으로 답일 수 있는 영역 설정
        auto lo = mp.lower_bound({ vec[i].second - limit, -COORDINATE_SIZE_MAX });
        auto up = mp.upper_bound({ vec[i].second + limit,  COORDINATE_SIZE_MAX });

        for (auto it = lo; it != up; it++)    // 그 영역 내에서 최솟값
            result = min(result, getDistance({ it->first.second, it->first.first }, vec[i]));

        mp[{vec[i].second, vec[i].first}] = 1;    // map에 추가
    }
 
    printf("%d", (int)result);    // 결과값 출력
    return 0;
}
