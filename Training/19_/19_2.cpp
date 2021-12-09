#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int card_num; // 카드의 개수
    
    scanf("%d", &card_num);
    
    queue<int> q;
    
    for (int i = 1; i <= card_num; i++){
        q.push(i);           // 1 ~ N 까지 카드를 큐에 넣어줌
    }
    
    while (q.size() > 1){    // 카드가 한 장 남을때까지 반복
        
        q.pop();             // 제일 위에 있는 카드 삭제
        
        int front_data = q.front(); // 제일 위에 있는 카드를 버린 이후 제일 위에 있는 카드를 front_data에 저장
        q.push(front_data);  // 제일 위에 있는 카드를 제일 밑으로 옮김
        
        q.pop();             // 제일 위에 있는 카드를 제일 밑으로 옮겼고, 이 카드는 필요가 없으니 삭제
    }
    
    printf("%d", q.front());    // 마지막 남은 1장의 카드 출력
    
    return 0;
}
