#include <stdio.h>

#define SIZE_MAX 1000000

int Min(int num1, int num2)
{
    if (num1 < num2)
        return num1; 
    else
        return num2;
}

int main()
{
    int MAKE_ONE_ARR[SIZE_MAX];
    int input_num;
    scanf("%d", &input_num);
    
    MAKE_ONE_ARR[0] = 0;
    MAKE_ONE_ARR[1] = 0;    // 1일때는 아무 연산 안 해도 '1' 즉 --> '0'
    
    for (int i = 2; i <= input_num; i++){
        
        MAKE_ONE_ARR[i] = MAKE_ONE_ARR[i - 1] +1;    // 1을 빼는경우 
        
        if (i % 2 == 0){        // 2로 나누어지는 경우 -> 1을빼는 경우와 2로 나눈경우에서 최소값
            MAKE_ONE_ARR[i] = Min(MAKE_ONE_ARR[i], MAKE_ONE_ARR[i / 2] + 1);
        }
        
        if (i % 3 == 0){        // 3으로 나누어지는 경우 -> 1을빼는 경우와 3으로 나눈경우에서 최소값
            MAKE_ONE_ARR[i] = Min(MAKE_ONE_ARR[i], MAKE_ONE_ARR[i / 3] + 1);
        }
        
    }
    
    printf("%d", MAKE_ONE_ARR[input_num]);
    return 0;
    
}
