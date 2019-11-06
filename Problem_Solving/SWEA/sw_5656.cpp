#include <stdio.h>
#include <algorithm>

using namespace std;

int cnt;
int W, H;
int arr[15][12];
int num = 0;

int destruct(int a, int b, int T[][12])
{
	int ret = 0;
	int temp = T[a][b];
	if (temp == 0)
	{
		return 0;
	}
	else if (temp == 1)
	{
		ret = 1;
		T[a][b] = 0;
	}
	else
	{
		ret = 1;
		T[a][b] = 0;
		for (int i = 1; i<temp; i++)
		{
			if (a - i >= 0)
			{
				ret += destruct(a - i, b, T);
			}
			if (a + i<H)
			{
				ret += destruct(a + i, b, T);
			}
			if (b - i >= 0)
			{
				ret += destruct(a, b - i, T);
			}
			if (b + i<W)
			{
				ret += destruct(a, b + i, T);
			}
		}
	}
	return ret;
}

void down(int T[][12])
{
	for (int i = 0; i<W; i++)
	{
		int count = 0;
		for (int j = H - 1; j >= 0; j--)
		{
			if (T[j][i] == 0)
				count++;
			else if (count != 0)
			{
				T[j + count][i] = T[j][i];
				T[j][i] = 0;
			}
		}
	}
}

int dfs(int N, int a, int b, int M[][12])
{
	cnt++;
	int tmp = cnt;
	int ret = 0;
	int T[15][12];

	for (int i = 0; i<H; i++)
		for (int j = 0; j<W; j++)
			T[i][j] = M[i][j];

	ret = destruct(a, b, T);

	down(T);
	if (tmp == N)
	{
		return ret;
	}
	else
	{
		int temp2 = 0;
		for (int i = 0; i<W; i++)
		{
			for (int j = 0; j<H; j++)
			{
				if (T[j][i] != 0)
				{
					cnt = tmp;
					int temp = dfs(N, j, i, T);
					if (temp>temp2)
					{
						temp2 = temp;
					}
					break;
				}
			}
		}
		ret += temp2;
	}
	return ret;
}

void init() {
	for (int i = 0; i<H; i++)
		for (int j = 0; j<W; j++)
			arr[i][j] = 0;

	for (int i = 0; i<H; i++)
	{
		for (int j = 0; j<W; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
				num++;
		}
	}
}


int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d %d %d", &N, &W, &H);
	
		int ans = 0;
		init();

		for (int i = 0; i<W; i++)
		{
			for (int j = 0; j<H; j++)
			{
				if (arr[j][i] != 0)
				{
					C = 0;
					int ret = dfs(N, j, i, arr);
					if (ret>ans)
						ans = ret;
					break;
				}
			}
		}
		printf("#%d %d\n", t, num - ans);
	}
}


//
//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<cstdio>
//
//using namespace std;
//int deps, N, W, H, ori[5][15][12], pmap[15][12], height[5][12], tempheight[12], tempsum, sum;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//void sim();
//void play(const int & i, const int & j);
//void correct(const int &);
//
//void correct(const int & deps) {
//	int temp[15] = { 0 };
//	int ind = 0;
//	for (int j = 0; j < W; j++) {
//		ind = 0;
//		memset(temp, 0, sizeof(temp));
//		for (int i = H - 1; i > -1; i--) {
//			if (pmap[i][j]) {
//				temp[ind++] = pmap[i][j];
//				pmap[i][j] = 0;
//			}
//		}
//		for (int i = 0; i < ind; i++) {
//			pmap[H - 1 - i][j] = temp[i];
//		}
//		height[deps][j] = ind;
//	}
//}
//
//void play(const int & i, const int & j) {
//	int cnt = pmap[i][j], x, y;
//	pmap[i][j] = 0;
//	for (int dir = 0; dir < 4; dir++) {
//		for (int dist = 1; dist < cnt; dist++) {
//			x = dist * dx[dir] + i; y = dist * dy[dir] + j;
//			if (x<0 || x>H - 1 || y<0 || y>W - 1)
//				continue;
//			if (pmap[x][y] > 1) {
//				play(x, y);
//			}
//			else
//				pmap[x][y] = 0;
//		}
//	}
//
//}
//
//void sim() {
//	tempsum = 0;
//	for (int j = 0; j < W; j++)
//		tempsum += height[deps][j];
//
//	//if (tempsum < 23)
//	//  cout << ' ';
//
//	if (tempsum == 0 || deps == N) {
//		//if (sum > tempsum)
//		//  cout << "update";
//		sum = tempsum < sum ? tempsum : sum;
//	}
//	else if (deps<N) {
//		deps++;
//		for (int j = 0; j < W; j++) {
//			if (!height[deps - 1][j])
//				continue;
//			memcpy(pmap, ori[deps - 1], sizeof(ori[0]));
//			if (pmap[H - height[deps - 1][j]][j] < 2) {
//				pmap[H - height[deps - 1][j]][j] = 0;
//				memcpy(height[deps], height[deps - 1], sizeof(height[0]));
//				height[deps][j]--;
//			}
//			else {
//				play(H - height[deps - 1][j], j);
//				correct(deps);
//			}
//			memcpy(ori[deps], pmap, sizeof(ori[0]));
//			sim();
//		}
//		deps--;
//	}
//
//
//}
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		memset(ori, 0, sizeof(ori));   
//		memset(height, 0, sizeof(height));
//		cin >> N >> W >> H;
//		for (int i = 0; i < H; i++) {
//			for (int j = 0; j < W; j++) {
//				cin >> ori[0][i][j];
//				if (!height[0][j] && ori[0][i][j]) {
//					height[0][j] = H - i;
//				}
//			}
//		}
//
//		deps = 0;   sum = W * H;
//		sim();
//
//		cout << '#' << test_case << ' ' << sum << '\n';
//	}
//	return 0;}

//#define	_CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//int arr[15][12];
//int N, W, H;
//int x[4] = { 1,-1, 0, 0 };
//int y[4] = { 0, 0, 1, -1 };
//
//for (int i = 0; i > -arange; i++) {
//	tmp = arr[i][j];
//	for (int j = -arange + 1; j < j + arange; j++) {
//		arr[i][j] = 0;
//	}
//	if(tmp != 0)
//		Boom_and_delete(int arr[])
//
//	
//}
//void destruct(int col) {
//	int i = 0;
//	while (arr[i][col] != 0) {
//		i++;
//	}
//	boom(i, col);
//}
//
//bool is_boundary(int x, int y) {
//	if (x >= 0 && x < H && y >= 0 && y < W)
//		return true;
//	else
//		false;
//}
//
//void boom(int x, int y) {
//	//int i = 0;
//	int num = arr[x][y];
//	if (num != 1) {
//		for (int c = 0; c < 4; c++) {
//			//int nx = x + ax[c];
//			//int ny = y + ay[c];
//			switch (c) {
//				case 0:{ //왼
//					int i = 0;
//					while (i!=num && is_boundary(x + i, y)) {
//						arr[x + i][y] = 0;
//						i++;
//					}
//					break;
//				}
//				case 1: { //오
//					int i = 0;
//					while (i != num && is_boundary(x - i, y)) {
//						arr[x - i][y] = 0;
//						i++;
//					}
//					break;
//				}
//				case 2: { //아
//					int i = 0;
//					while (i != num && is_boundary(x, y + i)) {
//						arr[x][y + i] = 0;
//						i++;
//					}
//					break;
//				}
//				case 3: { //위
//					int i = 0;
//					while (i != num && is_boundary(x, y - i)) {
//						arr[x][y - i] = 0;
//						i++;
//					}
//					break;
//				}
//				default:
//				{}
//			}
//
//		}
//	}
//	else
//		arr[x][y] = 0;
//}
//
//
//void init() {
//	memset(arr, 0, sizeod(arr));
//
//	cin >> N >> W >> H;
//
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//}
//
//void get_result() {
//	int cnt = 0;
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			if (arr[i][j] != 0) cnt++;
//		}
//	}
//}
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	freopen("input.txt", "r", stdin);
//	cin >> T;
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		init();
//
//		destruct(col);
//
//		int min = 12*15;
//
//		if (cnt < min)
//			min = cnt;
//
//		cout << '#' << test_case << ' ' << get_result() << endl;
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}



//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int T, tc, c, N, W, H;
//int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
//int arr[5][15][12];
//
//void go(int D) {
//	queue<int> q;
//	for (int j = 0; j < W; j++) {
//		for (int i = H - 1; i >= 0; i--) {
//			if (arr[D][i][j]) {
//				q.push(arr[D][i][j]);
//				arr[D][i][j] = 0;
//			}
//		}
//		for (int i = H - 1; q.size(); i--, q.pop())
//			arr[D][i][j] = q.front();
//	}
//}
//
//int dfs(int x, int y, int D) {
//	int k = arr[D][x][y];
//	int ans = 1;
//	arr[D][x][y] = 0;
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < 4; j++) {
//			int nx = x + i*dx[j];
//			int ny = y + i*dy[j];
//			if (nx < 0 || ny < 0 || nx >= H || ny >= W || !arr[D][nx][ny])
//				continue;
//			ans += dfs(nx, ny, D);
//		}
//	}
//	return ans;
//}
//
//int cal(int D) {
//	if (D > N)
//		return 0;
//	int ans = 0;
//	for (int i = 0; i < W; i++) {
//		for (int m = 0; m < H; m++)
//			for (int n = 0; n < W; n++)
//				arr[D][m][n] = arr[D - 1][m][n]; //
//
//		int tmp = 0; bool flg = 1;
//		for (int j = 0; j < H; j++) {
//			if (arr[D][j][i]) {
//				flg = 0;
//				tmp = dfs(j, i, D);
//				break;
//			}
//		}
//		if (flg)
//			continue;
//		go(D);
//		ans = max(ans, cal(D + 1) + tmp);
//	}
//	return ans;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> T;
//	for (tc = 1; tc <= T; tc++) {
//		cin >> N >> W >> H;
//		int cnt = 0;
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++) {
//				cin >> c; arr[0][i][j] = c;
//				cnt += c ? 1 : 0;
//			}
//		cout << "#" << tc << " " << cnt - cal(1) << '\n';
//	}
//	return 0;
//}