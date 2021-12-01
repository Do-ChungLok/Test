#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX_SIZE 9
#define SMALL_MAX_SIZE 3

using namespace std;
 
int board[MAX_SIZE][MAX_SIZE];    // 9 X 9 스도쿠 판 선언
 
vector < pair <int,int> > coordinate;    // 좌표를 기록할 벡터
 
bool check(int num, int row, int col)   // 입력한 num 판별(Check)
{
    int x, y;
    
    
    for (int j = 0; j < MAX_SIZE; j++){
        if (num == board[row][j] || num == board[j][col])    return false;
    }     // 행과 열에 중복되는 값이 있는지 확인.
    
    // row와 col을 기준으로 인덱스 좌표(x, y)를 찾음.
    x = int(row / SMALL_MAX_SIZE) * SMALL_MAX_SIZE;    // row/3 * 3
    y = int(col / SMALL_MAX_SIZE) * SMALL_MAX_SIZE;    // col/3 * 3
    
    // 자신이 속한 3 x 3 서브배열에 중복되는 값이 있는지 확인
    for (int i = x; i < (x + SMALL_MAX_SIZE); i++){
        for (int j = y; j < (y + SMALL_MAX_SIZE); j++){
            if (num == board[i][j])  
                return false;
        }
    }
    
    return true;    // 지금까지 진행되었다면 서브배열에 중복값이 없었다 -> 'true' 리턴
}
 
void sudoku_DFS(int idx)    // 스도쿠판을 순회하며 값을 하나씩 채워나갈 dfs 함수, 매개변수 idx = 채워야하는 좌표값들의 순서.
{    
    if ((size_t)idx == coordinate.size()){    // idx == coordinate.size() -> 스도쿠판을 다 채웠다.
        for (int i = 0; i < MAX_SIZE; i++){       // 스도쿠판을 다 채웠으니 ----> 결과 출력 후 종료
            for (int j = 0; j < MAX_SIZE; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
        
        return;
    }
    
    // 구하고자 하는 좌표값을 받는다.
    int row = coordinate[idx].first, col = coordinate[idx].second;
    
    // 좌표에 1부터 9까지 차례로 넣어본다.
    for (int i = 1; i < 10; i++){
        if (check(i,row,col)){       // 좌표에 i를 넣기전에 값을 넣을 수 있는지 check함수를 통해 확인한다.
            board[row][col] = i;    // 넣어도 되면 좌표에 i를 넣는다.
            sudoku_DFS(idx+1);      // 해당 좌표는 값을 넣었으니 다음 빈칸(값이 0인 좌표)로 이동한다.
        }
    }
    
    board[row][col] = 0;
    
    return;
}
 
int main()
{
    
    for (int i = 0; i < MAX_SIZE; i++){
        for (int j = 0; j < MAX_SIZE; j++){
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < MAX_SIZE; i++){
        for (int j = 0; j < MAX_SIZE; j++)
            if (board[i][j]==0)  
                coordinate.push_back(make_pair(i,j));
    }
    
    sudoku_DFS(0);    // sudoku_DFS 함수 호출
    
    return 0;
}

