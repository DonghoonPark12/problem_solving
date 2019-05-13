#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct n
{
	int value;
	Node *parent;
	Node *left; //����ü ���� + ���� ����
	Node *right;
} Node;

Node *Root; //Root ���(�� ����Ű�� ������) ����

void init(int value)
{
	Root = (Node *)malloc(sizeof(Node));
	Root->value = value;
	Root->left = NULL; Root->right = NULL;
}


int insert(int value)
{
	Node *temp = Root;

	Node *new;
	new = (Node *)malloc(sizeof(Node));
	new->value = value;
	new->left = NULL; new->right = NULL;

	while (1)
	{
		if (temp->value <  temp->value)// 4 < 5 // 
		{
			if (temp->right == NULL)
			{
				temp->right = new;//temp�� �������� ����ٸ� New ��� ����
				break; //while�� ����
			}
			else
			{
				temp = temp->right;
			}
		}
		else // (1) 9 > 5 // 6 > 5
		{
			if (temp->left == NULL)
			{
				temp->left = new;
				break; //while�� ����
			}
			else
			{
				temp = temp->left; //(1)
			}
		}
	}
}

void tree_inorder(Node* cur) {
	if (cur->left != NULL) {
		tree_inorder(cur->left);
	}
	printf("%c ", cur->value);

	if (cur->right != NULL) {
		tree_inorder(cur->right);
	}
}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%d", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int n;//����� ����
		char a;
		scanf("%d", &n); //��� ����

		Node *Root;

		scanf("%c", &a);
		init(a); //��带 �����ϸ鼭 ���� �� w ����


		tree_inorder(Root);
		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	printf("Case #%d ", test_case + 1);
	printf("%d\n", Answer);

	return 0;

}