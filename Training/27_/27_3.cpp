#include <iostream>
#include <algorithm>
#include <vector>

#define ARRAY_SIZE_MAX 1000001

using namespace std;

int sequence_size;    // 수열의 길이
int seq_arr[ARRAY_SIZE_MAX];   // 수열 저장할 배열
int cnt;    // 수열 길이 카운트
int dp[ARRAY_SIZE_MAX];    // 부분 수열의 길이를 저장할 배열

vector<int> vec;
vector<int> result;    // 결과값 저장할 벡터

int main()
{
	scanf("%d", &sequence_size);    // 수열의 길이 입력

	for (int i = 1; i <= sequence_size; i++){
		scanf("%d", &seq_arr[i]);    // 수열 입력
    }
    
    vec.push_back(seq_arr[1]);    // 처음값을 넣음
    
    for (int i = 2; i <= sequence_size; i++){
        if (vec[cnt] < seq_arr[i]){
            vec.push_back(seq_arr[i]);
            cnt++;    // 길이 ++
            dp[i] = cnt;
        }
        
        else{    // 작은 위치를 lower_bound로 찾음
            int pos = lower_bound(vec.begin(), vec.end(), seq_arr[i]) - vec.begin();
            vec[pos] = seq_arr[i];
            dp[i] = pos;
        }
    }
    
    int LIS_size = cnt;    // cnt 값의 크기가 수열 길이
    
    for (int i = sequence_size; i >= 0; i--){    // 역순으로 연산하여 벡터에 데이터 집어넣기
        if (dp[i] == LIS_size){
            result.push_back(seq_arr[i]);
            LIS_size--;
        }
    }
    
    int size = result.size();    // 가장 긴 증가하는 부분 수열의 길이

	printf("%d\n", size);     // 출력
    
	for (int i = 0; i < size; i++){	
        printf("%d ", result.back());    // 가장 긴 증가하는 부분 수열 출력
		result.pop_back();    // 출력한 값은 삭제
	}
    
    return 0;
}
