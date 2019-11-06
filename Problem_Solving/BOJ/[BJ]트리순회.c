#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct _Node
{
	char left;
	char right;
}node[91];
//����ü 26�� ����. ��� ������ 26���� �Ѿ�� �ʴ´�. (X)
//word�� �ε����� ������ �Ѵ�. Z �� 90������ �־�� �Ѵ�. 

int N; //��� ����
int word;

void inorder(char v)
{
	if (node[v].left !='.')
		inorder(node[v].left);

	printf("%c", v);

	if (node[v].right != '.')
		inorder(node[v].right);
}

void preorder(char v) // 1 //index�� �޴ٰ� word���� ���� ���ȴ�. // 'A'
{
	printf("%c", v); //A

	if (node[v].left != '.')
		preorder(node[v].left); //B //D

	if (node[v].right != '.')
		preorder(node[v].right);
}

void postorder(char v)
{
	if (node[v].left != '.')
		postorder(node[v].left);

	if (node[v].right != '.')
		postorder(node[v].right);

		printf("%c", v);
}

void input()
{
	// 7���� ���� �Ҵ� ��Ű�� �Է��ϴ°� �´�. 
	// �ٸ�, �������� ��尡 26�� ������ �����Ƿ� ����ü �迭�� �̸� �������. 
	for (int i = 1; i <= N; i++) //7
	{
		//scanf("%c ", &node[i].word);// string���� �� ������ ����. A
		scanf("%c ", &word);
		scanf("%c ", &node[word].left);//B
		scanf("%c ", &node[word].right);//C
	}
}

int main()
{
		freopen("input.txt", "r", stdin);

		setbuf(stdout, NULL);

		scanf("%d\n", &N); //7
		input();
		
		//puts(): ���ڿ� ���� �ִ� NULL���ڴ� �ٹٲ� ������ ����ȴ�. 
		preorder('A'); puts(""); 
		inorder('A'); puts("");
		postorder('A'); 

		
		printf("\n");
	return 0;
}