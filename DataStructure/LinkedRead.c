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
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//노드 추가 과정
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

	//입력 받은 데이터의 전체 출력
	if (head == NULL) {
		printf("저장된 자연수 존재하지 않음");
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
	
	//메모리의 해제 과정
	if (head == NULL) {
		return 0;
	}
	else {
		NODE *delNode = head;
		NODE *delNextNode = head->next;

		printf("%d을 삭제 합니다. \n", head->next);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을 삭제 합니다. \n", delNode->next);
			free(delNode);
		}
	}
}