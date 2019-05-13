/*
  G = (V,E) 
  V(G) = {A, B, C, D}
  E(G) = {a, b, c, d, e, f, g} Ȥ�� E(G) = {(A,C), (A,B), (A,D), (C,D), (B,D)}
*/
/* adjacency matrix to adjacency list */
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 55
typedef struct node{
	struct node *next;
	int value;
}node;

void add(node **head, int value)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->value = value;

	node *tail = *head;

	if (!(*head))//
	{
		new_node->next = NULL;//
		(*head) = new_node;// head�� �Ͽ��� new_node�� ����Ű�� �Ѵ�.
	}
	else
	{
		//(*head)->next = new_node;//
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;

}

int main()
{
	int adj_matrix[MAX][MAX] ;
	int n;

	node *head[MAX];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) //��� ǥ���� �״�� ������ ���ؼ� 1���� ����
	{
		head[i] = NULL;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &adj_matrix[i][j]); //���� ��� �Է�

			if (adj_matrix[i][j])
			{
				add(&head[i], j); //�ּҿ� �� ���Ҹ� �Ѱ��ش�. ex) &head[1], 2�� 4�� �Ѱ��ش�.
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		node *current_node = head[i];

		printf("%d: ", i);

		while (current_node)
		{
			printf("%d ", current_node->value); // ���� ����Ʈ�� ǥ��
			current_node = current_node->next;
		}
		printf("\n");
	}
	return 0;
}