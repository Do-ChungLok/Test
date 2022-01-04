#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

#define X first
#define Y second
typedef long long ll;

ll x, y;
vector <pair<ll, ll>> vec;

void find_intersection(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D) // 교점 구하기
{
	double px = (A.X * B.Y - A.Y * B.X) * (C.X - D.X) - (A.X - B.X) * (C.X * D.Y - C.Y * D.X);
	double py = (A.X * B.Y - A.Y * B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X * D.Y - C.Y * D.X);
	double p = (A.X - B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X - D.X);

	if (p == 0) {    // 평행할 때 
		if (B == C && A <= C) {    // 교점이 하나일 때
            printf("%lld %lld\n", B.X, B.Y);    // 좌표 입력
        }
    
		else if (A == D && C <= A) {
            printf("%lld %lld\n", A.X, A.Y);    // 좌표 입력
        }
	}

	else {          // 교차할 때
	
		double x = px / p;
		double y = py / p;

        printf("%.9lf %.9lf", x, y);    // 좌표의 절대/ 상대 오차는 10^-9 까지니까
	}
}
                                                                  
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
        
        return 0;
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
        
		if (A <= D && B >= C) {    // A<=D  && B>=C인 경우 교차하니까 '1'출력
            printf("1\n");    // 교차
            find_intersection(A, B, C, D);
        }
        
		else {                    // 교차하지 않으니 '0' 출력
            printf("0\n");    // 교차X
        }
	}
    
	else {
		if (ans1 <= 0 && ans2 <= 0) {     // 교차 or 한 점이 선분 위에 있을때 AB와 CD 기준으로 조건 충족시 교차하니까 '1'출력
            printf("1\n");    // 교차
            find_intersection(vec[0], vec[1], vec[2], vec[3]);
        }
        
		else {                            // 조건 충족x '0' 출력
            printf("0\n");    // 교차X
        }            
	}
	
	return 0;
	
}

int main()
{   
	for (int i = 0; i < 4; i++) {
        scanf("%lld %lld", &x, &y);    // 좌표 입력
		vec.push_back({ x,y });
	}
    
    solve(vec[0], vec[1], vec[2], vec[3]);
    
    return 0;

}
