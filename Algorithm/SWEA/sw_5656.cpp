//#define	_CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
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
//void Boom(int arr[], int N, int W, int H) {
//
//}
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	/*
//	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
//	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
//	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
//	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
//	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
//	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
//	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
//	*/
//	freopen("input.txt", "r", stdin);
//	cin >> T;
//	/*
//	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
//	*/
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		int N, W, H;
//		int tmp = 0;
//		int arr[15][12];
//		for (int i = 0; i < 15; i++) { for (int j = 0; j < 12; j++) { arr[i][j] = 0; } }
//		cin >> N >> W >> H;
//		for (int i = 0; i < H; i++) { 
//			for (int j = 0; j < W; j++) { 
//				cin >> tmp; arr[i][j] = tmp; 
//			} 
//		}
//
//
//		int min = 12*15;
//		int cnt = 0;
//		for (int i = 0; i < H; i++) {
//			for (int j = 0; j < W; j++) {
//				if (arr[i][j] != 0) cnt++;
//			}
//		}
//		if (cnt < min)
//			min = cnt;
//
//
//
//		cout << '#' << test_case << ' ' << min << endl;
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}



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