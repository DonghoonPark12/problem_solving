/*
  G = (V,E) 
  V(G) = {A, B, C, D}
  E(G) = {a, b, c, d, e, f, g} 혹은 E(G) = {(A,C), (A,B), (A,D), (C,D), (B,D)}
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
		(*head) = new_node;// head로 하여금 new_node를 가리키게 한다.
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

	for (int i = 1; i <= n; i++) //행렬 표현을 그대로 따르기 위해서 1부터 시작
	{
		head[i] = NULL;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &adj_matrix[i][j]); //인접 행렬 입력

			if (adj_matrix[i][j])
			{
				add(&head[i], j); //주소와 열 원소를 넘겨준다. ex) &head[1], 2와 4를 넘겨준다.
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		node *current_node = head[i];

		printf("%d: ", i);

		while (current_node)
		{
			printf("%d ", current_node->value); // 인접 리스트로 표현
			current_node = current_node->next;
		}
		printf("\n");
	}
	return 0;
}