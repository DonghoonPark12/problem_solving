#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 21
#define MIN_INF -987654321

int N, M;
int city[MAX_N][MAX_N];
int memo[MAX_N + 1];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

int ans;

void InitailzeMemo(){
	for (int i = 1; i <= MAX_N; i++)
		memo[i] = i*i + (i - 1)*(i - 1);
}

bool IsRange(int x, int y){
	return 0 <= x && x < N && 0 <= y && y < N;
}

void Bfs(int start_x, int start_y)
{
	queue<pair<int, int>> q;
	bool visited[MAX_N][MAX_N] = {};

	visited[start_x][start_y] = true;
	q.push(make_pair(start_x, start_y));

	int q_size;
	int depth = 1;
	int house_cnt = city[start_x][start_y] == 1 ? 1 : 0;

	while (!q.empty()){
		q_size = q.size();

		// 수익이 운영 비용보다 많을 경우
		if (house_cnt*M >= memo[depth])	{
			ans = max(ans, house_cnt);
		}

		if (depth == N + 1) return;

		while (q_size--){
			int x = q.front().first, y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)	{
				int nx = x + dx[k], ny = y + dy[k];

				// 범위를 벗어나거나 방문한 곳은 가지 않는다
				if (!IsRange(nx, ny) || visited[nx][ny]) continue;

				visited[nx][ny] = true;
				if (city[nx][ny] == 1)
					house_cnt++;
				q.push(make_pair(nx, ny));
			}
		}
		depth += 1;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	InitailzeMemo();

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				cin >> city[i][j];
			}
		}

		ans = MIN_INF;
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				Bfs(i, j);
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}


#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

//#define MAX 21
using namespace std;

int T, N, M, ans;
//int MAP[MAX][MAX];
int city[21][21];
vector<pair<int, int> > v;

typedef struct _node {
	int x, y, t;
	_node(int _x, int _y, int _t)
		:x(_x), y(_y), t(_t)
	{}
}Node;

queue<Node> q;


//void init()
//{
//	v.clear();
//	memset(MAP, 0, sizeof(MAP));
//	ans = 0;
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> MAP[i][j];
//			if (MAP[i][j] == 1)
//			{
//				v.push_back(make_pair(i, j));
//			}
//		}
//	}
//}

void home(int x, int y)
{
	int nCost = 0;
	for (int k = 1; k <= 2 * N - 1; k++)//What is the meaning of 2*N - 1??
	{
		int nCnt_home = 0;
		nCost = k * k + (k - 1)*(k - 1);

		for (int i = 0; i < v.size(); i++)
		{
			int ndist = abs(v[i].first - x) + abs(v[i].second - y);
			if (ndist < k)
				nCnt_home++;
		}

		if (nCnt_home * M >= nCost)
		{
			if (ans < nCnt_home) ans = nCnt_home;
		}
	}
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			home(i, j);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		v.clear();
		memset(city, 0, sizeof(city));
		ans = 0;

		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> city[i][j];
				if (city[i][j] == 1)
				{
					v.push_back(make_pair(i, j));
				}
			}
		}
		//Node n(1,2,3);
		////n.x = 1; n.y = 2; n.t = 3;

		//q.push(n);

		Solve();
		cout << "#" << tc << " " << ans << endl;
	}

	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//#define MAX_N 21
//#define MIN_INF -987654321
//
//int N, M;
//int city[MAX_N][MAX_N];
//int memo[MAX_N + 1];
//
//
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { -1, 1, 0, 0 };
//
//int ans;
//
//void InitailzeMemo()
//{
//	for (int i = 1; i <= MAX_N; i++)
//		memo[i] = i*i + (i - 1)*(i - 1);
//}
//
//bool IsRange(int x, int y)
//{
//	return 0 <= x && x < N && 0 <= y && y < N;
//}
//
//void Bfs(int start_x, int start_y)
//{
//	queue<pair<int, int>> q;
//	bool visited[MAX_N][MAX_N] = {};
//
//	visited[start_x][start_y] = true;
//	q.push(make_pair(start_x, start_y));
//
//	int q_size;
//	int depth = 1;
//	int house_cnt = city[start_x][start_y] == 1 ? 1 : 0;
//
//	while (!q.empty())
//	{
//		q_size = q.size();
//
//		// 수익이 운영 비용보다 많을 경우
//		if (house_cnt*M >= memo[depth])
//		{
//			ans = max(ans, house_cnt);
//		}
//
//		if (depth == N + 1) return;
//
//		while (q_size--)
//		{
//			int x = q.front().first, y = q.front().second;
//			q.pop();
//
//			for (int k = 0; k < 4; k++)
//			{
//				int nx = x + dx[k], ny = y + dy[k];//왼, 오, 아, 위
//
//				// 범위를 벗어나거나 방문한 곳은 가지 않는다
//				if (!IsRange(nx, ny) || visited[nx][ny]) continue;
//
//				visited[nx][ny] = true;
//				if (city[nx][ny] == 1)
//					house_cnt++;
//				q.push(make_pair(nx, ny));
//			}
//		}
//
//		depth += 1;
//	}
//
//}
//
//int main()
//{
//	//ios::sync_with_stdio(false);
//	//cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	InitailzeMemo();
//
//	int T;
//
//	cin >> T;
//
//	for (int tc = 1; tc <= T; tc++)
//	{
//
//		cin >> N >> M;
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				cin >> city[i][j];
//			}
//		}
//
//		ans = MIN_INF;
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				Bfs(i, j);
//			}
//		}
//
//		cout << "#" << tc << " " << ans << "\n";
//	}
//
//	return 0;
//}