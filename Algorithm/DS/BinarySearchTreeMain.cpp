#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	/*
	BTreeNode *bstRoot; //bstRoot�� BST�� ��Ʈ��带 ����Ų��.
	BTreeNode *sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));
	
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));
	*/

	//BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
	//BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	//BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
	//BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	//BSTInsert(&bstRoot, 7);

	//BSTShowAll(bstRoot); printf("\n");
	//sNode = BSTRemove(&bstRoot, 3);
	//free(sNode);

	//BSTShowAll(bstRoot); printf("\n");
	//sNode = BSTRemove(&bstRoot, 8);
	//free(sNode);

	//BSTShowAll(bstRoot); printf("\n");
	//sNode = BSTRemove(&bstRoot, 1);
	//free(sNode);

	//BSTShowAll(bstRoot); printf("\n");
	//sNode = BSTRemove(&bstRoot, 6);
	//free(sNode);

	//int n; cin >> n;
	//int tmp;
	//for (int i = 0; i < n; i++) {
	//	cin >> tmp;
	//	BSTInsert(&bstRoot, tmp);
	//}

	//BSTShowAll(bstRoot); printf("\n");

	BTreeNode *avlRoot;
	BTreeNode *clNode;
	BTreeNode *crNode;
	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	//BSTInsert(&avlRoot, 7);
	//BSTInsert(&avlRoot, 8);
	//BSTInsert(&avlRoot, 9);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

	//clNode = GetLeftSubTree(clNode);
	//crNode = GetRightSubTree(crNode);
	//printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));

/*	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));
	*/
	return 0;
}