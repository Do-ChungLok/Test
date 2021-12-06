#include <stdio.h>

#define TIME_MAX 1000

int main()
{
    int input_num;    // 사람의 수
    int time[TIME_MAX] = {};    // 돈을 인출하는데 걸리는 시간 
    int temp;
    int min_sum = 0;
    
    scanf("%d", &input_num);    // 사람의 수 입력
    
   for (int i = 0; i < input_num; i++){
        scanf("%d", &time[i]);       
    }
    
    for (int i = 1; i < input_num; i++){    // 최소 합을 구하기 위해 오름차순 정렬
        for (int j = 0; j < input_num; j++){
            if (time[i] < time[j]){
                temp = time[j];
                time[j] = time[i];
                time[i] = temp;
            }
        }
    }
    
    for (int i = 0; i < input_num; i++)    // 시간 합의 최소값
    {
        for (int j = 0; j < i+1; j++){
            min_sum = min_sum + time[j];
        }
    }
    
    printf("%d", min_sum);
    
    
    
}
