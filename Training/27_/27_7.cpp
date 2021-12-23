#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>

#define ARRAY_SIZE_MAX 100001

using namespace std;
    
bool visit[ARRAY_SIZE_MAX];

void bfs(int start, int target)
{
    memset(visit, false, sizeof(visit));    
    queue < pair < int, string > > q;    // 현재숫자, 연산 목록
    
    q.push({start, ""});
    visit[start] = true;
    
    while(!q.empty()){
        int current = q.front().first;
        string op = q.front().second;
        q.pop();
        
        if (current == target){    // 종료 조건
            //printf("%s", op);
            cout << op << "\n";
            break;
        }
        
        int next = current * 2;    // D 연산
        next = next > 9999 ? next % 10000 : next;
        
        if (!visit[next]){
            q.push({next, op + "D"});
            visit[next] = true;
        }
        
        next = current == 0 ? 9999 : current - 1;    // S 연산
        
        if (!visit[next]){
            q.push({next, op + "S"});
            visit[next] = true;
        }
        
        next = (current % 1000) * 10 + current / 1000;    // L 연산
        
        if (!visit[next]){
            q.push({next, op + "L"});
            visit[next] = true;
        }    
        
        next = (current / 10) + (current % 10) * 1000;    // R 연산
        
        if (!visit[next]){
            q.push({next, op + "R"});
            visit[next] = true;
        }        
    }
    
}

int main()
{
    int case_num;    // 테스트 케이스 수

    //scanf ("%d", &case_num);
    cin >> case_num;    // 케이스 수 입력
    for (int i = 0; i < case_num; i++){
        int start, target;
        cin >> start >> target;    // 처음수, 두번째 수 입력
        //scanf("%d %d", &start, &target);
        bfs(start, target);    // bfs 함수 호출
    }
}
