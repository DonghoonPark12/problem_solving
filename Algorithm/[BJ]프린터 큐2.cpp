/* 배열로 큐 작성하기, 원형 큐 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 100

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;//원소가 생기면 tail이 0 이 된다. head와 동일. head와 Tail이 동일할때 원소 한개 존재. 하나도 없을 때 Head 은 Tail 보다 한칸 앞선다. 
int queue_size = 0;

void enqueue(int n);
int dequeue();

int main()
{
	int T;
	int number, r = 0;
	int n;//수열의 갯수
	int m;//뽑고자 하는 원소의 위치
	int test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		scanf(" %d %d", &n, &m);
		//int *arr = (int *)malloc(sizeof(int) *n);
		for (int i = 0; i < n; i++) scanf("%d", &queue[i]);

		//arr[m]는 뽑고자 하는 값, 3
		while (queue[0] != n)
		{
			if (pri(queue[]) == 1)//다른 우선 순위 큰게 존재한다면 뒤로 넘긴다.
			{
				enqueue(queue[0]);
				dequeue();
			}
			else
			{
				if (queue[0] == n) break; // 다른 우선 순위 큰게 뒤에 존재 하지 않고, 첫번째 원소에 있다면 
				dequeue();
				Answer++;
			}
		}
		printf("%d", Answer);
	}
	return 0;
}

void enqueue(int n)
{
	if (queue_size == QUEUE_CAPACITY)
	{
		printf("queue is full!!\n");
		return;
	}

	tail = (tail + 1) % QUEUE_CAPACITY;
	queue[tail] = n;
	queue_size++;

	return;
}

int dequeue()
{
	int r = 0;

	if (queue_size == 0)
	{
		printf("queue is emtpy!!\n");
		return 0; //#1 이때 r=0가 되는데 [0]이 굳이 출력될 필요는 없다. 어떻해야 할까.
	}

	r = queue[head];
	head = (head + 1) % QUEUE_CAPACITY;
	queue_size--;
	return r;
}

int pri(int arr)
{
	for (int i = 0; i < n; i++)
	{

	}
}