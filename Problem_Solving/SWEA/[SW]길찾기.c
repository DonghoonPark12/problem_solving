#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n;
int edge[100][100] = { 0 };
int flag;
int visited[100] = { 0 };

int dfs(int cur)
{
	visited[cur] = 1;
	//printf("%d", cur);
	for (int i = 1; i <= 99; i++) //���� ����(�� ���� ����, ��� ���� 1 ~ 7���� Ȯ���� �Ѵ�...)
	{
		if (visited[i] != 1 || edge[cur][i] == 1) //�湮 ���� �ʾҰ�, ������ �����ϸ� 
		{
			if (i == 99)
			{
				visited[i] = 1;
				flag = 1;
				return;

			}
			dfs(i);
		}
	}
}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int u, v;
		scanf("%d\n", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d ", &u, &v); //0 1 0 2 1 4 1 3 4 8 4 3 2 9 2 5 5 6 5 7 7 99 7 9 9 8 9 10 6 10 3 7
			edge[u][v] = 1;
		}

		dfs(0);

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	printf("#%d ", T);
	printf("%d\n", flag);

	return 0;

}