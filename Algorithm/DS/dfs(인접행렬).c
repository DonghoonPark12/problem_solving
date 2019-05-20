/* 
O(V+E)
DFS에서 발전한 기법이 BackTracking
재귀 함수를 통해 구현되는 경우가 많다. 
*/

#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int edge[1010][1010];
int visited[1010]; //visited라는 배열을 따로 만들어서, 방문 되었다면 1로 두는 방식은 탁월하다. 
int u, v; //시작 정점, 도착 정점 
int N, M; //정점 갯수, 간선 갯수

void dfs(int cur)
{
	visited[cur] = 1;
	printf("%d", cur);
	for (int i = 1; i <= N; i++) //정점 갯수(한 지점 마다, 모드 정점 1 ~ 7까지 확인은 한다...)
	{
		if (visited[i] != 0 || edge[cur][i] == 0)
			continue; //이미 방문 되었거나(||), 간선이 연결되어있지 않다면 (Pruning)
		dfs(i);
		/*
		//방문이 안되었으면서(&&)간선이 존재한다면
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

	for (int i = 0; i < M; i++) //간선 갯수
	{
		scanf("%d %d", &u, &v);
		edge[u][v] = 1; //인접 행렬 방식으로 그래프 저장
	    edge[v][u] = 1; //★★양뱡항 그래프일 경우
	}
	dfs(1);

	return 0;
}
