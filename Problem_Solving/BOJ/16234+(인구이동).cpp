
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <math.h>
#define SIZE 51

using namespace std;

int arr[SIZE][SIZE];
bool visit[SIZE][SIZE];

// 연합된 국가들을 저장할 벡터 
vector< pair<int, int> > nations;

int n, l, r, totalMove = 0;

int xarr[4] = { 1,-1,0,0 };
int yarr[4] = { 0,0,1,-1 };

// 인구 이동이 끝난 것을 확인할 플래그
bool moveFlag = true;

bool IsOpenBorder(pair<int, int> &country, int near_x, int near_y) {
	if (near_x < 0 || near_x >= n || near_y < 0 || near_y >= n) return false;
	int diff = (arr[country.first][country.second] - arr[near_x][near_y]);
	diff = diff < 0 ? diff * (-1) : diff;
	if (l > diff || r < diff) return false;
	return true;
}

void BFS(int sx, int sy) {
	queue< pair<int, int> > q;

	q.push({ sx, sy });
	nations.push_back({ sx, sy });
	// 연합의 총 인구수를 저장할 변수 
	int totalPeople = arr[sx][sy];
	int totalNation = 1;

	while (!q.empty()) {
		pair<int, int> country = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			// 인접한 국가의 좌표 
			int near_x = country.first + xarr[i];
			int near_y = country.second + yarr[i];

			// 국가 개방 여부 
			if (!IsOpenBorder(country, near_x, near_y)) continue;
			// 이미 연합된 국가라면 
			if (visit[near_x][near_y]) continue;

			// 국가 개방이 된 경우 큐에 넣어주기 
			q.push({ near_x, near_y });
			nations.push_back({ near_x, near_y });
			visit[near_x][near_y] = true;

			totalPeople += arr[near_x][near_y];
			totalNation++;
		}
	}
	// 연합 국가가 없는 경우 
	if (totalNation == 1) { return; }

	// 평균 인구수 
	int avgPeople = totalPeople / totalNation;

	// 국가들에 평균 인구수 할당 
	for (int i = 0; i < nations.size(); ++i) {
		arr[nations[i].first][nations[i].second] = avgPeople;
	}
	moveFlag = true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	// 국가가 2개 이상인 경우에만 고려 
	if (n > 1)
	{
		while (moveFlag) {
			moveFlag = false;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					// 방문한 적이 없는 경우에만 bfs
					if (!visit[i][j]) {
						visit[i][j] = true;
						BFS(i, j);

						// vector 초기화
						nations.clear();
					}
				}
			}

			// 이동이 없었을 시 반복문 탈출 
			if (!moveFlag) break;

			// 이동이 있었던 경우, totalMove를 1 증가 
			++totalMove;
			// visit 초기화 
			memset(visit, false, sizeof(visit));
		}
	}

	cout << totalMove << '\n';

	return 0;
}

