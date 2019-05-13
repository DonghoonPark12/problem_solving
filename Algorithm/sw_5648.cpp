#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int sum_e = 0;
		int n; //���� ����
		int _x, _y, _dir, _e;//�ϳ��� ���ڰ� ������ �ִ� ��ġ, ����, ������
		cin >> n;
		vector<vector<int>> arr(4002, vector<int> (4002));
		for (int i = 0; i < n; i++) {
			cin >> _x >> _y >> _dir >> _e;
			arr[_y*2 + 2000][_x*2 + 2000] = 10000 + _dir * 1000 + _e;
		}
		while (1) {
			// ������ �̵�
			for (int y = 1; y <= 4000;  y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					int tmp=0;
					if (arr[y][x] != 0) {
							tmp = arr[y][x];
							//���� �̵�
							if ( ((arr[y][x]-10000) / 1000 == 3) && (x != 4000)) {
								arr[y][x + 1] += tmp;
							}
							//���� �̵�
							else if ( ((arr[y][x]-10000) / 1000 == 2) && (x != 1)) {
								arr[y][x - 1] += tmp;
							}
							//�Ʒ� �̵�
							else if ( ((arr[y][x]-10000) / 1000 == 1) && (y != 4000)) {
								arr[y + 1][x] += tmp;
							}
							//���� �̵�
							else if( ((arr[y][x]-10000) / 1000 == 0) && (y != 1)){
								arr[y - 1][x] += tmp;
							}
							else { }
							arr[y][x] = 0;
					}
				}
			}
			//�ΰ� �̻��� �⵿�Ͽ��ٸ�, �Ҹ�.
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] / 10000 > 1) { // % -> /
						sum_e += arr[y][x] % 1000;
						arr[y][x] = 0;
					}
				}
			}

			int end_flag = 1;
			//���Ұ� ���� �ִ��� ���� Ȯ��
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] != 0)
						end_flag = 0;
				}
			}
			if (end_flag)
				break;
		}
		printf("#%d %d\n", t+1, sum_e);
	}
	return 0;
}