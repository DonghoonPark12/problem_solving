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
	/* ���� ��尡 ����Ű�� ���� ���ο� ��嵵 ����Ű�� �� �� */
//	p_new->next = prev->next;
	/* ���� ��尡 (������ �ٲ�)���ο� ��带 ����Ű�� �Ѵ�. */
//	prev->next = p_new;
//}

void add_node(Node *prev, Node *p_new)
{
	p_new->next = prev->next;

	prev->next = p_new;
}

/* �ڷ� Ž���� �������, ������ Ž���� �����ϴ� */
Node * delete_node(Node *prev)//(Node *cur, Node *prev)
{
	/* ���� ��尡 ����Ű�� ���� Target���� �Ѵ� */
	Node *target = prev->next; //������ ��带 ����Ű�� �Ѵ�. 

							   /*���� ��尡 ����Ű�� ���� ���� ��嵵 ����Ű�� �Ѵ�. */
	prev->next = target->next;

	target->next = NULL;//free �Ҷ��� ��� �ּҰ�(��� ������)�� �ѱ�� �ȴ�. 
	return target;
}

/* Insertion Sort O(n^2) */
void InsertionSort(int data[], int size)
{
	int i;
	// ���ĵ��� ���� ����(head)�� ���� �����͸� ����
	Node *head_unsorted = (Node *)malloc(sizeof(Node));
	Node *head_sorted = (Node *)malloc(sizeof(Node));
	Node *node = head_unsorted; //���ĵ��� ���� ��带 ����Ű�� node ������
	Node *prev, *curr;

	head_unsorted->next = NULL;
	head_sorted->next = NULL;

	/* Unsorted Node ���� */
	for (i = 0; i<size; i++)
	{
		node->next = (Node *)malloc(sizeof(Node));// �����Ͽ� ����
		node = node->next;//�״��� �ּҷ� �̵�
		node->data = data[i];
		node->next = NULL;
	}

	//���ĵ��� ���� ������ �������� �ɶ� ����
	while (head_unsorted->next)
	{
		//���ĵ��� ���� ������ ù��° ���Ҹ� ������
		node = delete_node(head_unsorted);

		//���ĵ� ���տ��� �ڽź��� ū ���� �տ� �ִ´�. 
		prev = head_sorted;
		curr = head_sorted->next;
		while (curr && curr->data < node->data)//curr�� NULL�̸� �����. �ƴϸ� ��Ӱ���.(curr != '\0') 
		{
			prev = prev->next;
			curr = curr->next;
		}
		add_node(prev, node);
	}
	free(head_unsorted);//���� ��

	//node���� ���� ��ġ
	node = head_sorted->next;
	free(head_sorted);//���� ��
	size = 0;

	//�ٽ� ���ĵ� ������ ������ data �迭�� ����
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
	//�����ִ� ����Ʈ�� �ڿ� ������� ��� �ڿ� ���δ�.
	if (left)
		node->next = left;
	else
		node->next = right;

	node = head->next;
	//�ӽ� head ����
	free(head);
	return node;
}

Node *Devide(Node *first, int size)
{
	int i;
	Node *left = first;
	Node *right = first;
	Node *prev_right = first;

	//����Ʈ�� ��� ���Ҹ� ã�´�.
	for (i = 0; i < (size / 2) - 1; i++)
	{
		prev_right = prev_right->next;
	}
	right = prev_right->next;
	//������ ������ ������ link�� �ƹ��͵� ����Ű�� �ʴ� ���·� �ٲ۴�.
	prev_right->next = NULL;

	//������ ũ�Ⱑ 1�̻��� ��쿡 ���� ������ �ٽ� �Ѵ�.
	if (size / 2 > 1) left = Devide(left, size / 2);
	if (size - (size / 2) > 1) right = Devide(right, size - (size / 2));

	//���ʰ� �������� ��ģ ���� return�Ѵ�.
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
	//����� 0�̰ų� 1�� ���, �ٷ� ����
	if (length(m) <= 1)
		return m;
	else
	{
		list size is >1 then,

		//1.Devide �κ�
		list left, right
		integer middle <- length(m) / 2

		for each x in m before middle
			add x to left

		for each x in m after or equal middle
			add x ro right


		// List�� ũ�Ⱑ 1�� �� ������ merge_sort ��� ȣ��
		left <- merge_sort(left)
		right <- merge_sort(right)

		//���ҵ� List ����
		return merge(left, right)
	}
}

Function merge(left, right)
{
	var list result //�� ���� ���ҵ� List�� �����Ͽ� result����

	//���� List�� ���̰� 0�� �ɶ� ���� �ݺ�
	while length(left) > 0 or length(right) > 0
		if (length(left) > 0) and (length(right) > 0)
		// �� ���� List�� ù ���ҵ��� ���Ͽ�, ���� �� ����  result�� �߰���
			if first(left) <= first(right)
				append first(left) to result
				left <- rest(left)
			else
				append first(right) to result
				right<- rest(right)
		else if length(left) > 0 //���� List�� ���Ұ� �����ִ� ���
			append first(left) to result
			left <- rest(left)
		
		else if length(right) >0 //������ List�� ���Ұ� �����ִ� ���
			append first(right) ro result
			right <- rest(right)
	end while
