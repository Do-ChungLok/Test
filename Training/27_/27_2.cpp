#include <iostream>
#include <algorithm>
#include <vector>
#define ARRAY_SIZE_MAX 1001

using namespace std;

int sequence_size;    // 수열의 길이
int seq_arr[ARRAY_SIZE_MAX], length;    // 수열 저장할 배열, 길이
int max_index, tmp = 0;    // 최대값, 길이를 임시 저장할 변수
int dp[ARRAY_SIZE_MAX];    // 부분 수열의 길이를 저장할 배열

vector<int> vec;

int main()
{
	scanf("%d", &sequence_size);    // 수열의 길이 입력

	for (int i = 1; i <= sequence_size; i++){
		scanf("%d", &seq_arr[i]);    // 수열 입력
		length = 0;

		for (int j = 1; j < i; j++){
			if (seq_arr[j] < seq_arr[i])    // arr[i] 가 arr[j]보다 커야 업데이트
				length = max(dp[j], length);
		}
		dp[i] = length + 1;    // dp[j]와 length 중 긴 값에 +1 하여 dp[i] 업데이트
		
		if (tmp < length + 1){    // 최대 길이와 최대값 저장
			tmp = length + 1;     // 최대 길이
			max_index = i;        // 최대값의 인덱스
		}
	}

	for (int i = max_index; i >= 1; i--){
		if (dp[i] == tmp){
			vec.push_back(seq_arr[i]);
			tmp--;
		}
	}

	int size = vec.size();    // 가장 긴 증가하는 부분 수열의 길이
	printf("%d\n", size);     // 출력
    
	for (int i = 0; i < size; i++){	
        printf("%d ", vec.back());    // 가장 긴 증가하는 부분 수열 출력
		vec.pop_back();    // 출력한 값은 삭제
	}
    
    return 0;
}
