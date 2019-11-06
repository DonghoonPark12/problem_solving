#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool visited[11];
int len;
int __max = 0;
void dfs(int s, vector<vector<int>> m) {
	len++;
	if (len > __max) __max = len;
	visited[s] = true;
	for (int i = 1; i < m.size(); i++) {
		if (visited[i] == false && m[s][i] == 1) {//방문하지 않았고, 간선이 연결되어 있다면.
			dfs(i, m);
			len--;
		}
	}
	visited[s] = false;
}
int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n+1, vector<int>(n+1));
		int v1, v2;
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			matrix[v1][v2] = 1;
			matrix[v2][v1] = 1;
		}
		//for (int s = 1; s < matrix.size(); s++) {
		//	len = 0; __max = 0;
		//	dfs(s, matrix);
		//	//dfs(1, matrix);

		//	memset(visited, false, sizeof(visited));
		//}
		
		len = 0; __max = 0;
		dfs(1, matrix);
		memset(visited, false, sizeof(visited));

		printf("#%d ", test_case + 1);
		printf("%d\n", __max);
	}

	return 0;

}



#include <iostream> 
#include "vector"
using namespace std;

int N, M, ans;
int vis[15];
vector <int> g[15];

void dfs(int x, int len) {
	if (ans < len) ans = len;
	vis[x] = 1;
	for (int i = g[x].size() - 1; i >= 0; i--) {
		if (!vis[g[x][i]]) 
			dfs(g[x][i], len + 1);
	}
	vis[x] = 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (; T--;) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++) {
			int x, y; scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans = 0;
		for (int i = 1; i <= N; i++) {
			dfs(i, 1);
		}
		static int tc = 0;
		printf("#%d %d\n", ++tc, ans);
		for (int i = 1; i <= N; i++) g[i].clear();
	}
}