#define	_CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

int t = 1;

int main() {
	freopen("input.txt", "r", stdin);
	int T, tc;
	int Answer = 0;
	scanf("%d", &T);
	for (tc = 0; tc < T; tc++) {
		int n; cin >> n;
		vector<vector<int>> arr(n, vector<int>(n));
		//1. x++ -> y++ 
		//2. x-- -> y--
		int turn = 0;
		int len = n;
		int x = -1; int y = 0;
		int num = 1;
		//for (int i = 0; i < n; i++) {
		//	if (turn == 0) {
		//		for (int j = 0; j < len; j++) {
		//			if (x < len) x++;
		//			arr[y][x] = num;
		//			num++;
		//		}
		//		for (int j = 0; j < len-1; j++) {
		//			if (y >= 0) y++;
		//			arr[y][x] = num;
		//			num++;
		//		}
		//		len--;
		//	}
		//	if (turn == 1) {
		//		for (int j = 0; j < len; j++) {
		//			if (x >= 0) x--;
		//			arr[y][x] = num;
		//			num++;
		//		}
		//		for (int j = 0; j < len-1; j++) {
		//			if (y <= len) y--;
		//			arr[y][x] = num;
		//			num++;
		//		}
		//		len--;
		//	}
		//	if (turn == 0) turn = 1;
		//	else turn = 0;
		//}

		int value = 1; // 배열을 채워 나갈 값 
		int row = 0, col = -1; // 행(row), 열(col) B을 나타내는 index 
		int inc = 1; // index 의 증감량을 나타냄. 1 또는 -1 을 가질 수 있음 

		int nn = n;
		while (n > 0) {
			for (int i = 0; i < n; i++) {
				col += inc;
				arr[row][col] = value;
				value++;
			}
			n--;
			if (n == 0) break;
			for (int i = 0; i < n; i++) {
				row += inc;
				arr[row][col] = value;
				value++;
			}
			inc *= -1;
		}

		cout << '#' << tc+1 << endl;
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < nn; j++) {
				cout << arr[i][j]<<' ';
			}
			cout << '\n';;
		}
	}
	return 0;
}