#include <iostream>
using namespace std;
/*
	int** arr = new int*[y];
	for(int i = 0; i < y; ++i)
		arr[i] = new int[x];

	for(int i = 0; i < y; ++i) {
		delete [] arr[i];
	}
	delete [] arr;

	https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
*/
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0,-1,  0, 1};
//int dot[101][101];
//int da[9][3];

//int check() {
//	int ans = 0;
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 100; j++) {
//			if (dot[i][j] && dot[i + 1][j] && dot[i][j + 1] && dot[i + 1][j + 1])
//				ans++;
//		}
//	}
//	return ans;
//}
//void go(int x, int y, int d, int g) {
//	//int **da = new int *[8];
//	//for (int i = 0; i < 8; i++) {
//	//	da[i] = new int[3];
//	//}
//	memset(da, 0, sizeof(da));
//	da[0][0] = x; da[0][1] = y; da[0][2] = d;
//	if (g == 0) {
//		da[1][0] = x + ax[da[0][2]]; da[1][1] = y + ay[da[0][2]]; da[1][2] = (da[0][2] + 1) % 4;
//	}
//	else if (g == 1) {
//		da[1][0] = x + ax[da[0][2]];		da[1][1] = y + ay[da[0][2]];		da[1][2] = (da[0][2] + 1) % 4;
//		da[2][0] = da[1][0] + ax[da[1][2]]; da[2][1] = da[1][1] + ay[da[1][2]]; da[2][2] = (da[1][2] + 1) % 4;
//	}
//	else if (g == 2) {
//		da[1][0] = x + ax[da[0][2]];		da[1][1] = y + ay[da[0][2]];		da[1][2] = (da[0][2] + 1) % 4;
//		da[2][0] = da[1][0] + ax[da[1][2]]; da[2][1] = da[1][1] + ay[da[1][2]]; da[2][2] = (da[1][2] + 1) % 4;
//		da[3][0] = da[2][0] + ax[da[2][2]]; da[3][1] = da[2][1] + ay[da[2][2]]; da[3][2] = (da[0][2] + 1) % 4;
//		da[4][0] = da[3][0] + ax[da[3][2]]; da[4][1] = da[3][1] + ay[da[3][2]]; da[4][2] = (da[3][2] + 1) % 4;
//	}
//	else { //g==3
//		da[1][0] = x + ax[da[0][2]];		da[1][1] = y + ay[da[0][2]];		da[1][2] = (da[0][2] + 1) % 4;
//		da[2][0] = da[1][0] + ax[da[1][2]]; da[2][1] = da[1][1] + ay[da[1][2]]; da[2][2] = (da[1][2] + 1) % 4;
//		da[3][0] = da[2][0] + ax[da[2][2]]; da[3][1] = da[2][1] + ay[da[2][2]]; da[3][2] = (da[0][2] + 1) % 4;
//		da[4][0] = da[3][0] + ax[da[3][2]]; da[4][1] = da[3][1] + ay[da[3][2]]; da[4][2] = (da[3][2] + 1) % 4;
//		da[5][0] = da[4][0] + ax[da[4][2]]; da[5][1] = da[4][1] + ay[da[4][2]]; da[5][2] = (da[2][2] + 1) % 4;
//		da[6][0] = da[5][0] + ax[da[5][2]]; da[6][1] = da[5][1] + ay[da[5][2]]; da[6][2] = (da[1][2] + 1) % 4;
//		da[7][0] = da[6][0] + ax[da[6][2]]; da[7][1] = da[6][1] + ay[da[6][2]]; da[7][2] = (da[0][2] + 1) % 4;
//		da[8][0] = da[7][0] + ax[da[7][2]]; da[8][1] = da[7][1] + ay[da[7][2]]; da[8][2] = (da[7][2] + 1) % 4;
//
//	}
//
//	for (int i = 0; i < 8; i++) {
//		dot[da[i][1]][da[i][0]] = 1;
//	}
//
//}

//int main() {
//	freopen("input.txt", "r", stdin);
//	int n; cin >> n;
//	int x, y, d, g;
//	//int **d= new int *[n];
//	//for (int i = 0; i < n; i++) {
//	//	d[i] = new int[4];
//	//}
//	//for (int i = 0; i < 3; i++) {
//	//	cin>>d[i][0]>>d[i][1]>>d[i][2]>>
//	//}
//	for (int i = 0; i < n; i++) {
//		cin >> x >> y >> d >> g;
//		go(x, y, d, g);
//	}
//	int ans = check();
//	cout << ans << endl;
//	return 0;
//}



