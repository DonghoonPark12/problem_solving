#include <iostream>
#include <cstring>
//#include <vector>
using namespace std;

int ground[50][50];
int chk[50][50];
//vector<pair<int, int>> vp[2500];
int xy[2500][2];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int flag;
int ans;

bool is_boundary(int x, int y) {
	if (x >= 0 && x < 50 && y >= 0 && y < 50)
		return true;
	else
		return false;
}


void dfs(int x, int y) {
	//int x = ground[i][0];
	//int y = ground[i][1];
	
	if (chk[x][y] == 1)//이미 검사 되었으면 flag=1하지 않고 종료. 
		return;
	else
		flag = 1;

	chk[x][y] = 1; //대신에 ground[ax][ay] = 2로 하면 메모리 낭비를 줄일 수 있다. 
	               //ground[ax][ay] = 1 : 배추 있음, 방문 안함.
	               //ground[ax][ay] = 2 : 배추 있음, 방문함.

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if (is_boundary(ax, ay) && ground[ax][ay] == 1 && chk[ax][ay] != 1)
			dfs(ax, ay);
	}

	return;
}


int main() {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int m, n, k;
		cin >> m >> n >> k;
		memset(ground, 0, sizeof(ground));
		memset(chk, 0, sizeof(chk));
		memset(xy, 0, sizeof(xy));
		ans = 0;
		
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			xy[i][0] = x;
			xy[i][1] = y;
			ground[x][y] = 1;
		}


		for (int i = 0; i < k; i++) {
			dfs(xy[i][0], xy[i][1]);
			if (flag) ans++;
			flag = 0;
		}


		cout << ans << '\n';
	}
	return 0;

}