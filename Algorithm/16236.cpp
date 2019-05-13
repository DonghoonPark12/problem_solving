#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define max_int 21

using namespace std;

//�ð� ���⵵: O(n^4)
//���� ���⵵: O(n^2)
//����� �˰���: ����Ž�� by BFS, STL sorting
//����� �ڷᱸ��: �׷��� by 2���� �迭


int n, cur_x, cur_y, result, cur_size, cur_eat;
int d[max_int][max_int];
int check[max_int][max_int];
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
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//// �������� ������ �־���. ��ͷ� ���� ��ġ���� ���� ����� ���̸� ã���� ��͸� �̿��ϴµ�, 
//// 
//int arr[20][20];
//int cur_weight = 2;
//int eat = 0;
//int cur_x, cur_y;
//int clock = 0;//��� ���� �� �ִ� �ð� ī��Ʈ �Ѵ�.
//int meet_nearest_feed(int cur_yy, int cur_xx, int N) {
//	if (arr[cur_yy][cur_xx] != 0 && arr[cur_yy][cur_xx] <= cur_weight) {
//		cur_y = cur_yy; cur_x = cur_xx; return clock; //���� ��ġ���� ���� ����� ���̸� ã���� ��ġ ����ϸ鼭 ���� 
//	}
//	// N*N�� �Ѿ�� �Ϳ� ����, �켱 ������ ���� �̵�.
//	if (cur_yy - 1 >=0 && arr[cur_yy - 1][cur_xx] !=0 && arr[cur_yy - 1][cur_xx] <= cur_weight) {
//		if (arr[cur_yy - 1][cur_xx] == cur_weight) cur_weight++;
//		cur_y = cur_yy; cur_x = cur_xx; return clock; } //1 
//	if (cur_xx - 1>=0 && arr[cur_yy][cur_xx - 1]!=0 && arr[cur_yy][cur_xx - 1] <= cur_weight) {
//		if (arr[cur_yy][cur_xx - 1] == cur_weight) cur_weight++;
//		cur_y = cur_yy; cur_x = cur_xx; return clock; } //2 
//	if (cur_xx + 1<N && arr[cur_yy][cur_xx + 1]!=0 && arr[cur_yy][cur_xx + 1] <= cur_weight) {
//		if (arr[cur_yy][cur_xx + 1] == cur_weight) cur_weight++;
//		cur_y = cur_yy; cur_x = cur_xx; return clock; } //3 
//	if (cur_yy + 1<N && arr[cur_yy + 1][cur_xx]!=0 && arr[cur_yy + 1][cur_xx] <= cur_weight) {
//		if (arr[cur_yy + 1][cur_xx] == cur_weight) cur_weight++;
//		cur_y = cur_yy; cur_x = cur_xx; return clock; } //4 
//	//if (cur_yy - 1 >=0 && cur_xx - 1 >=0 && arr[cur_yy - 1][cur_xx - 1]!=0 && arr[cur_yy - 1][cur_xx - 1] <= cur_weight) {
//	//	if (arr[cur_yy - 1][cur_xx - 1] == cur_weight) cur_weight++;
//	//	cur_y = cur_yy; cur_x = cur_xx; return; }//5 
//	//if (cur_yy - 1 >=0 && cur_xx + 1 <N && arr[cur_yy - 1][cur_xx + 1]!=0 && arr[cur_yy - 1][cur_xx + 1] <= cur_weight) {
//	//	if (arr[cur_yy - 1][cur_xx + 1] == cur_weight) cur_weight++;
//	//	cur_y = cur_yy; cur_x = cur_xx; return; }//6 
//	//if (cur_xx - 1 >= 0 && cur_yy + 1 <N && arr[cur_yy + 1][cur_xx - 1]!=0 && arr[cur_yy + 1][cur_xx - 1] <= cur_weight) {
//	//	if (arr[cur_yy + 1][cur_xx - 1] == cur_weight) cur_weight++;
//	//	cur_y = cur_yy; cur_x = cur_xx; return; }//7 
//	//if (cur_yy + 1 <N && cur_xx + 1<N && arr[cur_yy + 1][cur_xx + 1]!=0 && arr[cur_yy + 1][cur_xx + 1] <= cur_weight) {
//	//	if (arr[cur_yy + 1][cur_xx + 1] == cur_weight) cur_weight++;
//	//	cur_y = cur_yy; cur_x = cur_xx; return; }//8 
//
//	// 2�� �̵� ������ ���� ��ġ���� �˻��Ѵ�. 
//	clock++;
//
//	if(cur_yy - 1 >= 0)
//		meet_nearest_feed(--cur_yy, cur_xx,N);
//	if(cur_xx - 1 >= 0)
//		meet_nearest_feed(cur_yy, --cur_xx,N);
//	if(cur_yy + 1 < N)
//		meet_nearest_feed(++cur_yy, cur_xx, N);
//	if (cur_xx + 1 < N)
//		meet_nearest_feed(cur_yy, ++cur_xx, N);
//}
//int main() {
//	int N;
//	freopen("input.txt", "r", stdin);
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//		}
//	}
// 
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (arr[i][j] == 9) {
//				cur_y = i;
//				cur_x = j;
//			}
//		}
//	}
//	 
//	int sum = 0;
//	while (1) {
//		//���� ����
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				sum += arr[i][j];
//			}
//		}
//		if (sum == 9) {
//			return clock;
//		}
//
//		meet_nearest_feed(cur_y, cur_x,N);
//		cur_x = 0; cur_y = 0; //���̸� ������ 0���� �ٲ۴�. 
//
//	}
//}