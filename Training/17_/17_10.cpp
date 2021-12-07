#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE_MAX 31
#define STR_SIZE_MAX 21

int main()
{

    int case_num;         // 테스트 케이스 개수
    scanf("%d", &case_num);
    
    for (int i = 0; i < case_num; i++){
        
        int result_num = 1;   // 다른 의상 조합의 수
        int clothes_num;      // 총 의상 개수
        int clothes_kind_num = 0; // 의상 종류 개수
        int clothes_kinds_num_list[ARRAY_SIZE_MAX];    // 의상 종류별 의상 개수가 저장될 배열
    
        // 의상 종류 리스트, 의상, 의상 종류
        char clothes_kinds_list[ARRAY_SIZE_MAX][STR_SIZE_MAX], clothes_name[STR_SIZE_MAX], 
        clothes_kind[STR_SIZE_MAX];
        scanf("\n%d", &clothes_num);
        
        for (int j = 0; j < clothes_num; j++){
            scanf("\n%s %s", clothes_name, clothes_kind);
            
            int k;
            
            for (k = 0; k < clothes_kind_num; k++){
                if (strcmp(clothes_kinds_list[k], clothes_kind) == 0){    // 이미 등장했던 종류와 중복이면 
                    clothes_kinds_num_list[k]++;                          // 해당 종류의 의상 개수 카운트
                    break;
                }
            } 
            
            if (k == clothes_kind_num){        // 새로운 종류의 의상이 등장한다면
                strcpy(clothes_kinds_list[clothes_kind_num], clothes_kind);    // 해당 종류의 의상 추가
                clothes_kinds_num_list[clothes_kind_num++] = 1;                // 해당 종류 의상 개수 1개
            }
        }
    
        for (int i = 0; i < clothes_kind_num; i++){
            result_num *= (clothes_kinds_num_list[i] + 1);    //종류별 의상 개수를 모두 곱함 
        }
         printf("%d\n", result_num - 1);   // 아무것도 안 입고 다닌 경우는 '-1'을 해서 제외
        
    } 
    return 0;
}
