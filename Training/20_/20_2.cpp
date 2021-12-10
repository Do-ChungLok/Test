#include <iostream>
#include <string>

#define ARRAY_SIZE_MAX 65

using namespace std;

string video_arr[ARRAY_SIZE_MAX]; // 비디오 영상 데이터 배열

//배열 정보를 받아서 영상 크기 & x 좌표 & y 좌표 이렇게 3개의 값으로 사분면 모두를 체크

void check(int size, int start_X, int start_Y)     // stsrt_X : 체크를 시작할 X 위치
{                                                  // start_Y : 체크를 시작할 Y 위치
    char target = video_arr[start_X][start_Y];     // 초기값을 배열에 넣어 시작점을 만듬
    
    for(int x = start_X; x < start_X + size; x++) { 
        for(int y = start_Y; y < start_Y + size; y++) {      
            if(video_arr[x][y] != target) {     // 초기 배열값과 현재의 값이 다른 경우 분할 진행
                
                cout << '(';
                check(size/2, start_X, start_Y);                   // 왼쪽 위 (2사분면)
                check(size/2, start_X, start_Y + size/2);          // 오른쪽 위 (1사분면)
                check(size/2, start_X + size/2, start_Y);          // 왼쪽 아래 (3사분면)
                check(size/2, start_X + size/2, start_Y + size/2); // 오른쪽 아래 (4사분면)
                cout << ')';
                            
                return; 
            } 
        } 
    } 
    
    cout << target;
}


int main()
{

    int video_size;       // 비디오 영상의 크기
    cin >> video_size;    // 비디오 영상 크기 입력   
    for (int i = 0; i < video_size; i++){        
            cin >> video_arr[i];  // 비디오 영상 데이터 배열 입력                        
    }
    
    check(video_size, 0, 0);    // 비디오 영상의 크기, 0, 0 에서 시작
    
    return 0;
}
