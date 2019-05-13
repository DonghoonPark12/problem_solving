#include <stdio.h>
#include <stdlib.h>


typedef struct Tree_node {
	struct Tree_node *parent;
	struct Tree_node *left;
	struct Tree_node *right;
	int value;
}Node;

Node *Root;
/*
typedef struct n 
{
	int value;
	Node *parent;
	Node *left; //����ü ���� + ���� ����
	Node *right;
}Node;

 Node *Root; //Root ���(�� ����Ű�� ������) ����
 */

void init(int value)
{
	Root = (Node *)malloc(sizeof(Node));
	Root->value = value;
	Root->left = NULL; Root->right = NULL;
}


int insert(int value)
{
	Node *temp = Root; //Node ������ *temp�� �Ͽ��� Root��带 ����Ű�� �Ѵ�. 

	Node *new; //���� ���� Ű ���� ������ New��� ����
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



int delete(int value)
{
	/*
	O(h), h�� ���� Ž�� Ʈ���� ����. ���� Ʈ���� ���������� �����Ǿ� �ִ� ��� O(logN)
	1. ���� �Ϸ��� ��带 ã�´�.
	2. �ϳ��� ���� Ʈ�� or �ΰ��� ���� Ʈ��?
	*/
	Node *temp = Root;
	Node *parent = Root;
	Node *child_P;
	Node *child;

	while (temp)
	{
		if (temp->value < value) //�����Ϸ��� ����� ���� �� ū ���
		{
			parent = temp; //���� ��带 �θ�� ����
			temp = temp->right; //���������� temp ������ �̵�
		}
		else if (temp->value > value)
		{
			parent = temp;
			temp = temp->left;
		}
		else if (temp->value == value) // ã�Ҵ�!
		{
			if (temp->right == NULL && temp->left == NULL)
			{
				//temp = NULL;�� �� �ƴ���????
				if (parent->left == temp) parent->left = NULL;
				else parent->right = NULL;
			}
			else if (temp->right != NULL && temp->left != NULL) //�ڽ��� �Ѵ� ������
			{
				child_P = temp;
				child = temp->left;

				while (child->right != NULL)//child �� 6
				{
					child_P = child;
					child = child->right;
				}

				if (child_P->left == child) child_P->left = child->right;
				else child_P->right = child->right;

				temp->value = child->value;
				temp = child;
			}
			else //�ڽ��� �ϳ� �ۿ� ���� ��
			{
				if (temp->right != NULL)
				{
					if (parent->right == temp) parent->right = temp->right;
					else parent->left = temp->right;
				}
				else
				{
					if (parent->right == temp) parent->right = temp->left;
					else parent->left = temp->left;
				}
			}
			free(temp);
			return 1;
		}
	}
	return 0;
}
	
/*
	tree_node * Temp = search(value);//Temp ��尡 �����Ϸ��� ��带 ����Ű�� �Ѵ�.
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
int search(int value) // Ž��
{
	/* ���� Ž�� Ʈ���� ���� ��ȸ�� ��� */
	Node *Temp = Root; //tree_node �����ͷ� �Ͽ��� Root�� ����Ű�� �Ѵ�.

	while (Temp)
	{
		if (Temp->value < value)
		{
			Temp = Temp->right;
		}
		else if (Temp->value > value)
		{
			Temp = Temp->left;
		}
		else if (Temp->value == value)
		{
			return 1;
		}
	}
	return 0; //ã�� ���Ͽ��� ���(Temp == 'NULL') 0 ��ȯ
}



int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &test_case); //2

	for (int i = 0; i < test_case; i++)
	{
		printf("%d", test_case + 1);

		int n;//���� ��
		scanf("%d\n", &n); //3

		int op, value;
		while (n--)
		{
			scanf("%d ", &op);
			if (op == 1)
			{
				scanf("%d\n", &value);
				insert(value);
			}
			else
			{
				delete();
			}
		}


	}
	return 0;

}