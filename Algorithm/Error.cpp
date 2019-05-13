#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#define MAXNODE 100

int cnt = 0;

int count = 0; int parent = 0; int current = 0;


typedef struct Node
{
	char Data;
	node *next;
}node;


node* Remove(node* k[]);

node* DownHeap(node* h[], int cur);



int main()

{

	node *p[MAXNODE];


	int cho;

	printf("삭제할 인덱스 값을 입력해주세요 :");

	scanf("%d", &cho);

	Remove(&p[cho]);

	printf("삭제가 완료되었습니다.\n");

}




node* Remove(node* k[]) {

	node* tmp; tmp->Data = k[0]->Data;

	k[0]->Data = k[count - 1]->Data;

	count--;

	DownHeap(k, 0);

	return tmp;

}


node* DownHeap(node* h[], int cur)
{

	int LChild; int RChild;

	if (cur == count) {

		printf("더 이상 내려갈 곳이 없습니다.\n");
	}

	else

	{
		LChild = 2 * cur + 1;

		if (2 * cur + 2 <= count) {

			RChild = LChild + 1;

			if (h[RChild]->Data > h[LChild]->Data)

				LChild = RChild;

		}

		if (h[cur]->Data < h[LChild]->Data) {

			node* spc;

			spc->Data = h[cur]->Data;

			h[cur]->Data = h[LChild]->Data;

			h[LChild]->Data = spc->Data;

			DownHeap(h, LChild);

		}


	}


