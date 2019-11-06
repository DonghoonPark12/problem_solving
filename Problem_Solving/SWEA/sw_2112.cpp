#include <iostream>
#include <algorithm>

using namespace std;

#define _max_D 14
#define _max_W 21
#define _max_INF 987654321

int T;
int d, w, k;
int film[_max_D][_max_W];
int check[_max_D][_max_W];
int now_film[_max_D][_max_W];
int ans = _max_INF;

void Initialize()
{
	for (int i = 0; i < _max_D; i++)
	{
		for (int j = 0; j < _max_W; j++)
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

		// ���ӵ� ���� ������ k�� �̻�Ǹ� �ش� ���� ���� �˻� ����� �����Ѵ�.
		if (check[row][i] >= k)
			msk |= (1 << (i - 1));
	}

	return msk;
}

void Dfs(int row, int cnt, int msk)
{
	// ��ǰ ������ ���� �� ans������ ���� �ϴ� ���� �׳� ����
	if (cnt >= ans) return;

	// ��� �˻簡 ������ ���� �˻縦 ����ϸ� ����
	if (row == d + 1)
	{
		if (msk == (1 << w) - 1) ans = cnt;
		return;
	}

	// -1 : ���� X, 0 : A ����, 1 : B ����
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

		ans = _max_INF;

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
//				break; //�ش� D�� ���̻� �˻��� �ʿ� ����.
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

/*
https://wjdgus2951.tistory.com/92
https://flack3r.tistory.com/entry/sw-expert%EB%AA%A8%EC%9D%98sw%EC%97%AD%EB%9F%89%ED%85%8C%EC%8A%A4%ED%8A%B8-%EB%B3%B4%ED%98%B8%ED%95%84%EB%A6%84
https://jongnan.tistory.com/entry/SW-Expert-2112-%EB%B3%B4%ED%98%B8-%ED%95%84%EB%A6%84
http://blog.naver.com/PostView.nhn?blogId=1ilsang&logNo=221349369691&categoryNo=50&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=1
https://yobs0814.github.io/2018-10-20/SWEA2112
*/
