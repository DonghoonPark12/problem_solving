#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;
/*
	[실수한 부분]
	Conncect배열을 평균 값을 넣어줄 때에도 사용하였다. 하지만 2차원 배열에서 연결되지 않은 연합 국가가 있을 수 있다.

	이럴 경우 이미 연합되어 인구 이동을 했던 국가에 새로운 mid 값이 또 대입된다.
	
	다음과 같은 문제를 해결하기 위해 연합이 일어날 때 마다 united 벡터를 만들어서 연합이 이루어 지고 난 후 united 벡터내에 존재하는 
	위치에서만 mid 값을 갱신해 준다. 

*/
int n, l, r;
int arr[100][100];
int con[100][100];
vector<pair<int, int>> united;
int ans; 
int cnt; //연합되는 국가 수 카운트
int sum; // 연합 인구수 더하는 변수

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int bfs(int i, int j);
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		bool moved = false;
		memset(con, 0, sizeof(con));

		/*-----------------------------------------------------------------------*/
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (con[i][j] == 0) {
					//cnt = 1; 
					int population = bfs(i, j) / cnt;
					/*-----------------------------------------------------------*/
					if (united.size()> 1){
						//for (int i = 0; i < n; i++) {
						//	for (int j = 0; j < n; j++) {
						//		if (con[i][j])
						//			arr[i][j] = population;
						//	}
						//}
						for (int i = 0; i < united.size(); i++) {
							arr[united[i].first][united[i].second] = population;
						}
						//united.clear();
						moved = true;
					}
					united.clear(); cnt = 0;
					/*-----------------------------------------------------------*/
				}

			}
		}
		/*-----------------------------------------------------------------------*/
		if (moved) ans++;
		else break;

	}

	cout << ans;
	return 0;
}

int bfs(int y, int x) {
	con[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });
	united.push_back({ y, x });
	int population = arr[y][x];

	cnt++;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
			if (con[ny][nx] == 1) continue;
			if (abs(arr[cy][cx] - arr[ny][nx]) >=l && abs(arr[cy][cx] - arr[ny][nx]) <= r) {
				q.push({ ny, nx });
				cnt++;
				con[ny][nx] = 1;//★
				population += arr[ny][nx];
				united.push_back({ ny, nx });
			}
		}
	}
	return population;
}

