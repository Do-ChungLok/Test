#include <stdio.h>
#define MAX_ARRAY Max-Min+1

int main()
{
    int Min, Max; // 입력받을 최소 최대 값 변수
    scanf("%d %d", &Min, &Max);
    
    int sum = 0;                            // 소수의 총합
    int arr[MAX_ARRAY];                 // 소수를 저장할 배열 
    
    for (int i = 0; i < MAX_ARRAY; i++) 
        arr[i] = 0;        // 배열을 0으로 초기화

    for (int i = Min; i < Max + 1; i++)
    {
        int check;   // 소수 판별 변수
        if (i == 1)  // 1은 소수가 아님 바로 건너 뜀
        {
            continue;
        }
        else if (i == 2) // 2는 소수
        {
            check = 1;
        }
        else // 1과 2가 아닐 때
        {
            for (int j = 2; j < i; j++)
            {
                check = 0;       //소수 판별 변수 초기화
                if (i % j == 0) //변수 i가 j로 나누었을때 나머지가 0이면 소수 x
                {
                    break;
                }
                check = 1; //소수일 경우 소수 판별 변수는 1
            }
        }

        if (check == 1)
        {
            sum += i;
            
            arr[i - Min] = i;
        
        }
    }
    for (int i = 0; i < MAX_ARRAY; i++)
    {

        if (arr[i] != 0) // 배열에 0이 아닌 수가 있을 경우를 검색
        {
            printf("%d\n%d", sum, arr[i]); // 제일 처음 0이 아닌 수가 나왔을 경우
            // 출력 후 프로그램 종료
            return 0;
        }
    }
    printf("-1"); // 소수가 없을 경우 -1 출력 후 종료
    return 0;
}
