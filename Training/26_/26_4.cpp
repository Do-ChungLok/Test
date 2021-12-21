#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdio.h>

using namespace std;

#define MAX 4000000

int input, sum;    // 자연수 input, 소수의 합 sum
int check[MAX+1]; // 0을 소수로 표기  

vector<int> p_sum;
vector<int> prime_num;

int main()
{
	scanf("%d", &input);    // 자연수 입력
	p_sum.push_back(0);
	 	
	for(int i = 2; i < sqrt(MAX); i++){    // 에라토스테네스의 체 알고리즘으로 소수 선별
		for(int j = 2*i; j <= MAX; j += i)
			check[j] = 1; // 소수가 아님을 표시  
	}
	 	
	for(int i = 2; i <= MAX; i++) {
		if(check[i] == 0){ // 소수인것을 선별
			sum += i;
			p_sum.push_back(sum);    // 소수의 합을 벡터에 삽입
		}
	}
	

	int result, left, right; // 투포인터
	result = 0;
	left = 0;
	right = 0;	
	
	while(left <= right && right < p_sum.size()){
        
		if (p_sum[right] - p_sum[left] > input){
			left++;    // 왼쪽으로 1칸 이동 
		}
		else if (p_sum[right] - p_sum[left] < input){
			right++;    // 오른쪽으로 1칸 이동 
		}
		else if (p_sum[right] - p_sum[left] == input){
			result++;      // 결과 카운트 ++
			right++;    // 오른쪽으로 1칸 이동  
		}
	}
    
	printf("%d", result);	// 출력 
	
}
