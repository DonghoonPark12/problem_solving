/*
     1
	/  \
   2    3
  / \
 4   5
*/ 

/* Method1: using queue
	printLevelorder(tree)
	1) Create an empty queue q
	2) temp_node = root //start from root
	3) Loop while temp_node is not NULL
	a) print temp_node->data.
	b) Enqueue temp_node¡¯s children(first left then right children) to q
	c) Dequeue a node from q and assign it¡¯s value to temp_node
*/

/* Method2: using recursive function
Function to print level order traversal of tree
printLevelOrder(tree)
for d = 1 to height(tree)
	printGivenLevel(tree,d)

// Function to print all nodes at a given level
if tree is NULL then return;
if level is 1, then
	print(tree->data);
else if level greater than 1, then
	printGivenLevel(tree->left, level-1);
	printGivenLevel(tree->right, level-1);
https://www.geeksforgeeks.org/level-order-tree-traversal/
*/

#include <iostream> 
#include <queue> 
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};

void printLevelOrder(Node *root) {
	if (root == NULL) return;
	queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node *node = q.front();//temp_node
		cout << node->data << " ";
		q.pop();
		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/* Enqueue right child */
		if (node->right!= NULL)
			q.push(node->right);
	}
}

Node *newNode(int data) {
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions 
int main()
{
	// Let us create binary tree shown in above diagram 
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}


//Below, recursive method
// Recursive CPP program for level 
// order traversal of Binary Tree  
//#include <bits/stdc++.h> 
//using namespace std;
//
///* A binary tree node has data,
//pointer to left child
//and a pointer to right child */
//class node
//{
//public:
//	int data;
//	node* left, *right;
//};
//
///* Function protoypes */
//void printGivenLevel(node* root, int level);
//int height(node* node);
//node* newNode(int data);
//
///* Function to print level
//order traversal a tree*/
//void printLevelOrder(node* root)
//{
//	int h = height(root);
//	int i;
//	for (i = 1; i <= h; i++)
//		printGivenLevel(root, i);
//}
//
///* Print nodes at a given level */
//void printGivenLevel(node* root, int level)
//{
//	if (root == NULL)
//		return;
//	if (level == 1)
//		cout << root->data << " ";
//	else if (level > 1)
//	{
//		printGivenLevel(root->left, level - 1);
//		printGivenLevel(root->right, level - 1);
//	}
//}
//
///* Compute the "height" of a tree -- the number of
//nodes along the longest path from the root node
//down to the farthest leaf node.*/
//int height(node* node)
//{
//	if (node == NULL)
//		return 0;
//	else
//	{
//		/* compute the height of each subtree */
//		int lheight = height(node->left);
//		int rheight = height(node->right);
//
//		/* use the larger one */
//		if (lheight > rheight)
//			return(lheight + 1);
//		else return(rheight + 1);
//	}
//}
//
///* Helper function that allocates
//a new node with the given data and
//NULL left and right pointers. */
//node* newNode(int data)
//{
//	node* Node = new node();
//	Node->data = data;
//	Node->left = NULL;
//	Node->right = NULL;
//
//	return(Node);
//}
//
///* Driver code*/
//int main()
//{
//	node *root = newNode(1);
//	root->left = newNode(2);
//	root->right = newNode(3);
//	root->left->left = newNode(4);
//	root->left->right = newNode(5);
//
//	cout << "Level Order traversal of binary tree is \n";
//	printLevelOrder(root);
//
//	return 0;
//}