#include <stdlib.h>
#include <stdio.h>

typedef struct ioctl {
	const char *service_type; /*데이터 필드 : 하나의 문자열 저장 */
	struct ioctl *next; /*링크 필드 : 다음 노드의 주소 저장 */
}Node;

Node *head = NULL; /* 첫 번째 노드의 주소를 저장할 포인터 */

int main() {
	/* 첫번째 노드 추가 & head에 연결 */
	head = (Node *)malloc(sizeof(Node));
	head->service_type = "CALL_SERVICE";
	head->next = NULL;

	/* 두번째 노드 추가 & 첫번째 노드에 연결 */
	Node *q = (Node *)malloc(sizeof(Node));
	q->service_type = "CALL_SERVICE_RET";
	q->next = NULL;
	head->next = q;

	/* CALL_SERVICE 노드 앞에 REGISTER_SERVICE 노드 연결(새로운 첫번째 노드)*/	
	q = (Node *)malloc(sizeof(Node));
	q->service_type = "REGISTER_SERVICE";
	q->next = head;
	head = q;

	/* 세 개의 노드를 순서대로 출력 */
	Node *p = head;
	while (p!=NULL) {
		printf("%s\n", p->service_type); //p가 현재 가리키고있는 노드를 출력.
		p = p->next; //p가 다음 노드를 가리키도록 한다. (next에는 다음 노드의 주소가 담겨있음)

		/* 다음 노드가 없다면, p==NULL이 되기 때문에 반복문이 종료 */
	}

	return 0;
}










































/*
typedef struct node {
	char data;
	struct node *next;
}Node;

Node *head = NULL;

int main(){
	head = (Node*)malloc(sizeof(Node));
	
	Node *node1 = (Node*)malloc(sizeof(Node));
	head->next = node1;
	node1->data = "화";
	
	Node *node2 = (Node*)malloc(sizeof(Node));
	node1->next = node2;
	node2->data = "수";
	node2->next = NULL;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>

// 연결 리스트를 구성할 Node 구조체
struct Node {
	int data;			// 노드에 저장할 데이터
	struct Node *next;	// 현재 노드의 다음 노드 포인터
};

struct Node *pStart = NULL;	// 리스트의 첫 노드의 포인터
struct Node *pEnd = NULL;	// 리스트의 마지막 노드의 포인터

void addfront(int val)
{
	struct Node *Current;	// 리스트에 추가할 새 노드 생성
	Current = (struct Node *) malloc(sizeof(struct Node));
	Current->data = val;	// data 필드에 val 을 저장

	if(pStart == NULL) {		// 첫 번째 노드일 경우
		Current->next = NULL;	// 다음 노드가 아직 없으므로 NULL 이다.
		pStart = pEnd = Current;
	}		
	else {
		Current->next = pStart;	// 새로 추가한 노드의 다음 노드가 기존의 첫번째 노드
		pStart = Current;	// 첫 번째 노드를 이번에 새로 만든 노드로 바꿔줌
	}
}

void printlist(struct Node *Current)
{
	// Current 가 가리키는 리스트를 출력한다.
	Current = pStart;
	while (Current != NULL) {
		printf("%d\n", Current->data);
		Current = Current->next;
	}
}

int main(void)
{
	int i;
	for (i = 1; i <= 5; i++) 
		addfront(i);	// 새 노드를 만들어 리스트 앞에 추가
	printlist(pStart);
	return 0;
}
*/
