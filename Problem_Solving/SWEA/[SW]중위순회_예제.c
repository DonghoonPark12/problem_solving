#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Ʈ���� �迭�� ǥ�� !! */

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
	for (i = 0; i < N; i++)
	{
		scanf("%d ", &addr);// ��ĭ���� ���� �޾� ������
		scanf("%c " , &str);// string���� �� ������ ����. 

		node[addr].word = str;
		node[addr].left = 0, node[addr].right = 0;

		if (addr * 2 <= N)//���� �ڽ� ��� 
		{
			scanf("%d", &node[addr].left);
			if (addr * 2 + 1 <= N)//������ �ڽ� ���
				scanf("%d", &node[addr].right);
		}

	}
}
/* Input */
/*
8
1 W 2 3
2 F 4 5
3 R 6 7
4 O 8
5 T
6 A
7 E
8 S
*/
int main()
{
	int test_case;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

		scanf("%d", &N);
		input();
		print(1);
		printf("\n");

	return 0;
}