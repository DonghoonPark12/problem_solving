//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//struct node {
//	int y, x, time;
//	node(int _y, int _x, int _time)
//		:y(_y), x(_x), time(_time)
//	{};
//};
////vector<vector<int>> arr(50, vector<int>(50));
//int arr[51][51];
//bool visited[51][51];
//queue<node> q;
//int p;
//int N, M, R, C, L;

//void bfs(int r, int c) {//세로 위치R, 가로 위치C
//	q.push(node(r, c, 1));
//	visited[r][c] = true;
//	
//	while (!q.empty()) {
//		int r = q.front().y;
//		int c = q.front().x;
//		int t = q.front().time;
//		q.pop();
//
//		if (t == L)
//			continue;
//
//		if (arr[r][c] == 1) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1));  visited[r][c + 1] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1));  visited[r + 1][c] = true; }
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//		}
//		else if (arr[r][c] == 2) { // |
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1)); visited[r + 1][c] = true; }
//		}
//		else if (arr[r][c] == 3) { // -
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1));  visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 4) {
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1)); visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 5) {
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1)); visited[r + 1][c] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1)); visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 6) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1));  visited[r + 1][c] = true; }
//		}
//		else if (arr[r][c] == 7) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//		}
//		else {}
//	}
//
//}

//int get_result() {
//	int sum = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (visited[i][j])
//				sum++;
//		}
//	}
//	return sum ;
//}

//void init() {
//	memset(arr, 0, sizeof(arr));
//	memset(visited, false, sizeof(visited));
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
//		init();
//		cin >> N >> M >> R >> C >> L;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				cin>>arr[i][j];//c, r
//			}
//		}
//		//bfs(R, C);
//
//		while (!q.empty()) q.pop();
//		printf("#%d ", test_case + 1);
//		printf("%d\n", get_result());
//	}
//
//	return 0;
//
//}

//#include <cstdio>
//
//int map[50][50];
//int chk[50][50];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int pipe[8][4] = {
//	{ 0,0,0,0 },  //0
//	{ 1,1,1,1 },  //1
//	{ 0,1,0,1 },  //2
//	{ 1,0,1,0 },  //3
//	{ 1,0,0,1 },  //4
//	{ 1,1,0,0 },  //5
//	{ 0,1,1,0 },  //6
//	{ 0,0,1,1 }   //7
//};
//
//int T, N, M, R, C, L;
//int result;
//
//void dfs(int x, int y, int b_x, int b_y, int time)
//{
//	int X, Y;
//	if (chk[x][y] != 1)
//	{
//		result++;
//		chk[x][y] = 1;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		X = x + dx[i];
//		Y = y + dy[i];
//		/*
//			X, Y가 세로, 가로 범위를 벗어나거나, 본래 자리로 돌아 오거나, 
//			map[X][Y] == 0 || pipe[map[x][y]][i] == 0  ??
//			pipe[map[X][Y]][(i + 2) % 4] == 0          ??
//			time + 1 > L							   ??
//		*/
//		if (X < 0 || X >= N || Y < 0 || Y >= M || (X == b_x && Y == b_y) || map[X][Y] == 0 || pipe[map[x][y]][i] == 0 ||
//			pipe[map[X][Y]][(i + 2) % 4] == 0 || time + 1 > L)
//			continue;
//		dfs(X, Y, x, y, time + 1);
//	}
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &T);
//	for (int t = 1; t <= T; t++)
//	{
//		result = 0;
//		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				scanf("%d", &map[i][j]);
//				chk[i][j] = 0;
//			}
//		}
//		dfs(R, C, 0, 0, 1);
//		printf("#%d %d\n", t, result);
//	}
//	return 0;
//}

#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

int t, n, m, sx, sy, l, x, y, ax, ay, time, cnt;
int map[50][50];
bool visited[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct Node {
	int x;
	int y;
	int time;
	Node(int _x, int _y, int _time)
		: x(_x), y(_y), time(_time)
	{ }
};

int getResult() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

void bfs(int a, int b) {
	queue<Node> q;
	q.push(Node(a, b, 1));
	visited[a][b] = true;

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		time = q.front().time;
		q.pop();

		if (time == l) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			ax = x + dx[i];
			ay = y + dy[i];
			if (ax >= 0 && ay >= 0 && ax < n && ay < m) {
				// i : 0=하,1=상,2=우,3=좌
				// stat :
				// 1 : 상하좌우
				// 2 : 상하
				// 3 : 좌우
				// 4 : 상우
				// 5 : 우하
				// 6 : 좌하
				// 7 : 좌상
				if (!visited[ax][ay]) {                                          // 이동하려는 새로운 map위치 ax, ay
					if (map[x][y] == 2) {if (i == 2 || i == 3) continue; }       //│ 경우 우, 좌 이동 불가
					else if (map[x][y] == 3) { if (i == 0 || i == 1) continue; } //─ 경우 하, 상 이동 불가
					else if (map[x][y] == 4) { if (i == 0 || i == 3) continue; } //└ 경우 하, 좌 이동 불가
					else if (map[x][y] == 5) { if (i == 1 || i == 3) continue; } //┌ 경우 상, 좌 이동 불가
					else if (map[x][y] == 6) { if (i == 1 || i == 2) continue; } // ┐경우 상, 우 이동 불가
					else if (map[x][y] == 7) { if (i == 0 || i == 2) continue; } // ┘경우 하, 우 이동 불가

					if (i == 0) {												 //하 일 경우, 
						if (map[ax][ay] == 1 || map[ax][ay] == 2 || map[ax][ay] == 4 || map[ax][ay] == 7) { //┼,│,└ , ┘만 통과 가능.   
							q.push(Node(ax, ay, time + 1)); visited[ax][ay] = true;
						}
					}
					else if (i == 1) {											 //상
						if (map[ax][ay] == 1 || map[ax][ay] == 2 || map[ax][ay] == 5 || map[ax][ay] == 6) { //┼,│,┌ ,┐ 만 통과 가능.
							q.push(Node(ax, ay, time + 1)); visited[ax][ay] = true;
						}
					}
					else if (i == 2) {											 //우
						if (map[ax][ay] == 1 || map[ax][ay] == 3 || map[ax][ay] == 6 || map[ax][ay] == 7) {//┼,─, ┐, ┘ 만 통과 가능.   
							q.push(Node(ax, ay, time + 1)); visited[ax][ay] = true;
						}
					}
					else {														 //좌
						if (map[ax][ay] == 1 || map[ax][ay] == 3 || map[ax][ay] == 4 || map[ax][ay] == 5) {//┼,─,└,┌   만 통과 가능.  
							q.push(Node(ax, ay, time + 1)); visited[ax][ay] = true;
						}
					}
				}
			}
		}
	}
}

void init() {
	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		init();

		scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &l);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		bfs(sx, sy);

		printf("#%d %d\n", tc, getResult());
	}
}
