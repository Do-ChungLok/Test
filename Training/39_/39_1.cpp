#include <stdio.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 1000000

using namespace std;
int line_num;    // 선을 그은 횟수
pair <int, int> Line[ARRAY_SIZE_MAX];    // 선분 시작, 끝 좌표 저장

int main()
{
    scanf("%d", &line_num);    // 선을 그은 횟수 입력
    for(int i = 0; i < line_num; i++) {
        scanf("%d %d", &Line[i].first, &Line[i].second);    // 선분 시작, 끝 좌표 입력
    }
    
    sort(Line, Line + line_num); // 선분 좌표들 정렬
    int start_point = Line[0].first;    // 초기값 설정
    int end_point = Line[0].second;     // 초기값 설정
    int length = 0;    // 길이 초기값 0 설정
    
    for (int i = 1; i < line_num; i++) {
        if (end_point < Line[i].first) {    // 선 안 겹치는 경우, Line[i].first : 선분 시작 좌표
            length+= end_point - start_point;
            start_point = Line[i].first;
            end_point = Line[i].second;
        }
        
       
        else {
            end_point = max(end_point, Line[i].second); // 선 겹치는 경우
        } 
    }
    length+= end_point - start_point;
    printf("%d",length);    // 출력
    
    return 0;
}
