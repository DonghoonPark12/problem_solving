#include <cstdio> 
/*
1,2. 문제 이해, 재정의
숫자열에서 특정 사이클을 가지며 숫자가 감소를 하며 원소가 0보다 작을 경우 정지.
3. 어떻게 해결할지 계획
리스트로 풀어 보고자(물론 더 쉬운 방법이 있겠지만) 노드를 정의하고, 1~5 감소 및 노드 삭제, 삽입을 반복
4. 계획 검증
더 나은 방법이 존재할 것이다. 내 방법은 문제를 그대로 구현
5. 구현
6. 회귀, 개선 방법
- tail의 경우 노드를 생성하고 이동해야 한다는 것을 알았으며
- 순서로 따지면 (1) tail->next 노드 생성 (2) tail 포인터 이동 (3) 데이터 삽입 이다.
- 생성/이동/삽입
*/
typedef struct node {
	int data;
	node *next;
}Node;

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int t = 0; t < 10; t++) {
		scanf("%d ", &n);
		int data_;//리스트에 저장될 데이터 저장 변수 
		Node *head = new Node;
		//Node *tail = new Node;
		Node *tail = head;
		for (int i = 0; i < 8; i++) {
			tail->next = new Node;
			tail = tail->next;
			scanf("%d ", &data_);
			tail->data = data_;
		}
		int loss = 1;
		while (tail->data > 0) {
			Node *tmp = head->next;
			head->next->data -= loss;
			head->next = head->next->next;//노드 제거

			//tail = tail->next; //포인터를 이동시킨 다음에
			//tail = new Node; //New 노드를 만들면 안된다.
			tail->next = new Node;//먼저 노드를 생성하고
			tail = tail->next;//포인터를 이동한다. 

			tail->data = tmp->data;//뒤로 이동
			if (loss == 5)
				loss -= 4;
			else
				loss += 1;
			delete tmp;
		}
		if (tail->data < 0) tail->data = 0;
		printf("#%d ", n);
		Node *prt = head->next;
		//while (prt != NULL) {
		while (prt != tail->next) {
			printf("%d ", prt->data);
			prt = prt->next;
		}
		delete head;
		printf("\n");
	}
	return 0;
}