#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node *next;
}Node;

void add_node(Node *prev, char val) {
	Node *p_new = (Node *)malloc(sizeof(Node));
	p_new->data = val;
	p_new->next = prev->next; // 이전 노드가 가리키던 것을 새로운 노드도 가리키게 한 후 
	prev->next = p_new; // 이전 노드가 (방향을 바꿔)새로운 노드를 가리키게 한다. 
}

void delete_node(Node *prev) {
	Node *target = prev->next;
	prev->next = target->next;
	printf("%d", target->data);
	free(target);
}

int main(void)
{
	int N,M; 
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d %d", &N,&M);
	/////////////////////////////////////////////////////////////////////////////////////////////////
	Node *head=(Node *)malloc(sizeof(Node));
	head->next = NULL;
	Node *node = head;

	for (int i = 0; i < N; i++) { //10개의 노드 생성
		add_node(node, i + 1);
		node = node->next;
	}
	node->next = head->next; //맨 마지막은 다시 처음을 가리키게 한다. 

	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	Node *node = head;

	for (int i = 0; i < N; i++) {
		add_node(node, i + 1);
		node = node->next;
	}
	node->next = head->next;
	printf("<");
	while (N--) //7번만 출력
	{
		for (int i = 0; i < 2; i++)
		{
			node = node->next;
		}
		delete_node(node);

		if (N>0)
			printf(", ");
	}
	printf(">\n");

	/////////////////////////////////////////////////////////////////////////////////////////////////


	return 0;

}