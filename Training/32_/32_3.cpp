#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

#define X first
#define Y second
typedef long long ll;

ll x, y;
vector <pair<ll, ll>> vec;

ll ccw(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C)
{
	ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
	tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

	if (tmp > 0) 
        return 1; // 반시계
    
	else if (tmp == 0) 
        return 0; // 일직선
    
	else if (tmp < 0) 
        return -1; // 시계방향
}

int solve(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D)
{
	ll ans1 = ccw(A, B, C) * ccw(A, B, D);    // 선분 AB 기준으로 C, D 체크
	ll ans2 = ccw(C, D, A) * ccw(C, D, B);    // 선분 CD 기준으로 A, B 체크

	if (ans1 == 0 && ans2 == 0) {    // pair 대소비교. 첫번째 인자가 같다면 두번째 인자 비교
		if (A > B) {    // A>B인 경우 위치 바꾸기
            swap(A, B);
        }
        
		if (C > D) {    // C>D인 경우 위치 바꾸기
            swap(C, D);
        }
        
		if (A <= D && B >= C)     // A<=D  && B>=C인 경우 교차하니까 '1'출력
            return 1; 
        
		else                     // 교차하지 않으니 '0' 출력
            return 0; 
	}
    
	else {
		if (ans1 <= 0 && ans2 <= 0)     // AB와 CD 기준으로 조건 충족시 교차하니까 '1'출력
            return 1; 
        
		else                             // 조건 충족x '0' 출력
            return 0;
	}
	
}

int main()
{
    int result = 0;    // 결과값
    
	for (int i = 0; i < 4; i++) {
        scanf("%lld %lld", &x, &y);    // 좌표 입력
		vec.push_back({ x,y });
	}
    
    result = solve(vec[0], vec[1], vec[2], vec[3]);
    
    printf("%d", result);    // 결과 출력

}
