#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int people_num; // 사람의 수
    int delete_people;    // 제거되는 사람 
    
    scanf("%d %d", &people_num, &delete_people);
    
    queue<int> q;
    
    for (int i = 1; i <= people_num; i++){
        q.push(i);           // 1 ~ 사람수 까지 카드를 큐에 넣어줌
    }
    
    printf("<");
    while (!q.empty()){    // 카드가 한 장 남을때까지 반복
        
        for (int j = 0; j < delete_people - 1; j++){ // delete_people - 1 까지의 값을 맨 뒤로 넣음
            int front_data = q.front(); // 제일 앞에 있는 사람을 front_data에 저장
            q.push(front_data);  // 제일 앞에 있는 사람을 제일 뒤로 옮김
            q.pop();             // 제일 앞에 있는 사람을 제일 뒤로 옮겼고, 이 사람은 필요가 없으니 삭제
        }
        
        printf("%d", q.front());    // 제일 앞에 있는 사람 출력
        q.pop();             // 제일 앞에 있는 사람 삭제
        
        if (!q.empty()){
            printf(", ");
        }  
    }
    printf(">\n");
    
    return 0;
}
