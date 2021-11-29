#include <stdio.h>
#include <stdlib.h>

typedef struct {     // x, y 구조체 선언
    int x; 
    int y; 
} coordinate; 

int compare(const void* coord1, const void* coord2){
    coordinate* num1 = (coordinate*)coord1;
    coordinate* num2 = (coordinate*)coord2;
    
    if(num1->y > num2->y){
        return 1;
    }
    
    else if(num1->y < num2->y){
        return -1;
    }
    
    else if(num1->y == num2->y){    // 좌표 y가 같은 경우   
        if(num1->x < num2->x)    // 좌표 x기준으로 오름차순 정렬
            return -1;
        else
            return 1;
    }       
    return 0;
}

int main(void) { 
    int N; 
    scanf("%d", &N);
    
    coordinate* list;
    list = (coordinate*)malloc(N * sizeof(coordinate));
    
    for (int i = 0; i < N; i++){ 
        scanf("%d %d", &list[i].x, &list[i].y);     // x, y 좌표 입력
    }
    
    qsort(list, N, sizeof(list[0]), compare);     // 정렬
    
    for (int i = 0; i < N; i++){
        printf("%d %d\n", list[i].x, list[i].y); 
    }
    return 0; 
}

