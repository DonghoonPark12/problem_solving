#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"

BTreeNode *MakeBTreeNode() {
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode *bt) {
	return bt->data;
}

void SetData(BTreeNode *bt, BTData data) {
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) {
	return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) { //¡Ú
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) { //¡Ú
	if (main->right!= NULL)
		free(main->right);
	main->right= sub;
}

void PreorderTraversal(BTreeNode * bt, VisitFuncPtr action) { //¡Ú
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraversal(bt->left, action);
	PreorderTraversal(bt->right, action);
}

void InorderTraversal(BTreeNode * bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;
	InorderTraversal(bt->left, action);
	action(bt->data);
	InorderTraversal(bt->right, action);
	
}

void PostorderTraversal(BTreeNode * bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;
	PostorderTraversal(bt->left, action);
	PostorderTraversal(bt->right, action);
	action(bt->data);
}

BTreeNode *RemoveLeftSubTree(BTreeNode * bt) { //¡Ú
	BTreeNode *delNode = NULL;
	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode *RemoveRightSubTree(BTreeNode * bt) { //¡Ú
	BTreeNode *delNode = NULL;
	if (bt != NULL) {
		delNode = bt->right;
		bt->right= NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub) {
	main->right = sub;
}




