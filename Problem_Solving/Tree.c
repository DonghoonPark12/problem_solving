typedef struct node {
	int value;
	int node* next;
}Tree_node;


void tree_preorder(struct Tree_node* cur) {
	printf("%d ", cur->value);
	if (cur->left != NULL) {
		tree_preorder(cur->left);
	}
	if (cur->right != NULL) {
		tree_preorder(cur->right);
	}
}

void tree_inorder(tree_node* cur) {
	if (cur->left != NULL) {
		tree_inorder(cur->left);
	}
	printf("%d ", cur->value);

	if (cur->right != NULL) {
		tree_inorder(cur->right);
	}
}

void tree_postorder(tree_node* cur) {
	if (cur->left != NULL) {
		tree_postorder(cur->left);
	}
	if (cur->right != NULL) {
		tree_postorder(cur->right);
	}
	printf("%d ", cur->value);
}
