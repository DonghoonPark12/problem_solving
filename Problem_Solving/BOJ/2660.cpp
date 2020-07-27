#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

//int n;
//int adjM[51][51];
//queue<pair<int, int>> q;
//
//int arr[51];
////int* visited;
//int visited[51];
//int _min = 0x7fffffff;
//
//int bfs(int st)
//{
//	int len = 0;
//	q.push({ st, 0 });
//	visited[st] = 1;
//
//	while (q.empty() != 1) 
//	{
//		int cur = q.front().first;
//		int lvl = q.front().second;
//		len = lvl > len ? lvl : len;
//
//		for (int i = 1; i <= n; i++)
//		{
//			if (adjM[cur][i] == 1 && visited[i] != 1 && i!= cur)
//			{
//				q.push({ i, lvl + 1 });
//				visited[i] = 1;
//			}
//		}
//		q.pop();
//	}
//	
//	return len;
//}
//
//int main()
//{
//	cin >> n;
//	int v1, v2;
//
//	//int* arr = (int*)malloc(sizeof(int) * n);
//	while(1)
//	{
//		cin >> v1 >> v2;
//		if (v1 == -1 && v2 == -1)
//			break;
//		adjM[v1][v2] = 1;
//		adjM[v2][v1] = 1;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		//visited = (int*)malloc(sizeof(int) * n);
//		memset(visited, 0, sizeof(visited));
//		arr[i] = bfs(i);
//		_min = arr[i] < _min ? arr[i] : _min;
//		//free(visited);
//	}
//
//	int cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i] == _min)
//			cnt++;
//	}
//	printf("%d %d\n", _min, cnt);
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i] == _min)
//			printf("%d ", i);
//	}
//
//	//free(arr);
//	return 0;
//}

/* 플로이드 와샬 알고리즘 */

using namespace std;
#define INF 0x7fffffff
int dp[51][51];
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);

	int N, a, b; cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) 
				dp[i][j] = 0;
			else dp[i][j] = INF;
		}
	}
	while (1) 
	{
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (dp[s][m] != INF && dp[m][e] != INF) {
					dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
				}
			}
		}
	}

	/* 
		회장 후보 점수와 후보 수 출력 
		두 번째 줄에는 회장 후보를 오름차순으로 모두 출력
	*/
	vector<int> ans;
	int mmin = 1e9;
	for (int i = 1; i <= N; i++) {
		int tmp_max = -1;
		for (int j = 1; j <= N; j++) {
			tmp_max = max(tmp_max, dp[i][j]);
		}
		if (mmin == 1e9) {
			mmin = tmp_max;
			ans.push_back(i);
		}
		else {
			if (mmin < tmp_max) 
				continue;
			else if (mmin == tmp_max) 
				ans.push_back(i);
			else {
				ans.clear();
				mmin = tmp_max;
				ans.push_back(i);
			}
		}
	}
	cout << mmin << " " << ans.size() << "\n";
	for (const auto& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}
