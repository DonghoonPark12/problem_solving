#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode **pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
	return GetData(bst);
}

//void BSTInsert(BTreeNode **pRoot, BSTData data) {//�ڡ�
//	BTreeNode *pNode = NULL;
//	BTreeNode *cNode = *pRoot; 
//	BTreeNode *nNode = NULL; //new Node
//
//	while (cNode != NULL) {//��
//		if (data == GetData(cNode)) //��������(Ű��) �ߺ��� ������� ����.
//			return;
//
//		pNode = cNode;
//
//		if (GetData(cNode) > data)
//			cNode = GetLeftSubTree(cNode);
//		else
//			cNode = GetRightSubTree(cNode);
//	}
//
//	//pNode�� �ڽ� ���� �߰��� �� ����� ����
//	nNode = MakeBTreeNode(); //�� ����� ����
//	SetData(nNode, data);    //�� ��忡 ������ ����
//
//	//pNode�� �ڽ� ���� �� ��带 �߰� //��
//	if (pNode != NULL) { //�̹� �θ��尡 Not NULL�̰�, �ڽ� ��尡 NULL�� �� ���� ���Դµ� �ٽ� �θ� ��尡 NULL�� �ƴ��� �˻��ϴ� ���ǹ��� �ʿ��ұ�??(�ʿ��ϴ�)
//		if (data < GetData(pNode))
//			MakeLeftSubTree(pNode, nNode);
//		else
//			MakeRightSubTree(pNode, nNode);
//	}
//	else
//		*pRoot = nNode;
//
//	Rebalance(pRoot);
//}

BTreeNode *BSTInsert(BTreeNode **pRoot, BSTData data) {
	/*
	1. ��Ʈ ��带 ������� �Ͽ� �������� ������ �õ��Ѵ�(�Լ��� ȣ���� ���۵ȴ�).
	1-1. ��Ʈ ��忡 ����� �����Ϳ� �� �����͸� ���Ѵ�.
	1-2. ���Ͽ� �� �������� ���� ������ ���� �ڽ� ��带 ��Ʈ ���� �Ͽ� �������� ������ �õ��Ѵ�.
	1-3. ���Ͽ� �� �������� ���� ũ�� ������ �ڽ� ��带 ��Ʈ ���� �Ͽ� �������� ������ �õ��Ѵ�.
	1-4. ������ �Ϸ�Ǹ� �ش� ��Ʈ ��带 �������� ���뷱���� �����Ѵ�.
	�⺻������ ���� �� ���뷱���� �ܼ� �帧�� ��������� ������ ���� �Ǿ �� ��尡 �߰��� ��� �� ����� �θ� ������
	*/
	if (*pRoot == NULL) {
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else {
		return NULL; //Ű�� �ߺ��� ������� �ʴ´�. 
	}
	return *pRoot;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) { //�ڡ�
	BTreeNode *cNode = bst; //current node
	BSTData cd;
	
	while (cNode != NULL) {
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target){ //�ڡ�
	// ���� ����� ��Ʈ ����� ���, ������ ����ؾ� �Ѵ�.
	BTreeNode *pVRoot = MakeBTreeNode();
	BTreeNode *pNode = pVRoot; // parent node
	BTreeNode *cNode = *pRoot; // current node
	BTreeNode *dNode;          // delete node

	//��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ����� ��带 Ž��
	//���� BSTSearch �Լ��� �ٷ� ���� ���� ������ pNode�� �ּҸ� ���� ���ؼ�.��
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL) //���� ����� �������� �ʴ´ٸ�
		return NULL;

	dNode = cNode; //���� ����� dNode�� ����Ű�� �Ѵ�.

	//ù ��° ���: ���� ����� �ܸ� ����� ��� //��
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	//�� ��° ���: ���� ����� �ڽ� ��� �ϳ��� ������ ��� //��
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode *dcNode; //���� ����� �ڽ� ��带 ����Ű�� ������ ����
		
		//���� ����� �ڽĳ�带 ã�´�.
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		//���� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(pNode) == dNode)   //���� ����� ���� �ڽ� �����
			ChangeLeftSubTree(pNode, dcNode); //�������� ����(���� ����� �θ� ���� �ڽ� ��带 ����)
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	//�� ��° ���: �ΰ��� ���� ��带 ��� ���� ��� //�ڡڡ�
	else {
		BTreeNode *mNode = GetRightSubTree(dNode);//��ü ��带 ����Ŵ
		// or BTreeNode *mNode = GetLeftSubTree(dNode);//��ü ��带 ����Ŵ
		BTreeNode *mpNode = dNode; //mpNode�� ��ü ����� �θ��带 ����Ŵ
		int delData;
		
		//1. �ڿ����� ���� Ʈ������ ���� ���� ���� ã�´�.
		while (GetLeftSubTree(mNode) != NULL) { 
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		//2. ��ü ��忡 ����� ���� ���� ��忡 �����Ѵ�.
		delData = GetData(dNode); //������ ���
		SetData(dNode, GetData(mNode));

		//3. ��ü�� ����� �θ���� �ڽĳ�带 �����Ѵ�. 
		if (GetLeftSubTree(mpNode) == mNode) 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));//mNode�� mpNode�� �����ʿ� ���� ���(å)
		
		dNode = mNode; //??
		SetData(dNode, delData); //��� ������ ����??
	}

	//��Ʈ�� ������ ���, �߰����� ó��.
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot); //���� ��Ʈ ����� �Ҹ�
	return dNode; //���� ����� ��ȯ
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraversal(bst, ShowIntData);
}


