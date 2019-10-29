#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct bTreeNode {
	BTData data;
	struct bTreeNode *left;
	struct bTreeNode *right;
}BTreeNode;


// 노드를 동적으로 할당해서 그 노드의 주소값을 반환
BTreeNode *MakeBTreeNode(void);

// 노드에 저장된 데이터를 반환
BTData GetData(BTreeNode *bt);

// 인자로 전달된 데이터를 노드에 저장한다.
void SetData(BTreeNode *bt, BTData data);


// 인자로 전달된 노드의 왼쪽 자식 노드의 주소 값을 반환한다.
BTreeNode *GetLeftSubTree(BTreeNode *bt);

// 인자로 전달된 노드의 오른쪽 자식 노드의 주소 값을 반환한다.
BTreeNode *GetRightSubTree(BTreeNode *bt);


// 인자로 전달된 노드의 왼쪽 자식 노드를 교체한다.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //★

// 인자로 전달된 노드의 오른쪽 자식 노드를 교체한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub); //★


typedef void VisitFuncPtr(BTData data);

void PreorderTraversal(BTreeNode *bt, VisitFuncPtr action);
void InorderTraversal(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraversal(BTreeNode *bt, VisitFuncPtr action);

BTreeNode *RemoveLeftSubTree(BTreeNode *bt);
BTreeNode *RemoveRightSubTree(BTreeNode *bt);

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif
