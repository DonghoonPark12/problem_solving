#include <stdio.h>

#define MAX_NODE 100
class LinkedList {
public:
	struct Node {
		int data;
		str
	};
};
typedef struct listnode
{
	int data;
	listnode *front;
	listnode *rear;
}ListNode;

typedef struct {
	int use;
	ListNode node;
}ListNodeHeap;

ListNodeHeap heap[MAX_NODE];

void initHeap(void) {
	for (int i = 0; i < MAX_NODE; i++)
		heap[i].use = 0;
}

	
