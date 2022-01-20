#include <stdio.h>
#include <algorithm>
#include <vector>

#define ARRAY_SIZE_MAX 1000000

using namespace std;

int people_num;    // 사람 수
int destination_distance;      // 최종 목적지 거리

vector <pair <long long, long long>> Line;    // 선분 시작, 끝 좌표 저장

int main()
{
    scanf("%d %d", &people_num, &destination_distance);    // 사람 수, 최종 목적지 거리 입력
    for(int i = 0; i < people_num; i++) {
        int input_a, input_b;
        scanf("%d %d", &input_a, &input_b);    // 선분 시작, 끝 좌표 입력
        
        // 시작점이 끝점보다 큰 경우(input_b > input_a)에만 pair<int, int> 배열에 <input_b, input_a> 쌍을 저장
        if (input_a > input_b) {    
            Line.push_back({ input_b, input_a});
        }
    }
        
    sort(Line.begin(), Line.end()); // 선분 좌표들 정렬
    
    long long start_point = 0;    // 초기값 설정
    long long end_point = 0;     // 초기값 설정
    long long length = 0 ;    // 길이 초기값 설정
    
    for (int i =0; i < Line.size(); i++) {
        if (end_point < Line[i].first) {    // 역방향 사람이 지금 처리중인 운행 구간과 겹치지 않는 경우
            length+= (2 * (end_point - start_point));
            start_point = Line[i].first;
            end_point = Line[i].second;
        } 
        
        else {
            end_point = max(end_point, Line[i].second);
        } 
    }
    
    length += (2 * (end_point - start_point));    // 왼쪽으로 갔다가 다시 복귀 해야하니 '* 2' 를 해줌
    printf("%lld\n", destination_distance + length);    // 출력
    
    return 0;
}
