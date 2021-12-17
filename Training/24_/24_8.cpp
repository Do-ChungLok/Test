#include <stdio.h>
#include<queue>

using namespace std;

#define ARRAY_SIZE_MAX 100001

void check(int);

queue <int> q;    // bfs 방법을 사용하기 위해 큐 선언

int subin;    // 수빈이 위치
int brother;    // 동생 위치
int visited[ARRAY_SIZE_MAX];    // 방문 여부 확인

int bfs()
{
    q.push(subin);    // 수빈의 처음 위치 push
    int time = 0;     // 동생 위치까지 걸리는 시간
    
    while (!q.empty()){
        int s = q.size();
        for (int i = 0; i < s; ++i)
        {
            int current = q.front();    // 현재 위치에 저장
            q.pop();
            
            if (current == brother)        // 목적지(동생위치) 도달 시 
                return time;
            check(current+1);    // 걷는다면 X + 1
            check(current-1);    // 걷는다면 X - 1
            check(current*2);    // 순간이동 한다면 X * 2
        }
        ++time;
    }
    
    return 0;
}

void check(int num)    // 이동하는 곳이 유효한지 체크
{
    if (num >= 0 && num <= 100000 && !visited[num]){    // 배열 범위에 유효한지, 방문한 곳이 아닌지 판단
    
        visited[num] = 1;
        q.push(num);
    }
}

int main()
{
    scanf("%d %d", &subin, &brother);
    printf("%d", bfs());
    
    return 0;
}
