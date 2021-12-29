#include <stdio.h>

int main()
{
    int case_num;    // 테스트 케이스 수
    int country_num;     // 국가의 수
    int kinds_plane;    // 비행기의 종류
    int plane1, plane2; // 왕복하는 비행기
    
    
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    for (int i = 0; i < case_num; i++){
        
        scanf("%d %d", &country_num, &kinds_plane);
        
        for (int j = 0; j < kinds_plane; j++){
            scanf("%d %d", &plane1, &plane2);
        }
        
        printf("%d\n", country_num - 1);    // n개의 정점을 가지는 그래프의 최소 간선수는 n-1개
    }
    
    return 0;
}
