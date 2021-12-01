#include <iostream>
#include <algorithm>

#define MAX 20
#define DIFF_MIN 2e9

using namespace std;

int N;                   // 인원 수
int ability[MAX][MAX];   // 능력치
int team[MAX];           // 각 인원이 속한 팀 - 0 : start, 1 : link
int min_Diff = DIFF_MIN;  // 차이의 최솟값

void calculate_ability()     // 각 팀별 능력치 각각 구하기 
{
    int startTeam_ability = 0; // start Team 능력치
    int linkTeam_ability = 0;  // link Team 능력치
    

    for (int i = 0; i < N; i++) {    // 팀 능력치 구하기
        for (int j = 0; j < N; j++) {
            if (i == j) 
                continue;
            if (team[i] == 0 && team[j] == 0) 
                startTeam_ability += ability[i][j];
            else if (team[i] == 1 && team[j] == 1) 
                linkTeam_ability += ability[i][j];
        }
    }
    
    min_Diff = min(min_Diff, abs(startTeam_ability - linkTeam_ability));    // 팀 능력치 비교
}

void Divide_Team(int idx, int startTeam_Num)     // 인원을 팀으로 나누기
{
    if (idx == N)     // 모든 인원 다 배정했을 때
        return;    
    
    if (startTeam_Num == N/2) {     // 스타트팀원의 수 : 링크팀원의 수 = 1 : 1
        calculate_ability();
        return;
    }
     
    team[idx] = 0;    // idx가 startTeam일 때, startTeam 배정하기
    Divide_Team(idx + 1, startTeam_Num + 1);
    
    team[idx] = 1;    // idx가 startTeam 아닐 때, startTeam 배정하기
    Divide_Team(idx + 1, startTeam_Num);
}

int main() 
{
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ability[i][j];
        }
        team[i] = 1;
    }
    
    Divide_Team(0, 0);
    cout << min_Diff << "\n";
    
    return 0;
}
