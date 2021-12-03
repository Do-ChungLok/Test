#include <stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int conference_num;  // 회의의 수
    int start_hour;      // 회의 시작 시간
    int end_hour;        // 회의 종료 시간
    
    vector< pair<int, int> > schedule;
    
    scanf("%d", &conference_num);    // 회의 수 입력
    
    for (int i = 0; i < conference_num; i++){
        scanf("%d %d", &start_hour, &end_hour);    // 회의 시작 시간, 종료 시간 입력
        schedule.push_back( make_pair(end_hour, start_hour) );    
    }
    
    sort(schedule.begin(), schedule.end());
    
	int time = schedule[0].first; // 'time' 변수를 처음 회의 스케쥴 종료 시간으로 초기화
	int count = 1;
    
	for (int i = 1 ; i < conference_num; i++) {
		if (time <= schedule[i].second ){    // 두번째 회의 스케쥴 시작 시간 >= 첫번째 스케쥴 종료 시간
			count++;
			time = schedule[i].first;
		}
	}

	printf("%d", count);     
}
