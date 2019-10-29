#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

typedef struct node
{
	char data;
	node *next;
}Node;

/*
void add_node(Node *prev, char val)
{
	Node *p_new = (Node *)malloc(sizeof(Node));

	p_new->data = val;
	/* 이전 노드가 가리키던 것을 새로운 노드도 가리키게 한 후 */
//	p_new->next = prev->next;
	/* 이전 노드가 (방향을 바꿔)새로운 노드를 가리키게 한다. */
//	prev->next = p_new;
//}

void add_node(Node *prev, Node *p_new)
{
	p_new->next = prev->next;

	prev->next = p_new;
}

/* 뒤로 탐색은 어렵지만, 앞으로 탐색은 가능하다 */
Node * delete_node(Node *prev)//(Node *cur, Node *prev)
{
	/* 이전 노드가 가리키는 것을 Target으로 한다 */
	Node *target = prev->next; //삭제할 노드를 가리키게 한다. 

							   /*현재 노드가 가리키는 것을 이전 노드도 가리키게 한다. */
	prev->next = target->next;

	target->next = NULL;//free 할때는 노드 주소값(노드 포인터)만 넘기면 된다. 
	return target;
}

/* Insertion Sort O(n^2) */
void InsertionSort(int data[], int size)
{
	int i;
	// 정렬되지 않은 집합(head)에 기존 데이터를 삽입
	Node *head_unsorted = (Node *)malloc(sizeof(Node));
	Node *head_sorted = (Node *)malloc(sizeof(Node));
	Node *node = head_unsorted; //정렬되지 않은 노드를 가리키는 node 포인터
	Node *prev, *curr;

	head_unsorted->next = NULL;
	head_sorted->next = NULL;

	/* Unsorted Node 생성 */
	for (i = 0; i<size; i++)
	{
		node->next = (Node *)malloc(sizeof(Node));// 연결하여 생성
		node = node->next;//그다음 주소로 이동
		node->data = data[i];
		node->next = NULL;
	}

	//정렬되지 않은 집합이 공집합이 될때 까지
	while (head_unsorted->next)
	{
		//정렬되지 않은 집합의 첫번째 원소를 빼내어
		node = delete_node(head_unsorted);

		//정렬된 집합에서 자신보다 큰 원소 앞에 넣는다. 
		prev = head_sorted;
		curr = head_sorted->next;
		while (curr && curr->data < node->data)//curr이 NULL이면 멈춘다. 아니면 계속간다.(curr != '\0') 
		{
			prev = prev->next;
			curr = curr->next;
		}
		add_node(prev, node);
	}
	free(head_unsorted);//역할 끝

	//node에게 바통 터치
	node = head_sorted->next;
	free(head_sorted);//역할 끝
	size = 0;

	//다시 정렬된 집합의 내용을 data 배열에 저장
	while (node)
	{
		data[size] = node->data;
		size++;
		prev = node;
		node = node->next;
		free(prev);
	}
	return;
}

/* Mersort O(nlogn)*/
Node *Merge(Node *left, Node *right)
{
	Node *node = (Node *)malloc(sizeof(Node));
	Node *head = node;

	while (left && right)
	{
		if (left->data < right->data)
		{
			node->next = left;
			left = left->next;
			node = node->next;
		}
		else
		{
			node->next = right;
			right = right->next;
			node = node->next;
		}
	}
	//남아있는 리스트를 뒤에 만들어진 노드 뒤에 붙인다.
	if (left)
		node->next = left;
	else
		node->next = right;

	node = head->next;
	//임시 head 제거
	free(head);
	return node;
}

Node *Devide(Node *first, int size)
{
	int i;
	Node *left = first;
	Node *right = first;
	Node *prev_right = first;

	//리스트중 가운데 원소를 찾는다.
	for (i = 0; i < (size / 2) - 1; i++)
	{
		prev_right = prev_right->next;
	}
	right = prev_right->next;
	//왼쪽의 마지막 원소의 link를 아무것도 가리키지 않는 상태로 바꾼다.
	prev_right->next = NULL;

	//원소의 크기가 1이상일 경우에 대해 분할을 다시 한다.
	if (size / 2 > 1) left = Devide(left, size / 2);
	if (size - (size / 2) > 1) right = Devide(right, size - (size / 2));

	//왼쪽과 오른쪽을 합친 값을 return한다.
	return Merge(left, right);
}

void MergeSort(int data[], int size)
{
	Node *head_unsorted = (Node *)malloc(sizeof(Node));
	Node *node = head_unsorted;

	head_unsorted->next = NULL;

	for (int i = 0; i < size; i++)
	{
		node->next = (Node *)malloc(sizeof(Node));
		node = node->next;
		node->data = data[i];
		node->next = NULL;
	}

	node = Devide(head_unsorted->next, size);

	free(head_unsorted);

	for (int i = 0; i < size; i++)
	{
		data[i] = node->data;
		node = node->next;
	}

	return;
}

int main()
{
	int data[7], i;

	for (i = 0; i<7; i++)
	{
		data[i] = rand() % 100;
	}

	//InsertionSort(data, 10);
	MergeSort(data, 7);

	return 0;
}

/*
Function MergeSort(list m)
{
	//사이즈가 0이거나 1인 경우, 바로 리턴
	if (length(m) <= 1)
		return m;
	else
	{
		list size is >1 then,

		//1.Devide 부분
		list left, right
		integer middle <- length(m) / 2

		for each x in m before middle
			add x to left

		for each x in m after or equal middle
			add x ro right


		// List의 크기가 1이 될 때까지 merge_sort 재귀 호출
		left <- merge_sort(left)
		right <- merge_sort(right)

		//분할된 List 병합
		return merge(left, right)
	}
}

Function merge(left, right)
{
	var list result //두 개의 분할된 List를 병합하여 result만듬

	//서브 List의 길이가 0이 될때 까지 반복
	while length(left) > 0 or length(right) > 0
		if (length(left) > 0) and (length(right) > 0)
		// 두 서브 List의 첫 원소들을 비교하여, 작은 것 부터  result에 추가함
			if first(left) <= first(right)
				append first(left) to result
				left <- rest(left)
			else
				append first(right) to result
				right<- rest(right)
		else if length(left) > 0 //왼쪽 List에 원소가 남아있는 경우
			append first(left) to result
			left <- rest(left)
		
		else if length(right) >0 //오른쪽 List에 원소가 남아있는 경우
			append first(right) ro result
			right <- rest(right)
	end while
