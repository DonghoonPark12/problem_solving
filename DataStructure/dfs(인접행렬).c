/* 
O(V+E)
DFS���� ������ ����� BackTracking
��� �Լ��� ���� �����Ǵ� ��찡 ����. 
*/

#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int edge[1010][1010];
int visited[1010]; //visited��� �迭�� ���� ����, �湮 �Ǿ��ٸ� 1�� �δ� ����� Ź���ϴ�. 
int u, v; //���� ����, ���� ���� 
int N, M; //���� ����, ���� ����

void dfs(int cur)
{
	visited[cur] = 1;
	printf("%d", cur);
	for (int i = 1; i <= N; i++) //���� ����(�� ���� ����, ��� ���� 1 ~ 7���� Ȯ���� �Ѵ�...)
	{
		if (visited[i] != 0 || edge[cur][i] == 0)
			continue; //�̹� �湮 �Ǿ��ų�(||), ������ ����Ǿ����� �ʴٸ� (Pruning)
		dfs(i);
		/*
		//�湮�� �ȵǾ����鼭(&&)������ �����Ѵٸ�
		if(visitied[i] == 0 && edge[cur][i] == 1)
			dfs(i);
		*/
	}
}

int main()
{	
	freopen("input.txt", "r", stdin);

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
