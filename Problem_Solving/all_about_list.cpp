#include <cstdio>
/*
연결 리스트의 세가지 종료
- 단일 연결 리스트: Single Linked list, 각 노드가 그 다음 노드를 가리킨다.
- 이중 연결 리스트: Double Linked list, 각 노드가 두개의 포인터를 가지고, 앞, 뒤 노드를 가리킨다.
- 원형 연결 리스트: Circular Linked list, 단일 연결 리스트에서 마지막 노드의 *next가 처음 노드를 가리켜 원형으로 이어진다.
- 이중 원형 연결 리스트: 이중 연결 리스트에서 마지막 노드의 *next 가 처음 노드를 가리키며, 처음 노드의 *prev가 마지막 노드를 가리킨다. 
http://huiyu.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%8F%99%EC%A0%81%ED%95%A0%EB%8B%B9%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8Linked-List-%EA%B5%AC%ED%98%84
https://stackoverflow.com/questions/392397/why-do-we-use-arrays-instead-of-other-data-structures
*/

typedef struct node
{
	int data;
	node *prev;
	node *next;
}Node;

class List {
	struct Node {
		int data;
		Node * next;
	};

	Node * head;

public:
	List() {
		head = NULL;
	}

	~List() {
		while (head != NULL) {
			Node * n = head->next;
			delete head;
			head = n;
		}
	}

	void add_node(Node *prev, char val)
	{
		//Node *p_new = (Node *)malloc(sizeof(Node));
		Node *p_new = new Node;

		p_new->data = val;
		p_new->next = prev->next; //이전 노드가 가리키던 것을 새로운 노드도 가리키게 한 후 
		prev->next = p_new; //이전 노드가 (방향을 바꿔)새로운 노드를 가리키게 한다. 
	}

	/* 뒤로 탐색은 어렵지만, 앞으로 탐색은 가능하다 */
	void delete_node(Node *prev)//(Node *cur, Node *prev)
	{
		/* 이전 노드가 가리키는 것을 Target으로 한다 */
		Node *target = prev->next; //삭제할 노드를 가리키게 한다. 
								   /*현재 노드가 가리키는 것을 이전 노드도 가리키게 한다. */
		prev->next= target->next;

		delete target;//free 할때는 노드 주소값(노드 포인터)만 넘기면 된다. 
	}

	// ...
};

/*현재노드로 부터 이전 노드를 찾는다,,, 이렇게는 안된다. */
/*
void	delete_node(Node *cur)
{
		Node *prev;
		prev->link = cur; //노드 포인터 생성 후 링크를 현재에 걸어준다??? 말이 안된다. 
		//동적 할당이 안되었다. 따라서 prev->link도 말이 안된다.
		//여기서 말한 prev가 cur노드를 가리키는 (진짜)prev노드라 할 수 없다. 
		
		prev->link = cur->link;
		
		free(cur);
}
*/

typedef struct node2
{
	char data;
	node *next, *prev;
}Node2;

void	add_node2(Node *prev, int val)
{
	/* new 노드 생성 */
	Node *new = (Node *)malloc(sizeof(Node));
	Node *p_next = prev->next;
	new->data = val;
	
	/* 이전 노드가 가리키는 것을 new노드도 가리키게 한다. (2)*/
	new->next = prev->next;
	/* new노드를 이전 노드가 가리키게 한다. (3)*/
	prev->next = new;
	
	/*new노드의 prev 링크에 cur주소를 준다 (4)*/
	new->prev = prev;
	
	/* new노드의 앞 노드의 prev링크가 new노드를 가리키게 한다. (5)*/
	new->next->prev = new;
   //p_next->prev = new;
}

void	delete_node2(Node *prev)
{
	Node *target = prev->next;
	Node *post = target->next;
	
	prev->next = target->next;//1
	post->prev = prev; //2
	
	free(target);
}


	
// http://huiyu.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%8F%99%EC%A0%81%ED%95%A0%EB%8B%B9%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8Linked-List-%EA%B5%AC%ED%98%84
		
		