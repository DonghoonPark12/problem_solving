#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 트리를 배열로 표현 !! */

struct _Node
{
	char word;
	int left;
	int right;
}node[101];

//구조체 100개 생성. 노드 갯수는 100개를 넘어가지 않는다. 

int N, addr; //노드 갯수, 
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
		scanf("%d ", &addr);// 빈칸까지 같이 받아 버리면
		scanf("%c " , &str);// string으로 할 이유가 없다. 

		node[addr].word = str;
		node[addr].left = 0, node[addr].right = 0;

		if (addr * 2 <= N)//왼쪽 자식 노드 
		{
			scanf("%d", &node[addr].left);
			if (addr * 2 + 1 <= N)//오른쪽 자식 노드
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