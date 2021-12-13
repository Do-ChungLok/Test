#include <iostream>
#include <algorithm>
using namespace std;

#define ARRAY_SIZE_MAX 500001

int card_num1, card_num2;
int input_card[ARRAY_SIZE_MAX];//상근이가 가지고 있는 숫자 카드들

int Lower_Binary(int card) {    //찾으려는 값 이상의 수가 처음 나오는 위치 찾기
	int mid, low, high;
	low = 0;
	high = card_num1 - 1;

	while (low < high) {
		mid = (low + high) / 2;
		if (input_card[mid] >= card)    // 하한 : 같거나 큰 수 중에 첫 번째 위치
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int Upper_Binary(int card) {    // 찾으려는 값보다 큰 수가 처음 나오는 위치 찾기
	int mid, low, high;       // ex) -10 -10 2 3 3 6 7 10 10 10 -> '-10' 보다 큰 수 처음 나오는 위치 : 2
	low = 0;                  // '-10'이상의 수 처음 나오는 위치 : 0  ------> '2' - '0' = '2' 즉 '-10'의 갯수 '2'
	high = card_num1 - 1;

	while (low < high) {
		mid = (low + high) / 2;
		if (input_card[mid] > card)    // 상한 : 큰 수 중에 첫 번째 위치
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}


int main() {
	
	scanf("%d", &card_num1);    // 카드의 개수 입력
    
	for (int i = 0; i < card_num1; i++) {
        scanf("%d", &input_card[i]);    // 카드에 적힌 정수 입력
	}
    
	sort(input_card, input_card + card_num1);    // 입력한 정수들을 오름차순으로 정렬

    scanf("%d", &card_num2);    // 카드의 개수 입력2
    
	for (int i = 0; i < card_num2; i++) {
		int integer_card;    // 몇개 가지고 있어야하는 카드인지 구해야 하는 정수    
		
        scanf("%d", &integer_card);    // 몇개 가지고 있어야하는 카드인지 구해야 하는 정수 입력
		
		int lower = Lower_Binary(integer_card);
		int upper = Upper_Binary(integer_card);

		if (upper == card_num1 - 1 && integer_card == input_card[card_num1 - 1])
			upper++;
        
        printf("%d ", upper - lower);
		
	}
    
	return 0;
}
