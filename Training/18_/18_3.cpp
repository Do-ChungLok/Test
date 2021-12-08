#include <stdio.h>
#include <string.h>

#define STRING_SIZE_MAX 50

int main()
{
    int case_num;    // 입력 데이터 케이스 수
    char parenthesis[STRING_SIZE_MAX]; // 입력한 괄호들을 저장할 배열
    
    scanf("%d", &case_num);
    
    for (int i = 0; i < case_num; i++){
        int count = 0;       // 괄호를 카운트 '(' : count++ , ')' : count--
        
        scanf("%s", parenthesis);    // 괄호 문자열 입력
        
        for (int j = 0; j < strlen(parenthesis); j++){
            if (parenthesis[j] == '('){    // 입력한 괄호 문자열 중 '(' 을 만나면 count++
                count++;
            }
            
            else if (parenthesis[j] == ')'){    // 입력한 괄호 문자열 중 ')' 을 만나면 count--
                count--;
            }
            
            if (count < 0){    // count 가 0보다 작으면 NO를 출력하고 빠져나옴
                printf("NO\n");
                break;
            }
        }
        
        if (count == 0){       // count가 0이라는 말은 괄호들이 짝이 맞다는 말과 같으므로 YES 출력
            printf("YES\n");
        }
        
        else if (count > 0){   // count가 0 보다 크다면 괄호들의 짝이 맞지 않으니까 NO cnffur
            printf("NO\n");
        }
    }
    
    return 0;
}
