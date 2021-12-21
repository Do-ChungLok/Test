#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int stuff_num, max_weight;    // 물건의 개수, 넣을 수 있는 최대 무게
int stuff_weight;

vector<int> item;
vector<int> front_sum;    // 반으로 쪼갠 후 앞에서 부터의 합 벡터
vector<int> back_sum;     // 반으로 쪼갠 후 뒤에서 부터의 합 벡터

int result = 0;

void front_to_sum(int index, int sum)
{
	if (sum > max_weight)    // 합이 max_weight를 넘어갈때
		return;

	if (index == stuff_num / 2){    // 앞쪽 끝까지 체크 했을때
		front_sum.push_back(sum);
		return;
	}

	front_to_sum(index + 1, sum + item[index]);    // index구간 물건을 고를때

	front_to_sum(index + 1, sum);    // index구간 물건을 고르지 않을때
}

void back_to_sum(int index, int sum)
{
	if (sum > max_weight)    // 합이 max_weight를 넘어갈때
		return;

	if (index == stuff_num){    // 뒤쪽 끝까지 체크 했을때
		back_sum.push_back(sum);
		return;
	}

	back_to_sum(index + 1, sum + item[index]);    // index구간 물건을 고를때

	back_to_sum(index + 1, sum);    // index구간 물건을 고르지 않을때
}

int main()
{

	scanf("%d %d", &stuff_num, &max_weight);    // 물건의 개수, 최대 무게 입력
    
	for (int i = 0; i < stuff_num; i++){
		scanf("%d", &stuff_weight);    // 물건의 무게 입력
		item.push_back(stuff_weight);
	}

	front_to_sum(0, 0);    // 앞쪽 물건들로 만들수 있는 모든 합을 구한다

	back_to_sum(stuff_num / 2, 0);    // 뒤쪽 물건들로 만들수 있는 모든 합을 구한다

	sort(front_sum.begin(), front_sum.end());    // 오름차순 정렬 
	sort(back_sum.begin(), back_sum.end());      // 오름차순 정렬

	int left = 0;    // 투포인터를 이용
	int right = back_sum.size() - 1;
    
	while (1){
		if (left == front_sum.size()) // front_sum을 모두 체크 했을때
			break;
		if (right == -1) // back_sum을 모두 체크 했을때
			break;

		if (front_sum[left] + back_sum[right] <= max_weight){
			result += (right + 1); // front_sum[left]와 합쳐서 합이 max_weight 이하가 되는것은 back_sum의 right 인덱스 이하의 것들 모두 가능
			left++; // 다음에 확인할 front_sum의 인덱스
		}

		else{
			right--;
		}
	}
    
    printf("%d\n", result);
	
	return 0;
}
