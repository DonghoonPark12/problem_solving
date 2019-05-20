typedef struct node
{
	char data;
	node *next;
}Node;

void add_node(Node *prev, char val)
{
	Node *p_new = (Node *)malloc(sizeof(Node));
	
	p_new->data = val;
	/* 이전 노드가 가리키던 것을 새로운 노드도 가리키게 한 후 */
	p_new->link = prev->link;
	/* 이전 노드가 (방향을 바꿔)새로운 노드를 가리키게 한다. */
	prev->link = new;
}

/* 뒤로 탐색은 어렵지만, 앞으로 탐색은 가능하다 */
void	delete_node(Node *prev)//(Node *cur, Node *prev)
{
	/* 이전 노드가 가리키는 것을 Target으로 한다 */
	Node *target = prev->link; //삭제할 노드를 가리키게 한다. 
	
	/*현재 노드가 가리키는 것을 이전 노드도 가리키게 한다. */
	prev->link = target->link;
	
	free(target);//free 할때는 노드 주소값(노드 포인터)만 넘기면 된다. 
}
	
	
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

/* Insertion Sort */
void InsertionSort(int data[], int size)
{
	int i;

	Node *head_unsorted = (Node *)malloc(sizeof(Node));
	Node *head_sorted = (Node *)malloc(sizeof(Node));
	Node *node = head_unsorted;
	Node *prev, *curr;

	head_unsorted->link = NULL;
	head_sorted = NULL;


}


	

		
		