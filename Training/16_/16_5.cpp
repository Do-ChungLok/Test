#include <stdio.h>

#define DISTANCE_OF_CITIES 100000

int main()
{
    int num_of_city;                     // 도시의 수
    int distance[DISTANCE_OF_CITIES];    // 거리를 배열에 저장
    int each_price, min_price;           // 해당 도시의 리터당 가격, 최저가
    long long result_price = 0;          // 최저 가격의 합
    
    
    scanf("%d", &num_of_city);           // 도시의 수 입력
    
    for (int i = 0; i < num_of_city - 1; i++){    
        scanf("%d", &distance[i]);       // 도시의 거리 입력
    }
    
    for (int j =0; j < num_of_city - 1; j++){
        scanf("%d", &each_price);        // 해당 도시의 리터당 가격 입력
        
        if (j == 0 || each_price < min_price){    // 해당 도시의 리터당 가격 < 최저가
            min_price = each_price;               // 최저가에 해당 도시의 리터당 가격으로 갱신
        }

        result_price += (long) min_price * distance[j];    // 최저 가격의 합 = 최저가 * 거리 
    }
    
    printf("%lld", result_price);
    
    return 0;
    
}
