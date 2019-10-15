
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <math.h>
#define SIZE 51

using namespace std;

int arr[SIZE][SIZE];
bool visit[SIZE][SIZE];

// ���յ� �������� ������ ���� 
vector< pair<int, int> > nations;

int n, l, r, totalMove = 0;

int xarr[4] = { 1,-1,0,0 };
int yarr[4] = { 0,0,1,-1 };

// �α� �̵��� ���� ���� Ȯ���� �÷���
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
	// ������ �� �α����� ������ ���� 
	int totalPeople = arr[sx][sy];
	int totalNation = 1;

	while (!q.empty()) {
		pair<int, int> country = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			// ������ ������ ��ǥ 
			int near_x = country.first + xarr[i];
			int near_y = country.second + yarr[i];

			// ���� ���� ���� 
			if (!IsOpenBorder(country, near_x, near_y)) continue;
			// �̹� ���յ� ������� 
			if (visit[near_x][near_y]) continue;

			// ���� ������ �� ��� ť�� �־��ֱ� 
			q.push({ near_x, near_y });
			nations.push_back({ near_x, near_y });
			visit[near_x][near_y] = true;

			totalPeople += arr[near_x][near_y];
			totalNation++;
		}
	}
	// ���� ������ ���� ��� 
	if (totalNation == 1) { return; }

	// ��� �α��� 
	int avgPeople = totalPeople / totalNation;

	// �����鿡 ��� �α��� �Ҵ� 
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
	// ������ 2�� �̻��� ��쿡�� ��� 
	if (n > 1)
	{
		while (moveFlag) {
			moveFlag = false;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					// �湮�� ���� ���� ��쿡�� bfs
					if (!visit[i][j]) {
						visit[i][j] = true;
						BFS(i, j);

						// vector �ʱ�ȭ
						nations.clear();
					}
				}
			}

			// �̵��� ������ �� �ݺ��� Ż�� 
			if (!moveFlag) break;

			// �̵��� �־��� ���, totalMove�� 1 ���� 
			++totalMove;
			// visit �ʱ�ȭ 
			memset(visit, false, sizeof(visit));
		}
	}

	cout << totalMove << '\n';

	return 0;
}

