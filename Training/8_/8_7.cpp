#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char arr[])    // 문자열을 뒤집는 함수
{
    int len = strlen(arr);
    for(int i=0; i<len/2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[len -i -1];
        arr[len -i -1] = temp;
    }
}

int main(){    //10^1은 2자리, 10^2은 3자리,,, 10^10000은 10001자리
    char A[10002] = {0}, B[10002] = {0}, result[10003]={0};
    int carry=0, i;    // carry : 받아올림
    
    scanf("%s%s", A, B);
    reverse(A);
    reverse(B);
    
    int len = strlen(A) > strlen(B) ? strlen(A) : strlen(B);
    
    for(i=0; i<len; i++)
    {
        // 문자형 배열에서 0의 아스키 코드만큼 뺀 후문자를 숫자로 변환 후 받아올림과 더함
        int sum = A[i] - '0' +B[i] -'0' + carry;    
        
        while(sum<0)    // A[i] or B[i]가 null인 경우 0이상이 될때까지 문자'0'의 아스키 코드 값을 더함
            sum+= '0';
        if(sum>9)    // 받아올려지는 수는 최대 1 
            carry=1;
        else        // 합이 9보다 작아 받아올려지는 수가 없으면 0
            carry=0;
        result[i] = sum % 10 + '0';    // 숫자를 다시 문자로 만들어 result[i]에 저장
    }
    
    if(carry == 1)      // 가장 큰 자릿수에서 받아올림이 발생하면 배열 마지막에 1을 추가
        result[len]='1';
    reverse(result);    // 덧셈 완료 후 역순으로 정렬하여 원하는 값으로 복원
    printf("%s", result);
    
    return 0;
}
