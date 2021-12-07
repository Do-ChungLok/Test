#include <stdio.h>

#define RADIUS_SIZE_MAX 1000

// 최대 공약수 구하는 함수 : gcf -> (greatest_common_factor)
int gcf(int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return num2;
    }
    
    return gcf(num2, num1 % num2);
}

int main()
{
    int ring_num;    // 링의 개수 변수
    int radius[RADIUS_SIZE_MAX];      // 반지름 변수 들어갈 배열
    int gcf_radius;    // 반지름들의 최대 공약수
    
    scanf("%d", &ring_num);    // 링의 개수 입력
    
    for (int i = 0; i < ring_num; i++){
        scanf("%d", &radius[i]);    // 반지름 입력              
    }
    
    for (int j = 1; j < ring_num; j++){
        gcf_radius = gcf(radius[0], radius[j]);     // 첫 번째링과 나머지 링들의 최대 공약수를 저장할 변수
        printf("%d/%d\n", radius[0] / gcf_radius, radius[j] / gcf_radius);
    }   
    
    return 0;
}
