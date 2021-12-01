// i = 4 : 2 = 1 + 1
// i = 5 : 3 = 2 + 1
// i = 6 : 4 = 2 + 2 ...---> arr[i] = arr[i - 2] + arr[i - 3];

#include <stdio.h>
#define SIZE_MAX 101

int main()
{
    int i, T, input_num;    
    long long arr[SIZE_MAX] = {0, 1, 1, 1};    // i=1일때 1, i=2일때 1, i=3일때 1, i=4일때 ...
   
    for (i = 4; i< SIZE_MAX; i++){
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    
    scanf("%d", &T);    // 테스트 케이스 개수 입력 
    
    for(i = 0; i < T; i++){
        scanf("%d", &input_num);
        printf("%lld\n", arr[input_num]);
    }

    return 0;
}
