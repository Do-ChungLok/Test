#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Coordinate { 
    long long x, y; 
};

Coordinate operator-(Coordinate a, Coordinate b) 
{
    Coordinate c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

vector <Coordinate> Point;

long long CCW(Coordinate a, Coordinate b, Coordinate c) 
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

long long Dist_Square(Coordinate a, Coordinate b) 
{ 
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}

int main() 
{
    int case_num;
    int city_num;
    Coordinate Temp1, Temp2;
    stack <Coordinate> Convex;

    scanf("%d", &case_num);
    
    for (int i = 0; i < case_num; i++) {
        scanf("%d", &city_num);
        Point.resize(city_num);
        
        for (int i = 0; i < city_num; i++) {
            scanf("%lld %lld", &Point[i].x, &Point[i].y);    // x, y 좌표 입력
        }
        
        for (int i = 1; i < city_num; i++) {
            if (Point[i].y < Point[0].y || (Point[i].y == Point[0].y && Point[i].x < Point[0].x)) {
                long long temp = Point[0].x;
                Point[0].x = Point[i].x;
                Point[i].x = temp;
                
                temp = Point[0].y;
                Point[0].y = Point[i].y;
                Point[i].y = temp;
            }
        }
        
        sort(Point.begin() + 1, Point.end(), minCCW);    // 정렬
        Convex.push(Point[0]);
        Convex.push(Point[1]);
        
        for (int i = 2; i < city_num; i++) {
            while (Convex.size() >= 2) {
                Temp2 = Convex.top();
                Convex.pop();
                Temp1 = Convex.top();
                
                if (CCW(Temp1, Temp2, Point[i]) > 0) {
                    Convex.push(Temp2);
                    break;
                }
            }
            Convex.push(Point[i]);
        }
        
        vector <Coordinate> Vertex;
        int Size = Convex.size();
        Vertex.resize(Size);
        
        for (int i = Size - 1; i >= 0; i--) {
            Vertex[i] = Convex.top();
            Convex.pop();
        }

        int LPoint = 0, RPoint = 0;
        for (int i = 0; i < Size; i++) {
            if (Vertex[i].x < Vertex[LPoint].x) {
                LPoint = i;
            }
            
            if (Vertex[i].x > Vertex[RPoint].x) {
                RPoint = i;
            }
        }
        
        long long DiaSq = Dist_Square(Vertex[LPoint], Vertex[RPoint]);
        Coordinate Origin, Ans1, Ans2;
        Origin.x = 0, Origin.y = 0;
        Ans1 = Vertex[LPoint], Ans2 = Vertex[RPoint];
        
        for (int i = 0; i < Size; i++) {
            // 외적값이 음수일 때
            if (CCW(Origin, Vertex[(LPoint + 1) % Size] - Vertex[LPoint], Vertex[RPoint] - Vertex[(RPoint + 1) % Size]) > 0) {
                LPoint = (LPoint + 1) % Size;
            }
            
            else {
                RPoint = (RPoint + 1) % Size;
            }
            
            if (Dist_Square(Vertex[LPoint], Vertex[RPoint]) > DiaSq) {
                DiaSq = Dist_Square(Vertex[LPoint], Vertex[RPoint]);
                Ans1 = Vertex[LPoint];
                Ans2 = Vertex[RPoint];
            }
        }
        
        printf("%lld %lld %lld %lld\n", Ans1.x, Ans1.y, Ans2.x, Ans2.y);
    }
    
    return 0;
}
