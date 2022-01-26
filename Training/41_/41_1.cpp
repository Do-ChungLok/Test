#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
 
struct Coordinate { 
    long long x, y; 
};

vector <Coordinate> Point;
 
long long CCW(Coordinate a, Coordinate b, Coordinate c)    	// ccw 계산
{
    return a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
    // 음수 : 시계 
	// 양수 : 반시계 
	//  0  : 평행
}
 
bool minCCW(Coordinate a, Coordinate b)    
{
    long long Value = CCW(Point[0], a, b);
    if (Value) {
        return Value > 0;
    }
    
    else if(a.y != b.y) {    // y 좌표 먼저 오름차순 정렬하고, x 좌표 오름차순 정렬
        return a.y < b.y;
    }
    
    else  {
        return a.x < b.x;
    }
}
 
int main() 
{
    int dot_num;    // 점의 개수
    Coordinate temp1, temp2;
    stack <Coordinate> Convex;
    
    scanf("%d", &dot_num);    // 점의 개수 입력
    Point.resize(dot_num);
    
    for(int i = 0; i < dot_num; i++) {
        scanf("%lld %lld", &Point[i].x, &Point[i].y);    // x, y 좌표 입력
    }
    
    for(int i=1; i<dot_num; i++) {
        if(Point[i].y < Point[0].y || (Point[i].y == Point[0].y && Point[i].x < Point[0].x)) {
            long long temp = Point[0].x;
            Point[0].x = Point[i].x;
            Point[i].x = temp;
            
            temp = Point[0].y;
            Point[0].y = Point[i].y;
            Point[i].y = temp;
        }
    }
    
    sort(Point.begin()+1, Point.end(), minCCW);    // 정렬
    Convex.push(Point[0]);    // 스택에 초기 점 입력
    Convex.push(Point[1]);    // 스택에 두번째 점 입력
    
    for (int i = 2; i < dot_num; i++) {
        while (Convex.size() >= 2) {    // 스택에 2개이상 점이 있는경우 계속 반복
            temp2 = Convex.top();
            Convex.pop();    // 데이터 제거
            temp1 = Convex.top();
            
            if (CCW(temp1, temp2, Point[i]) > 0) {    // 스택 최상단 점 2개와 다음 점의 관계가 반시계인경우
                Convex.push(temp2);    // 데이터 push
                break;
            }
        }
        Convex.push(Point[i]);    // 다음 점을 스택에 push
    }
    printf("%ld", Convex.size());    // 출력
    
    return 0;
}
