#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define QUEUE_SIZE 10001
#define MAX_VERTEX_COUNT 10001

#define IS_VISITED 1
#define NOT_VISITED 0

int queue[QUEUE_SIZE];
int front;
int rear;

int isEmpty();
int inFull();
void enQueue(int item);
int deQueue();
void createQueue();
int Qpeek();

int N, M; //정점과 간선
int u, v;

int adjacent[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
int visited[MAX_VERTEX_COUNT];
int visitingVertex;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		for (int i = 0; i <= N; i++) {
			visited[i] = NOT_VISITED;
			for (int j = 0; j <= N; j++) {
				adjacent[i][j] = 0;
			}
		}

		scanf("%d %d", &N, &M); //정점과 간선 갯수

		// 연결 여부 파악
		for (int i = 0; i < M; i++) //간선 갯수
		{
			scanf("%d %d", &u, &v);
			adjacent[u][v] = 1; //인접 행렬 방식으로 그래프 저장
			adjacent[v][u] = 1; //★★양뱡항 그래프일 경우
		}

		//큐 생성
		createQueue();

		//첫 시작점인 정점1을 큐에 넣고, 방문한 것으로 표시
		enQueue(1);
		visited[1] = IS_VISITED;

		while (isEmpty() == 0) {
			visitingVertex = deQueue();
			printf("%d ", visitingVertex);

			//인접한 정점을 찾는다. 
			for (int i = 1; i <= N; i++) {
				if (adjacent[visitingVertex][i] == 1 && visited[i] == 0) {
					enQueue(i);
					visited[i] = IS_VISITED;
				}
			}
		}
		printf("\n");
	}

	return 0;
}

/*
1 2
1 3
2 4
2 5
4 6
5 6
3 7
*/