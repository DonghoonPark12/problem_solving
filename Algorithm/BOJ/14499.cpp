#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int sx[5] = { 0, 0, 0, -1, 1 };
int sy[5] = { 0, 1, -1, 0, 0 };
int arr[20][20];
//int order[1000];
int order;
int n, m, x, y, k;
//vector<pair<int, int>> dice;
int dice[7];

void init() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dice, 0, sizeof(dice));
}

bool is_boundary(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	else
		return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	init();

	for (int i = 0; i < k; i++) {
		cin >> order;
		int ax = x + sx[order];
		int ay = y + sy[order];

		if (is_boundary(ax, ay)) {
			x = ax, y = ay;
			switch (order) {
			case(1): { //��
				int tmp = dice[3];
				int tmp2 = dice[6];
				int tmp3 = dice[4];

				dice[3] = dice[1]; //1�� ��ġ�� �� --> 3�� ��ġ�� ��
				dice[6] = tmp;     //3�� ��ġ�� �� --> 6�� ��ġ�� ��
				dice[4] = tmp2;    //6�� ��ġ�� �� --> 4�� ��ġ�� ��
				dice[1] = tmp3;    //4�� ��ġ�� �� --> 1�� ��ġ�� ��
				break;
			}
			case(2): {//��
				int tmp = dice[1];
				int tmp2 = dice[4];
				int tmp3 = dice[6];

				dice[1] = dice[3];
				dice[4] = tmp;
				dice[6] = tmp2;
				dice[3] = tmp3;
				break;
			}
			case(3): {//��
				int tmp = dice[2];
				int tmp2 = dice[6];
				int tmp3 = dice[5];

				dice[2] = dice[1];
				dice[6] = tmp;
				dice[5] = tmp2;
				dice[1] = tmp3;
				break;
			}
			case(4): {//��
				int tmp = dice[5];
				int tmp2 = dice[6];
				int tmp3 = dice[2];

				dice[5] = dice[1];
				dice[6] = tmp;
				dice[2] = tmp2;
				dice[1] = tmp3;
				break;
			}
			}
		}
		else
			continue;
		if (arr[x][y] == 0) {
			arr[x][y] = dice[6]; //dice �عٴ� idx�� ���� �ʿ� �Ѱ��ش�.
		}
		else {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}
		cout << dice[1] << '\n';
	}

	return 0;
}