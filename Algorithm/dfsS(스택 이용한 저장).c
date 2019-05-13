#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int edge[1010][1010];
int visited[1010]; //visited��� �迭�� ���� ����, �湮 �Ǿ��ٸ� 1�� �δ� ����� Ź���ϴ�. 
int u, v; //���� ����, ���� ���� 
int N, M; //���� ����, ���� ����
int stack[1010];
int top = -1;

void push(int cur)
{
	top++;
	stack[top] = cur; // stack�� 1 ����
	visited[cur] = 1; //1�� �湮 �Ǿ���.
	return;
}

void pop()
{
	top--;
	return;
}

void dfs(int cur)
{
	push(cur); //stack�� ����
	printf("%d ", cur);

	while (top >= 0)
	{
		for (int i = 1; i <= N; i++) //���� ���� 7�� �� Ȯ�� �Ѵ�. 
		{
			if (visited[i] == 0 && edge[stack[top]][i] == 1) //������ �湮 �Ǿ��� �ʾҰų�, 
			{												 // ���� ���ÿ� �����(1)�� ����� �����̶��.
				push(i);									 // 2�� ����.
				i = 1;										 //
			}
		}
		pop();
	}
}




int main()
{
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) //���� ����
	{
		scanf("%d %d", &u, &v);
		edge[u][v] = 1; //���� ��� ������� �׷��� ����
		edge[v][u] = 1; //�ڡھ瓇�� �׷����� ���
	}
	dfs(1);

	return 0;
}