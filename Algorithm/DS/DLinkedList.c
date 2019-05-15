#include <stdlib.h>
#include <../C,C++/LinkedList.h>


void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}