#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
	double pi = 3.14159265358979f;
	double x1, y1, r1, x2, y2, r2;
    
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);    // 좌표, 반지름 길이 입력
    
	if (r1 < r2){    // r1을 더 크게 설정
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}

	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));    // 원 중심간의 거리

	if (d >= r1 + r2) { // 면적이 겹치지 않을 때
        printf("0.000");
	}
    
	else if (d + r2 <= r1) { // 작은 원이 큰 원 내부에 있을 때
        printf("%.3lf", r2 * r2 * pi );
	}
    
	else { // 원 면적이 부분적으로 겹칠 때 -> 코사인 법칙으로 세타1, 2 구함

		double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));    // 세타1
		double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));    // 세타2
        
		double S1 = (r1 * r1 * 2 * theta1) / 2 - r1 * r1 * sin(2 * theta1) / 2;    // 부채꼴넓이1 - 삼각형 넓이1
		double S2 = (r2 * r2 * 2 * theta2) / 2 - r2 * r2 * sin(2 * theta2) / 2;    // 부채꼴넓이2 - 삼각형 넓이2

		double result = S1 + S2;    // 총 면적
        
        printf("%.3lf", result);    // 결과 출력
	}

    return 0;
}
