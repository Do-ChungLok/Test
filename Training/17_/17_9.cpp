
#include <stdio.h>

#define ARRAY_SIZE_MAX 1000

double factorial(int number)    // 이항계수를 구하기 위해 사용되는 팩토리얼 함수
{
    double result = 1;
    for (int i =1; i <= number; i++){
        result = result * i;
    }
    
    return result;
}

int main()
{
    double case_num;    // 테스트 케이스 개수
    double west_site[ARRAY_SIZE_MAX], east_site[ARRAY_SIZE_MAX]; // 서쪽, 동쪽 사이트 개수
    double denominator;          // 이항계수를 구하는데 사용되는 분자 변수
    double numerator;            // 이항계수를 구하는데 사용되는 분모 변수
    double binomial_coefficient[ARRAY_SIZE_MAX]; // 이항계수 변수 -> nCk = n! / k! * (n - k)!    
  
    scanf("%lf", &case_num);    // 케이스 개수 입력
    for (int i = 0; i < case_num; i++){
        scanf("%lf %lf", &west_site[i], &east_site[i]);
    }
    
    for (int j = 0; j < case_num; j++){
        denominator = factorial(east_site[j]); // 이항계수의 분자 -> n! --- n : east_site[j] , k : west_site[j]
        numerator = factorial(west_site[j]) * factorial(east_site[j] - west_site[j]); // 이항계수의 분모 -> k! * (n - k)!
        binomial_coefficient[j] = denominator / numerator; // 이항계수 변수
    
        printf("%.lf\n", binomial_coefficient[j]);
    }

}
