#include<bits/stdc++.h> 
#include<iostream> 
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
class node
{
public:
	int data;
	node* left;
	node* right;

	/* Constructor that allocates a new node with the given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int isBSTUtil(node* node, int min, int max);

/* Returns true if the given tree is a binary search tree (efficient version). */
int isBST(node* node)
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
	/* an empty tree is BST */
	if (node == NULL)
		return 1;

	/* false if this node violates the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;

	/* otherwise check the subtrees recursively, tightening the min or max constraint */
	return
		isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values  
		isBSTUtil(node->right, node->data + 1, max); // Allow only distinct values  
}


/* Driver code*/
int main()
{
	cout << INT_MIN << INT_MAX;
	node *root = new node(10);
	root->left = new node(5);
	root->right = new node(15);
	root->left->left = new node(NULL);
	root->left->right = new node(NULL);
	root->right->left = new node(6);
	root->right->right = new node(20);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}

//#include <iostream>
//
//int BSearch(int arr[], int len, int target) {
//	int first = 0;
//	int last = len - 1;
//	int mid;
//	int opCount = 0;
//
//	while (first <= last) {
//		mid = (first + last) / 2;
//		if (target == arr[mid])
//			return mid;
//		else {
//			if (target < arr[mid])
//				last = mid - 1;
//			else
//				first = mid + 1;
//		}
//		opCount += 1;
//	}
//	printf("비교연산횟수 : %d \n", opCount);
//	return -1;//찾지 못했을 때 -1
//}
//
//int BSearch_recur(int arr[], int first, int last, int target) {
//	int mid;
//	if (first > last)
//		return -1;
//
//	mid = (first + last) / 2;
//	if (target == arr[mid])
//		return mid;
//	else if (target < arr[mid])
//		return BSearch_recur(arr, first, mid-1 , target);
//	else
//		return BSearch_recur(arr, mid+1, last, target);
//}
//
//typedef struct Tree_node {
//	struct Tree_node *parent;
//	struct Tree_node *left;
//	struct Tree_node *right;
//	int value;
//}Node;
//
//Node *Root;
//
//void init(int value)
//{
//	Root = (Node *)malloc(sizeof(Node));
//	Root->value = value;
//	Root->left = NULL; Root->right = NULL;
//}
//
//
//int insert(int value)
//{
//	Node *temp = Root; //Node 포인터 *temp로 하여금 Root노드를 가리키게 한다. 
//
//	Node *new; //새로 들어온 키 값을 가지고 New노드 구성
//	new = (Node *)malloc(sizeof(Node));
//	new->value = value;
//	new->left = NULL; new->right = NULL;
//
//	while (1)
//	{
//		if (temp->value <  temp->value)// 4 < 5 // 
//		{
//			if (temp->right == NULL)
//			{
//				temp->right = new;//temp의 오른쪽이 비었다면 New 노드 삽입
//				break; //while문 종료
//			}
//			else
//			{
//				temp = temp->right;
//			}
//		}
//		else // (1) 9 > 5 // 6 > 5
//		{
//			if (temp->left == NULL)
//			{
//				temp->left = new;
//				break; //while문 종료
//			}
//			else
//			{
//				temp = temp->left; //(1)
//			}
//		}
//	}
//}
//
//
//
//int delete(int value)
//{
//	/*
//	O(h), h는 이진 탐색 트리의 높이. 이진 트리가 균형적으로 생성되어 있는 경우 O(logN)
//	1. 삭제 하려는 노드를 찾는다.
//	2. 하나의 서브 트리 or 두개의 서브 트리?
//	*/
//	Node *temp = Root;
//	Node *parent = Root;
//	Node *child_P;
//	Node *child;
//
//	while (temp)
//	{
//		if (temp->value < value) //삭제하려는 노드의 값이 더 큰 경우
//		{
//			parent = temp; //현재 노드를 부모로 지정
//			temp = temp->right; //오른쪽으로 temp 포인터 이동
//		}
//		else if (temp->value > value)
//		{
//			parent = temp;
//			temp = temp->left;
//		}
//		else if (temp->value == value) // 찾았다!
//		{
//			if (temp->right == NULL && temp->left == NULL)
//			{
//				//temp = NULL;가 왜 아니지????
//				if (parent->left == temp) parent->left = NULL;
//				else parent->right = NULL;
//			}
//			else if (temp->right != NULL && temp->left != NULL) //자식이 둘다 있을때
//			{
//				child_P = temp;
//				child = temp->left;
//
//				while (child->right != NULL)//child 는 6
//				{
//					child_P = child;
//					child = child->right;
//				}
//
//				if (child_P->left == child) child_P->left = child->right;
//				else child_P->right = child->right;
//
//				temp->value = child->value;
//				temp = child;
//			}
//			else //자식이 하나 밖에 없을 때
//			{
//				if (temp->right != NULL)
//				{
//					if (parent->right == temp) parent->right = temp->right;
//					else parent->left = temp->right;
//				}
//				else
//				{
//					if (parent->right == temp) parent->right = temp->left;
//					else parent->left = temp->left;
//				}
//			}
//			free(temp);
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	int arr[] = {1,3,5,7,9 };
//	int idx;
//	int arr1[500] = { 0, };
//	int arr2[5000] = { 0, };
//	int arr3[50000] = { 0, };
//
//
//	//idx = BSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 1);
//	//if (idx == -1) printf("탐색 실패\n");
//	//else printf("타겟 인덱스: %d \n", idx);
//
//	//idx = BSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 2);
//	//if (idx == -1) printf("탐색 실패\n");
//	//else printf("타겟 인덱스: %d \n", idx);
//
//	//idx = BSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 3);
//	//if (idx == -1) printf("탐색 실패\n");
//	//else printf("타겟 인덱스: %d \n", idx);
//
//	idx = BSearch_recur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
//	if (idx == -1) printf("탐색 실패\n");
//	else printf("타겟 인덱스: %d \n", idx);
//	
//	idx = BSearch_recur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
//	if (idx == -1) printf("탐색 실패\n");
//	else printf("타겟 인덱스: %d \n", idx);
//
//	return 0;
//}
//
//
//

/*
tree_node * Temp = search(value);//Temp 노드가 삭제하려는 노드를 가리키게 한다.
if ((Temp->left == NULL) && (Temp->right == NULL))
{
Temp = NULL;
}


while (child->right != NULL)
{
child_P = child;
child = child->right;
}

}
*/
//int search(int value) // 탐색
//{
//	/* 이진 탐색 트리의 중위 순회의 경우 */
//	Node *Temp = Root; //tree_node 포인터로 하여금 Root를 가리키게 한다.
//
//	while (Temp)
//	{
//		if (Temp->value < value)
//		{
//			Temp = Temp->right;
//		}
//		else if (Temp->value > value)
//		{
//			Temp = Temp->left;
//		}
//		else if (Temp->value == value)
//		{
//			return 1;
//		}
//	}
//	return 0; //찾지 못하였을 경우(Temp == 'NULL') 0 반환
//}



//int main(void)
//{
//	int T, test_case;
//	freopen("input.txt", "r", stdin);
//
//	setbuf(stdout, NULL);
//
//	scanf("%d\n", &test_case); //2
//
//	for (int i = 0; i < test_case; i++)
//	{
//		printf("%d", test_case + 1);
//
//		int n;//연산 수
//		scanf("%d\n", &n); //3
//
//		int op, value;
//		while (n--)
//		{
//			scanf("%d ", &op);
//			if (op == 1)
//			{
//				scanf("%d\n", &value);
//				insert(value);
//			}
//			else
//			{
//				delete();
//			}
//		}
//
//
//	}
//	return 0;
//
//}