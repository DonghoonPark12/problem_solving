/* �迭�� ť �ۼ��ϱ�, ���� ť */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 100

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;//���Ұ� ����� tail�� 0 �� �ȴ�. head�� ����. head�� Tail�� �����Ҷ� ���� �Ѱ� ����. �ϳ��� ���� �� Head �� Tail ���� ��ĭ �ռ���. 
int queue_size = 0;

void enqueue(int n);
int dequeue();

int main()
{
	int T;
	int number, r = 0;
	int n;//������ ����
	int m;//�̰��� �ϴ� ������ ��ġ
	int test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		scanf(" %d %d", &n, &m);
		//int *arr = (int *)malloc(sizeof(int) *n);
		for (int i = 0; i < n; i++) scanf("%d", &queue[i]);

		//arr[m]�� �̰��� �ϴ� ��, 3
		while (queue[0] != n)
		{
			if (pri(queue[]) == 1)//�ٸ� �켱 ���� ū�� �����Ѵٸ� �ڷ� �ѱ��.
			{
				enqueue(queue[0]);
				dequeue();
			}
			else
			{
				if (queue[0] == n) break; // �ٸ� �켱 ���� ū�� �ڿ� ���� ���� �ʰ�, ù��° ���ҿ� �ִٸ� 
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
		return 0; //#1 �̶� r=0�� �Ǵµ� [0]�� ���� ��µ� �ʿ�� ����. ��ؾ� �ұ�.
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