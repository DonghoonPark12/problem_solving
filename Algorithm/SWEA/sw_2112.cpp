#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_D 14
#define MAX_W 21
#define MAX_INF 987654321

int T;
int d, w, k;
int film[MAX_D][MAX_W];
int check[MAX_D][MAX_W];
int now_film[MAX_D][MAX_W];
int ans = MAX_INF;

void Initialize()
{
	for (int i = 0; i < MAX_D; i++)
	{
		for (int j = 0; j < MAX_W; j++)
		{
			film[i][j] = 0;
			now_film[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

int update(int row, int m, int msk)
{
	for (int i = 1; i <= w; i++)
	{
		int cur = m == -1 ? film[row][i] : m;

		if (now_film[row - 1][i] == cur)
			check[row][i] = check[row - 1][i] + 1;
		else
			check[row][i] = 1;

		now_film[row][i] = cur;

		// 연속된 셀의 개수가 k개 이상되면 해당 열의 성능 검사 통과를 저장한다.
		if (check[row][i] >= k)
			msk |= (1 << (i - 1));
	}

	return msk;
}

void Dfs(int row, int cnt, int msk)
{
	// 약품 투입을 저장 된 ans값보다 많이 하는 경우는 그냥 종료
	if (cnt >= ans) return;

	// 모든 검사가 끝났고 성능 검사를 통과하면 저장
	if (row == d + 1)
	{
		if (msk == (1 << w) - 1) ans = cnt;
		return;
	}

	// -1 : 투여 X, 0 : A 투여, 1 : B 투여
	for (int i = -1; i < 2; i++)
	{
		Dfs(row + 1, cnt + (i == -1 ? 0 : 1),
			update(row, i, msk));
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		Initialize();

		cin >> d >> w >> k;

		for (int i = 1; i <= d; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> film[i][j];
			}
		}

		ans = MAX_INF;

		Dfs(1, 0, 0);

		cout << "#" << test_case << " " << ans << "\n";

	}

	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int D, W, K;
//vector<vector<int>> arr(D, vector<int>(W));
//
//bool performance_check() {
//	int cur, prev;
//	int cnt;
//	vector<int> satisfy(W, 0);
//	for (int i = 0; i < W; i++) {
//		for (int j = 0; j < D; j++) {
//			cnt = 0;
//			cur = arr[j][i];
//			if (j != 0 && cur == prev) cnt++;
//			else if (j == 0) cnt++;
//			else if (cur != prev) cnt = 0;
//			else {}
//
//			if (cnt >= K) {
//				satisfy[i] = 1; //i, not j
//				break; //해당 D는 더이상 검사할 필요 없음.
//			}
//			prev = arr[j][i];
//		}
//	}
//
//	int sum = 0;
//	for (int i = 0; i < W; i++) {
//		sum += satisfy[i];
//	}
//	return sum == W ? true : false;
//}
//
//int main() {
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		cin >> D >> W >> K;
//
//		//Data input
//		for (int i = 0; i < D; i++) {
//			for (int j = 0; j < W; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//	}
//}