#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX 350
#define BASE 150

typedef struct pos {
	int vital;
	int x, y;
}POS;

int container[MAX][MAX] = { 0, };
int dx[] = { 0,0,1,-1 };//동서남북
int dy[] = { 1,-1,0,0 };//동서남북

int main()
{
	freopen("input.txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, K;
		queue <POS> q[11];
		int ans = 0;
		cin >> N >> M >> K;
		memset(container, 0, sizeof(container));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> container[i + BASE][j + BASE];
				if (container[i + BASE][j + BASE]) {
					POS first;
					first.vital = container[i + BASE][j + BASE] * 2; //why *2??
					first.x = i + BASE, first.y = j + BASE;
					q[container[i + BASE][j + BASE]].push(first);
				}
			}
		}//입력완료

		for (int i = 0; i <= K; i++) {
			for (int j = 10; j >= 1; j--) {
				int size = q[j].size();
				for (int k = 0; k < size; k++) {

					auto x = q[j].front(); q[j].pop();
					if (x.vital>j) {
						if (container[x.x][x.y] > 0) {
							ans++;
							container[x.x][x.y] = -container[x.x][x.y];
						}
						q[j].push({ x.vital - 1,x.x,x.y });
					}//비활성

					else if (x.vital == j) {
						q[j].push({ x.vital - 1,x.x,x.y });
						for (int z = 0; z < 4; z++) {
							int nx = x.x + dx[z];
							int ny = x.y + dy[z];
							if (container[nx][ny]) continue;
							container[nx][ny] = j;
							q[j].push({ x.vital * 2,nx,ny });
						}
					}//확장 + 활성

					else if (x.vital < j && x.vital) {
						q[j].push({ x.vital - 1,x.x,x.y });
					}//확장 이후 활성

					else { ans--; }//죽음
				}
			}
		}
		cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


//#include <iostream>
//#include <queue>
//using namespace std;
//
//#define MAXL 352
//struct data_type {
//	//0: 빈 공간, 1: 비활성 상태, 2: 활성 상태, 3: 죽은 상태
//	int status;
//	//LP
//	//HP: 죽은 상태: 0, 비활성 상태일 경우 증가, 활성 상태일 경우 감소
//	int LP, HP;
//}Map[2][MAXL][MAXL];
//
//int T, N, M, K;
//data_type Map[2][MAXL][MAXL];
//
//int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
//
//int main() {
//		int T, test_case;
//		freopen("input.txt", "r", stdin);
//		setbuf(stdout, NULL);
//	
//		scanf("%d", &T);
//		for (test_case = 0; test_case < T; test_case++)
//		{
//			int Answer = 0;
//			cin >> N >> M >> K;
//			//init
//			for (int i = 0; i < N + K + 2; i++) { //9
//				for (int j = 0; j < M + K + 2; j++) { //10
//					Map[0][i][j].status = 0;
//					Map[1][i][j].status = 0;
//				}
//			}
//
//			//초기 줄기 세포의 Life Point
//			for (int i = 0 + K / 2 + 1; i < N + K / 2 + 1; i++) {
//				for (int j = 0 + K / 2 + 1; j < M + K / 2 + 1; j++) {
//					cin >> Map[0][i][j].LP;
//					if (Map[0][i][j].LP > 0) {
//						Map[0][i][j].status = 1;
//						Map[0][i][j].HP = 0;
//					}
//				}
//			}
//			N = N + K + 2;
//			M = M + K + 2;
//
//			int CurMap = 0;
//			for (int k = 0; k < K; k++) {
//				for (int i = 0; i < N; i++) {
//					for (int j = 0; j < M; j++) {
//						//죽은 세포일 경우
//
//					}
//				}
//			}
//		}
//}
//

//
//struct node{
//	int x, y;
//	node(int _x, int _y)
//		:x(_x), y(_y)
//	{}
//};
//
//int N, M, K;
//int cell[351][351];
//queue<int> q;
//
//void bfs(int y, int x) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if(cell[i][j])
//				bfs_util(i, j, 0);
//		}
//	}
//}
//void bfs_util(int y, int x, int t) {
//	q.push(node(x, y));
//	while (!q.empty()) {
//		if (t != cell[y][x]) {
//			t++;
//		}
//		else {
//			if (cell[y][x - 1] != 0) {
//				cell[y][x - 1] = cell[y][x];
//				q.push()
//			}
//			if (cell[y][x + 1] != 0)
//				cell[y][x + 1] = cell[y][x];
//			if (cell[y - 1][x] != 0)
//				cell[y - 1][x] = cell[y][x];
//			if (cell[y + 1][x] != 0)
//				cell[y + 1][x] = cell[y][x];
//		}
//	}
//}
//int main(void)
//{
//	int T, test_case;
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int Answer = 0;
//		cin >> N >> M >> K;
//		for (int i = 0; i < N; i++) { //9
//			for (int j = 0; j < M; j++) { //10
//				cin >> cell[175 - (N/2) +i][175 - (M/2) + j];
//			}
//		}
//		bfs(175 - (N/2), 175 - (M/2));
//		
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				cin >> cell[i][j];
//			}
//		}
//
//		printf("#%d ", test_case + 1);
//		printf("%d\n", Answer);
//	}
//
//	return 0;
//
//}