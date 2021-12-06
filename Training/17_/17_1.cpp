#include <stdio.h>

int main()
{
    int input_num1, input_num2;    // 입력 숫자 1, 2

    while(1){
        scanf("%d %d", &input_num1, &input_num2);
        
        if (input_num1 != 0 && input_num2 != 0){    // 입력 숫자 1을 입력 숫자 2로 나누어서 나머지가 0이면 입력 숫자 1은 입력 숫자 2의 약수이다.
            if (input_num2 % input_num1 == 0){
                printf("factor\n");
            }
        
            else if (input_num1 % input_num2 == 0){    // 입력 숫자 2을 입력 숫자 1로 나누어서 나머지가 0이면 입력 숫자 2은 입력 숫자 1의 배수이다.
                printf("multiple\n");
            }
            
            else{
                printf("neither\n");    // 두 조건에 해당되지 않는 케이스는 아무것도 아니다.
            }  
        }
        
        else    // 입력 숫자 1, 2가 0일때 빠져 나온다.
            break;

    }
    return 0;
    
}
