#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	/*
	BTreeNode *bstRoot; //bstRoot는 BST의 루트노드를 가리킨다.
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
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));
	
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));
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

	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	//clNode = GetLeftSubTree(clNode);
	//crNode = GetRightSubTree(crNode);
	//printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));

/*	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);

	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));
	*/
	return 0;
}