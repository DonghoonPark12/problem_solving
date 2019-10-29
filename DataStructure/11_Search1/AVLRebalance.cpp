#include <iostream>
#include "BinaryTree3.h"
#include "AVLRebalance.h"

int GetHeight(BTreeNode *bst) {
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode *bst) {
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));
	return lsh - rsh;
}

BTreeNode *RotateLL(BTreeNode *bst) {
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTreeNode *RotateRR(BTreeNode *bst) {
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTreeNode *RotateLR(BTreeNode *bst) {
	BTreeNode *pNode;
	//BTreeNode *cNode;

	pNode = GetLeftSubTree(bst);
	ChangeLeftSubTree(bst, RotateRR(pNode));
	
	return RotateLL(bst);
}

BTreeNode *RotateRL(BTreeNode *bst) {
	BTreeNode *pNode;
	//BTreeNode *cNode;

	pNode = GetRightSubTree(bst);
	ChangeRightSubTree(bst, RotateLL(pNode));
	return RotateRR(bst);
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) { //LL or LR
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) 
			*pRoot = RotateLL(*pRoot); //LL
		else
			*pRoot = RotateLR(*pRoot); //LR
	}

	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) //RR or RL
			*pRoot = RotateRR(*pRoot); //RR
		else
			*pRoot = RotateRL(*pRoot); //RL
	}
	return *pRoot;
}
