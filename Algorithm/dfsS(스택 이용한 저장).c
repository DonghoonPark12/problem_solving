#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int edge[1010][1010];
int visited[1010]; //visited라는 배열을 따로 만들어서, 방문 되었다면 1로 두는 방식은 탁월하다. 
int u, v; //시작 정점, 도착 정점 
int N, M; //정점 갯수, 간선 갯수
int stack[1010];
int top = -1;

void push(int cur)
{
	top++;
	stack[top] = cur; // stack에 1 저장
	visited[cur] = 1; //1은 방문 되었다.
	return;
}

void pop()
{
	top--;
	return;
}

void dfs(int cur)
{
	push(cur); //stack에 저장
	printf("%d ", cur);

	while (top >= 0)
	{
		for (int i = 1; i <= N; i++) //정점 갯수 7개 다 확인 한다. 
		{
			if (visited[i] == 0 && edge[stack[top]][i] == 1) //정점이 방문 되었지 않았거나, 
			{												 // 현재 스택에 저장된(1)과 연결된 간선이라면.
				push(i);									 // 2를 저장.
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

	for (int i = 0; i < M; i++) //간선 갯수
	{
		scanf("%d %d", &u, &v);
		edge[u][v] = 1; //인접 행렬 방식으로 그래프 저장
		edge[v][u] = 1; //★★양뱡항 그래프일 경우
	}
	dfs(1);

	return 0;
}