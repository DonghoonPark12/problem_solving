#include <iostream>
#include <queue>

using namespace std;

int T, tc, c, N, W, H;
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int arr[5][15][12];

void go(int D) {
	queue<int> q;
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (arr[D][i][j]) {
				q.push(arr[D][i][j]); 
				arr[D][i][j] = 0;
			}
		}
		for (int i = H - 1; q.size(); i--, q.pop()) 
			arr[D][i][j] = q.front();
	}
}

int dfs(int x, int y, int D) {
	int k = arr[D][x][y]; 
	int ans = 1; 
	arr[D][x][y] = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + i*dx[j]; 
			int ny = y + i*dy[j];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W || !arr[D][nx][ny]) 
				continue;
			ans += dfs(nx, ny, D);
		}
	}
	return ans;
}

int cal(int D) {
	if (D > N) 
		return 0; 
	int ans = 0;
	for (int i = 0; i < W; i++) {
		for (int m = 0; m < H; m++) 
			for (int n = 0; n < W; n++) 
				arr[D][m][n] = arr[D - 1][m][n]; //

		int tmp = 0; bool flg = 1;
		for (int j = 0; j < H; j++) {
			if (arr[D][j][i]) {
				flg = 0;
				tmp = dfs(j, i, D);
				break;
			}
		}
		if (flg) 
			continue;
		go(D); 
		ans = max(ans, cal(D + 1) + tmp);
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> N >> W >> H;
		int cnt = 0;
		for (int i = 0; i < H; i++) 
			for (int j = 0; j < W; j++) {
			cin >> c; arr[0][i][j] = c; 
			cnt += c ? 1 : 0;
		}
		cout << "#" << tc << " " << cnt - cal(1) << '\n';
	}
	return 0;
}