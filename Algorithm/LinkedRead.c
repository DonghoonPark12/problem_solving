#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

int main() {
	NODE *head = NULL;
	NODE *tail = NULL;
	NODE *cur = NULL;

	NODE *newNode = NULL;
	NODE *dummy = NULL;
	int readData;

	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//��� �߰� ����
		dummy = (NODE*)malloc(sizeof(NODE));
		dummy->data = NULL;
		dummy->next= NULL;
		
		newNode = (NODE*)malloc(sizeof(NODE));
		newNode->data = readData;
		newNode->next= NULL;

		//if (head == NULL) {
		//	head = newNode;
		//	tail = newNode;
		//}
		//else {
		//	newNode->next = head;
		//	head = newNode;
		//}

		head = dummy;
		if (dummy->next == NULL)
			dummy->next = newNode;
		else
			tail->next= newNode;
		tail = newNode;
	}
	printf("\n");

	//�Է� ���� �������� ��ü ���
	if (head == NULL) {
		printf("����� �ڿ��� �������� ����");
	}
	else {
		cur = tail;
		printf("%d ", cur->data);
		while (cur->next!= NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");
	
	//�޸��� ���� ����
	if (head == NULL) {
		return 0;
	}
	else {
		NODE *delNode = head;
		NODE *delNextNode = head->next;

		printf("%d�� ���� �մϴ�. \n", head->next);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�� ���� �մϴ�. \n", delNode->next);
			free(delNode);
		}
	}
}