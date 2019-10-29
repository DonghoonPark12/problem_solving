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
	p_new->next = prev->next; // ���� ��尡 ����Ű�� ���� ���ο� ��嵵 ����Ű�� �� �� 
	prev->next = p_new; // ���� ��尡 (������ �ٲ�)���ο� ��带 ����Ű�� �Ѵ�. 
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

	for (int i = 0; i < N; i++) { //10���� ��� ����
		add_node(node, i + 1);
		node = node->next;
	}
	node->next = head->next; //�� �������� �ٽ� ó���� ����Ű�� �Ѵ�. 

	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	Node *node = head;

	for (int i = 0; i < N; i++) {
		add_node(node, i + 1);
		node = node->next;
	}
	node->next = head->next;
	printf("<");
	while (N--) //7���� ���
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