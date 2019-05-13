#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int sum_e = 0;
		int n; //원자 갯수
		int _x, _y, _dir, _e;//하나의 원자가 가지고 있는 위치, 방향, 에너지
		cin >> n;
		vector<vector<int>> arr(4002, vector<int> (4002));
		for (int i = 0; i < n; i++) {
			cin >> _x >> _y >> _dir >> _e;
			arr[_y*2 + 2000][_x*2 + 2000] = 10000 + _dir * 1000 + _e;
		}
		while (1) {
			// 원자의 이동
			for (int y = 1; y <= 4000;  y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					int tmp=0;
					if (arr[y][x] != 0) {
							tmp = arr[y][x];
							//우측 이동
							if ( ((arr[y][x]-10000) / 1000 == 3) && (x != 4000)) {
								arr[y][x + 1] += tmp;
							}
							//좌측 이동
							else if ( ((arr[y][x]-10000) / 1000 == 2) && (x != 1)) {
								arr[y][x - 1] += tmp;
							}
							//아래 이동
							else if ( ((arr[y][x]-10000) / 1000 == 1) && (y != 4000)) {
								arr[y + 1][x] += tmp;
							}
							//위로 이동
							else if( ((arr[y][x]-10000) / 1000 == 0) && (y != 1)){
								arr[y - 1][x] += tmp;
							}
							else { }
							arr[y][x] = 0;
					}
				}
			}
			//두개 이상이 출동하였다면, 소멸.
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] / 10000 > 1) { // % -> /
						sum_e += arr[y][x] % 1000;
						arr[y][x] = 0;
					}
				}
			}

			int end_flag = 1;
			//원소가 남아 있는지 여부 확인
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