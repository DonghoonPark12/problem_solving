#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
/*
	간선 길이가 1인 그래프에서 최단 거리를 구하는 문제와 비슷하다?
	
*/
using namespace std;
int w, h;
int arr[1000][1000];
int time[1000][1000];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

bool possible() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

void bfs() {
	int cy, cx;
	while (!q.empty()) {
		cy = q.front().first;
		cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (arr[ny][nx] == -1 || ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}
	if (!possible()) {
		cout << -1;
	}
	else
		cout << arr[cy][cx]-1;
}
int main() {
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i, j });
		}
	}
	bfs();
	return 0;
}
// ★출발 지점을 저장하기 위해서는 queue를 전역으로 선언해서, 배열 입력시에 바로 넣어준다.
// ★출발 지점이 여러개라도, queue + bfs는 동시에 출발하면 된다.
// ★이동시 마다 arr[ny][nx] = arr[cy][cx] +1 하면 (레벨 혹은 시간) 역할을 하게 된다.
// ★마지막 지점 시간은 arr[cy][cx]가 될 것이다. 
// 왜냐하면 종료시점이 더이상 push하지 못할 때이며 이때 큐의 마지막 원소(cy, cx)의 값인 arr[cy][cx]가
// 최소 날짜가 될 것이기 때문이다.
/*
	return !printf("-1");는

	printf("-1");
	return 0;라는 뜻이다. 
	참나..ㅋㅋㅋ
*/
