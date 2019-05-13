#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct _Node
{
	char left;
	char right;
}node[91];
//구조체 26개 생성. 노드 갯수는 26개를 넘어가지 않는다. (X)
//word가 인덱스의 역할을 한다. Z 즉 90까지는 있어야 한다. 

int N; //노드 갯수
int word;

void inorder(char v)
{
	if (node[v].left !='.')
		inorder(node[v].left);

	printf("%c", v);

	if (node[v].right != '.')
		inorder(node[v].right);
}

void preorder(char v) // 1 //index로 받다가 word값이 들어와 버렸다. // 'A'
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
	// 7개를 동적 할당 시키고 입력하는게 맞다. 
	// 다만, 문제에서 노드가 26개 정해져 있으므로 구조체 배열을 미리 만들었다. 
	for (int i = 1; i <= N; i++) //7
	{
		//scanf("%c ", &node[i].word);// string으로 할 이유가 없다. A
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
		
		//puts(): 문자열 끝에 있는 NULL문자는 줄바꿈 문제로 변경된다. 
		preorder('A'); puts(""); 
		inorder('A'); puts("");
		postorder('A'); 

		
		printf("\n");
	return 0;
}