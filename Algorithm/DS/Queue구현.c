/* 배열로 큐 작성하기, 원형 큐 */
#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

#define QUEUE_CAPACITY 8

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;//원소가 생기면 tail이 0 이 된다. head와 동일. head와 Tail이 동일할때 원소 한개 존재. 하나도 없을 때 Head 은 Tail 보다 한칸 앞선다. 
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
		else if (number == 0)// ;가 있으면 else if 문은 실행문이 없는 의미 없는 문이 된다. 
		{
			r = dequeue();
			if( r != 0) printf("[%d]\n", r);//#1 이 방법은 좀 구리다. 
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
		return 0; //#1 이때 r=0가 되는데 [0]이 굳이 출력될 필요는 없다. 어떻해야 할까.
	}

	r = queue[head];
	head = (head + 1) % QUEUE_CAPACITY;
	queue_size--;
	return r;
}