#include <stdio.h>

int	main(void)
{
	int	T;	// 테스트 케이스 횟수
	int	x, y;	// x: 시작 위치, y: 끝 위치. (0 <= x < y < 2^31)
	int	move_count;	// 이동 횟수
	int	remain_space;	// 남은 거리
	int	move;	// 이동 거리

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &x, &y);
		move_count = 0;
		remain_space = y - x;
		move = 1;
		while (remain_space > 0)
		{
			if (remain_space < move)
				move_count -= 1;
			remain_space -= (move * 2);
			move_count += 2;
			if (remain_space <= 0)
			{
				if (remain_space == -(move))
					move_count -= 1;
				break ;
			}
			move++;
		}
		printf("%d\n", move_count);
	}
	return (0);
}











/*
#include <stdio.h>

int main() { 
  int T; // 테스트 케이스를 입력 받기 위한 변수
  scanf("%d", &T);
  
  for(int testCase=0; testCase<T; testCase++) {
    unsigned int x, y, distance;
    int machine_count = 0;
    int move = 1;    // 이동할 수 있는 거리
    
    scanf("%u %u\n", &x, &y); // 출발점과 도착점 입력 받음
    distance = y - x;
    
    while(distance / 2 >= move) {
      distance -= move * 2;    //대칭으로 이동할 거리 계산
      machine_count += 2;      //대칭이므로 이동 횟수 2번 증가
      move++;
    }

    if (1 <= distance && distance <= move) 
      machine_count++;
    else if (move < distance) 
      machine_count += 2;
    
    printf("%d", machine_count);
  }
  
  return 0;
}
*/
