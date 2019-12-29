/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define _max_int 21

using namespace std;

//�ð� ���⵵: O(n^4)
//���� ���⵵: O(n^2)
//����� �˰���: ����Ž�� by BFS, STL sorting
//����� �ڷᱸ��: �׷��� by 2���� �迭


int n, cur_x, cur_y, result, cur_size, cur_eat;
int d[_max_int][_max_int];
int check[_max_int][_max_int];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };


struct info {
	int x;
	int y;
	int dist;
};

//���� �� �ִ� ����� ������ ���� ���� v
vector<info> v;

//���� �� �ִ� ����⸦ ���ǿ� ���� �����Ѵ�.
bool cmp(const info &a, const info &b) {

	if (a.dist == b.dist) {

		if (a.x == b.x) {
			return a.y < b.y;
		}
		else return a.x < b.x;
	}
	else return a.dist < b.dist;
}

//����� ���� ��ġ���� �̵��� �� �ִ� ��� ���������� �Ÿ��� ����Ѵ�.
void find_dist(int x, int y) {

	check[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx<n && ny >= 0 && ny<n) {
				if (check[nx][ny] == 0 && d[nx][ny] <= cur_size) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	//1. ���� ���� �Է�
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &d[i][j]);
			if (d[i][j] == 9) {

				//����� ���� ��ġ ������Ʈ
				cur_x = i;
				cur_y = j;

				//���� ������ �����Ѵ�
				d[i][j] = 0;
			}
		}
	}

	//ó�� ���������� ����� ���� �ʱ�ȭ
	//����� ũ��� 2, ���� ������ 0
	cur_size = 2;
	cur_eat = 0;

	while (true) {

		//2. ����� ���� ��ġ���� �̵��� �� �ִ� ��� ���������� �Ÿ��� ����Ѵ�.
		find_dist(cur_x, cur_y);

		//3. ���� �� �ִ� ����⸦ ã�´�.
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {

				//ĭ�� ������ �ְ�, ���� �� ������
				if (d[i][j] > 0 && d[i][j] < cur_size) {

					//���� �� �ִ� ���������� �Ÿ�
					int dist = check[i][j];

					//��, ���� �� �ִ� �����������, ū ����⿡�� �ѷ��׿� �� ��������� �� �� �� �ִ�.
					//�� �� ���� ��쿡�� ���� �ʴ´�.
					if (dist > 0) v.push_back({ i, j, dist });
				}
			}
		}


		//4. ��� �̵�
		int fish_cnt = (int)v.size();

		//1) ���� �� �ִ� ����Ⱑ ���ٸ� ����
		if (fish_cnt == 0) {
			break;
		}
		else {

			//2) ���� �� �ִ� ����Ⱑ 1�������� ������
			if (fish_cnt > 1) sort(v.begin(), v.end(), cmp);

			int nx = v[0].x;
			int ny = v[0].y;
			int move_time = v[0].dist;

			//��� ũ�� ������Ʈ
			cur_eat++;
			if (cur_eat == cur_size) {
				cur_eat = 0;
				cur_size++;
			}

			//����� ��ġ ������Ʈ
			cur_x = nx;
			cur_y = ny;

			//���� ����
			d[nx][ny] = 0;

			//������ ���� �ʱ�ȭ
			v.clear();

			//üũ �迭 �ʱ�ȭ
			memset(check, 0, sizeof(check));

			//�ð� ������Ʈ
			result += move_time;
		}
	}
	printf("%d\n", result);

}
*/


#include <stdio.h>
#include <queue>
using namespace std;

struct SHARK {
	int y, x, time;
};

int n;
int map[20][20];

int shark_size, shark_eat;
SHARK shark;

const int dy[] = { 0, 0, -1, +1 };
const int dx[] = { -1, +1, 0, 0 };

int main()
{
	scanf("%d", &n);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}

	bool is_update = true;
	while (is_update) {
		is_update = false;

		bool visited[20][20] = { false, };
		queue<SHARK> q;
		visited[shark.y][shark.x] = true;
		q.push(shark);

		SHARK candi;
		candi.y = 20, candi.time = -1;
		while (!q.empty()) {
			SHARK cur = q.front();  q.pop();

			if (candi.time != -1 && candi.time < cur.time) {
				break;
			}

			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
				is_update = true;
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}

			for (int dir = 0; dir < 4; ++dir) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
					continue;
				}

				if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (is_update) {
			shark = candi;
			++shark_eat;
			if (shark_eat == shark_size) {
				++shark_size;
				shark_eat = 0;
			}
			map[shark.y][shark.x] = 0;
		}
	}

	printf("%d\n", shark.time);

	return 0;
}



