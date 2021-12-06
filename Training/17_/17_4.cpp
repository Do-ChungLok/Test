#include <stdio.h>

int main()
{
    int case_num;        // 테스크 케이스 개수
    int input_num1, input_num2;       // 입력 숫자 1, 2
    int greatest_common_factor, least_common_multiple;    // 최대 공약수, 최소 공배수

    scanf("%d", &case_num);    // 테스트 케이스 개수 입력
    
    for(int i = 0; i < case_num; i++){
        scanf("%d %d", &input_num1, &input_num2);    // 입력 숫자 1, 2 입력 
            for (int i = 1; i <= input_num1 && input_num2; i++){    // for 반복문을 통해 입력 숫자1, 2 둘다 나누었을때 나머지가 0인 수중 제일 큰 수를 최대 공약수로 설정
                if (input_num1 % i == 0 && input_num2 % i == 0)
                    greatest_common_factor = i;
            }
    
            least_common_multiple = (input_num1 * input_num2) / greatest_common_factor;
            // 최소 공배수 = (입력 숫자 1 * 입력 숫자 2) / 최대 공약수
        
    printf("%d\n", least_common_multiple);     // 최소 공배수 출력
    }

    return 0;
    
}
