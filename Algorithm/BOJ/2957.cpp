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
		if (data == GetData(cNode)) //데이터의(키의) 중복을 허용하지 않음.
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode(); //새 노드의 생성
	SetData(nNode, data);    //새 노드에 데이터 저장

							 //pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL) { //이미 부모노드가 Not NULL이고, 자식 노드가 NULL일 때 빠져 나왔는데 다시 부모 노드가 NULL이 아님을 검사하는 조건문이 필요할까??
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
	// 삭제 대상이 루트 노드인 경우, 별도로 고려해야 한다.
	BTreeNode *pVRoot = MakeBTreeNode();
	BTreeNode *pNode = pVRoot; // parent node
	BTreeNode *cNode = *pRoot; // current node
	BTreeNode *dNode;          // delete node

							   //루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	//삭제 대상인 노드를 탐색
	//위의 BSTSearch 함수를 바로 쓰지 않은 이유는 pNode의 주소를 갖기 위해서.
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL) //삭제 대상이 존재하지 않는다면
		return NULL;

	dNode = cNode; //삭제 대상을 dNode가 가리키게 한다.

				   //첫 번째 경우: 삭제 대상이 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	//두 번째 경우: 삭제 대상이 자식 노드 하나를 가지는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode *dcNode; //삭제 대상의 자식 노드를 가리키는 포인터 변수

						   //삭제 대상의 자식노드를 찾는다.
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		//삭제 대상의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(pNode) == dNode)   //삭제 대상이 왼쪽 자식 노드라면
			ChangeLeftSubTree(pNode, dcNode); //왼쪽으로 연결(삭제 노드의 부모 노드와 자식 노드를 연결)
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	//세 번째 경우: 두개의 사직 노드를 모두 갖는 경우
	else {
		BTreeNode *mNode = GetRightSubTree(dNode);//대체 노드를 가리킴
												  // or BTreeNode *mNode = GetLeftSubTree(dNode);//대체 노드를 가리킴
		BTreeNode *mpNode = dNode; //mpNode는 대체 노드의 부모노드를 가리킴
		int delData;

		//1. ★오른쪽 서브 트리에서 가장 작은 값을 찾는다.
		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		//2. 대체 노드에 저장된 값을 삭제 노드에 대입한다.
		delData = GetData(dNode); //대입전 백업
		SetData(dNode, GetData(mNode));

		//3. 대체할 노드의 부모노드와 자식노드를 연결한다. 
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode; //??
		SetData(dNode, delData); //백업 데이터 복원??
	}
	//삭제된 노드가 루트노드인 경우에 대한 추가적인 처리.
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot); //가상 루트 노드의 소멸
	return dNode; //삭제 대상의 변환
}

void ShowIntData(int data) {
	printf("%d ", data);
}


int main() {
	freopen("input.txt", "r", stdin);
	BTreeNode *bstRoot; //bstRoot는 BST의 루트노드를 가리킨다.

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