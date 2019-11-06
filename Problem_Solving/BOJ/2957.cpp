#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int BTData;

typedef BTData BSTData;

typedef void VisitFuncPtr(BTData data);

int cnt = 0;

typedef struct bTreeNode {
	BTData data;
	struct bTreeNode *left;
	struct bTreeNode *right;
}BTreeNode;

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

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}

BTreeNode *RemoveLeftSubTree(BTreeNode * bt) {
	BTreeNode *delNode = NULL;
	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode *RemoveRightSubTree(BTreeNode * bt) {
	BTreeNode *delNode = NULL;
	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub) {
	main->right = sub;
}


void BSTMakeAndInit(BTreeNode **pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data) {
	cout << cnt << endl;
	cnt++;
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *pRoot;
	BTreeNode *nNode = NULL; //new Node

	while (cNode != NULL) {
		if (data == GetData(cNode)) //��������(Ű��) �ߺ��� ������� ����.
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode(); //�� ����� ����
	SetData(nNode, data);    //�� ��忡 ������ ����

							 //pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL) { //�̹� �θ��尡 Not NULL�̰�, �ڽ� ��尡 NULL�� �� ���� ���Դµ� �ٽ� �θ� ��尡 NULL�� �ƴ��� �˻��ϴ� ���ǹ��� �ʿ��ұ�??
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) {
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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ���, ������ ����ؾ� �Ѵ�.
	BTreeNode *pVRoot = MakeBTreeNode();
	BTreeNode *pNode = pVRoot; // parent node
	BTreeNode *cNode = *pRoot; // current node
	BTreeNode *dNode;          // delete node

							   //��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ����� ��带 Ž��
	//���� BSTSearch �Լ��� �ٷ� ���� ���� ������ pNode�� �ּҸ� ���� ���ؼ�.
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

				   //ù ��° ���: ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	//�� ��° ���: ���� ����� �ڽ� ��� �ϳ��� ������ ���
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
	//�� ��° ���: �ΰ��� ���� ��带 ��� ���� ���
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
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode; //??
		SetData(dNode, delData); //��� ������ ����??
	}
	//������ ��尡 ��Ʈ����� ��쿡 ���� �߰����� ó��.
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot); //���� ��Ʈ ����� �Ҹ�
	return dNode; //���� ����� ��ȯ
}

void ShowIntData(int data) {
	printf("%d ", data);
}


int main() {
	freopen("input.txt", "r", stdin);
	BTreeNode *bstRoot; //bstRoot�� BST�� ��Ʈ��带 ����Ų��.

	BSTMakeAndInit(&bstRoot);

	int n; cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		BSTInsert(&bstRoot, tmp);
	}

	//BSTShowAll(bstRoot); printf("\n");
	return 0;
}