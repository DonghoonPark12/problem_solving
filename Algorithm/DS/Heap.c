#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 5005

int heap[MAX];

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int n;

	scanf("%d", &n);
/*
We create a Max Heap to sort the elements in ascending order : 오름차순으로 정렬하기 위해서 Map Heap을 먼저 구성한다.

Once Heap is created we swap the root node with the last node and delete the last node
from the heap : 힙이 만들어지면 root 노드와 마지막 노드를 바꾸고, 마지막 노드를 heap에서 제거한다.

https://www.youtube.com/watch?v=MtQL_ll5KhQ

*/	

/****************배열에 힙 원소 삽입 : Max heap ******************/	
	for (int i = 1; i <= n; i++)
	{
		int m;

		scanf("%d", &m);
		heap[i] = m;

		for (int j = i; j > 1; j = j / 2)
		{
			if (heap[j] > heap[j / 2])
				swap(&heap[j], &heap[j / 2]);
		}
	}

/****************오름차순 정렬*******************/	
	for (int i = 1; i <= n; i++)
	{

		swap(&heap[1], &heap[n - i + 1]);

		for (int j = 1;;)
		{

			int k = j * 2;

			if (k > n - i) break;

			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++;

			if (heap[j] < heap[k])
			{
				swap(&heap[j], &heap[k]);
				j = k;
			}

			else break;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", heap[i]);

		return 0;
}

