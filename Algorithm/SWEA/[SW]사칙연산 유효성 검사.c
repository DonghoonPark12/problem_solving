#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct _Node
{
	char word;
	int left;
	int right;
}node[101];

//����ü 100�� ����. ��� ������ 100���� �Ѿ�� �ʴ´�. 

int N, addr; //��� ����, 
			 //char str[10];
char str;

void print(int v)
{
	if (node[v].left > 0)
		print(node[v].left);
	printf("%c", node[v].word);
	if (node[v].right > 0)
		print(node[v].right);
}

void input()
{
	int i;
	for (i = 0; i < N; i++) //7�� ����
	{
		scanf("%d ", &addr);// ��ĭ���� ���� �޾� ������ // 1 //2 //3 //4
		if (addr <= N / 2)
		{
			scanf("%c ", &str);// string���� �� ������ ����. // * //* // /

			node[addr].word = str;
			node[addr].left = 0, node[addr].right = 0;

			if (addr * 2 <= N)//���� �ڽ� ��� 
			{
				scanf("%d", &node[addr].left); // 2 // 4 // 6
				if (addr * 2 + 1 <= N)//������ �ڽ� ��� 
					scanf("%d", &node[addr].right); //3 // 5 // 7
			}
		}
		else
		{
			scanf("%d ", &str); 
			node[addr].word = str; //word �ڸ��� ���� ��� ����. 
			//node[addr].left = 0, node[addr].right = 0;
			if (addr * 2 <= N)//���� �ڽ� ��� 
			{
				scanf("%d", &node[addr].left); 
				if (addr * 2 + 1 <= N)//������ �ڽ� ��� 
					scanf("%d", &node[addr].right); 
			}
		}

	}
}
/* Input */
/*
7
1 * 2 3
2 * 4 5
3 / 6 7
4 8
5 2
6 9
7 4
*/
int main()
{
	int test_case;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &N); // 7
	input();
	print(1);
	printf("\n");

	return 0;
}