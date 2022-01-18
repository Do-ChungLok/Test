#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

#define ARRAY_SIZE_MAX 500001

using namespace std;

int input_num;    // 정수 개수
int input;    // 입력 정수
int arr[ARRAY_SIZE_MAX];
int tmp[ARRAY_SIZE_MAX];
long long result = 0;

// 버블 소트의 swap 개수 = merge 소트에서 merge과정에서의 교차점 개수
void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	int k = start;
	int cnt = 0;

	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right]) {    // 왼쪽 배열의 값이 tmp에 정렬될 때마다 cnt 더해줌
			tmp[k++] = arr[left++];
			result += (long long)cnt;
		}
        
		else {        // 오른쪽 배열의 값이 tmp에 정렬될 때마다 cnt++
			tmp[k++] = arr[right++];
			cnt++;
		}
	}

	if (left > mid) {    // 남은 부분 중 오른쪽 배열의 값이 정렬될 때
		int s = right;
		while (s <= end) {
			tmp[k++] = arr[s++];
			cnt++;
		}
	}
  
	else {    // 남은 부분 중 왼쪽 배열의 값이 정렬될 때
		int s = left;
		while (s <= mid) {
			tmp[k++] = arr[s++];
			result += (long long)cnt;
		}
	}

	for (int t = start; t <= end; t++)
		arr[t] = tmp[t];
}

void mergesort(int start, int end)    // 정렬
{
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(start, mid);
		mergesort(mid + 1, end);
		merge(start, end);
	}
}

int main()
{
    scanf("%d", &input_num);    // 정수 개수
	for (int i = 0; i < input_num; i++) {

        scanf("%d", &input);    // 정수 입력
		arr[i] = input;    // 배열에 저장
	}
    
	mergesort(0, input_num - 1);
    
    cout << result;    // 결과 출력
    
    return 0;
}
