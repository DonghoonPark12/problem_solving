/* �迭�� ť �ۼ��ϱ�, ���� ť */
#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

#define QUEUE_CAPACITY 8

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;//���Ұ� ����� tail�� 0 �� �ȴ�. head�� ����. head�� Tail�� �����Ҷ� ���� �Ѱ� ����. �ϳ��� ���� �� Head �� Tail ���� ��ĭ �ռ���. 
int queue_size = 0;

void enqueue(int n);
int dequeue();

int main()
{
	int number, r=0;

	do{
		printf("Input number: ");
		scanf("%d", &number);

		if (number > 0)
		{
			enqueue(number);
		}
		else if (number == 0)// ;�� ������ else if ���� ���๮�� ���� �ǹ� ���� ���� �ȴ�. 
		{
			r = dequeue();
			if( r != 0) printf("[%d]\n", r);//#1 �� ����� �� ������. 
		}
	} while (number >= 0);

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