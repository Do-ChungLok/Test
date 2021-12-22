#include <stdio.h>

#define ARRAY_SIZE_MAX 1000001

using namespace std;

int before_num[ARRAY_SIZE_MAX];    // before_num[i] : i이전의 숫자
int dp[ARRAY_SIZE_MAX];    // dp[i] : i에서 1을 만드기까지 몇번의 연산을 했는지

int make_one(int input)
{
    dp[1] = 0;
    
	for(int i = 2; i <= input; i++) {    // 1을 빼는 연산   
		dp[i] = dp[i - 1] + 1;
		before_num[i] = i - 1;
  
		if(i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {    // 2로 나누어 떨어지고, 연산 후 연산의 길이가 짧다면  
			dp[i] = dp[i / 2] + 1;
			before_num[i] = i / 2;
		}
		
		if(i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {    // 3으로 나누어 떨어지고, 연산 후 연산의 길이가 짧다면
			dp[i] = dp[i / 3] + 1;
			before_num[i] = i / 3;
		} 
	}     
    
   return dp[input];
}

int main()
{
    int input;    // 입력할 정수
    int result;    // 결과값
    scanf("%d", &input);    // 정수 입력
    
    result = make_one(input);
    printf("%d\n",  result);
    
    while(1){
        printf("%d ", input);    // 1로 만드는 방법의 수 출력
        input = before_num[input];    
        
        if (input == 0){
            break;
        }
    }
    
    return 0;
      
}
