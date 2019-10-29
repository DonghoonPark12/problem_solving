#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct bTreeNode {
	BTData data;
	struct bTreeNode *left;
	struct bTreeNode *right;
}BTreeNode;


// ��带 �������� �Ҵ��ؼ� �� ����� �ּҰ��� ��ȯ
BTreeNode *MakeBTreeNode(void);

// ��忡 ����� �����͸� ��ȯ
BTData GetData(BTreeNode *bt);

// ���ڷ� ���޵� �����͸� ��忡 �����Ѵ�.
void SetData(BTreeNode *bt, BTData data);


// ���ڷ� ���޵� ����� ���� �ڽ� ����� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode *GetLeftSubTree(BTreeNode *bt);

// ���ڷ� ���޵� ����� ������ �ڽ� ����� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode *GetRightSubTree(BTreeNode *bt);


// ���ڷ� ���޵� ����� ���� �ڽ� ��带 ��ü�Ѵ�.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //��

// ���ڷ� ���޵� ����� ������ �ڽ� ��带 ��ü�Ѵ�.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub); //��


typedef void VisitFuncPtr(BTData data);

void PreorderTraversal(BTreeNode *bt, VisitFuncPtr action);
void InorderTraversal(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraversal(BTreeNode *bt, VisitFuncPtr action);

BTreeNode *RemoveLeftSubTree(BTreeNode *bt);
BTreeNode *RemoveRightSubTree(BTreeNode *bt);

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif
