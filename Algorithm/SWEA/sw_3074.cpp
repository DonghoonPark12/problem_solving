#define	_CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> ability(n);
		vector<int> time(n);
		for (int i = 0; i < n; i++) {
			cin >> ability[i];
		}

		//처음에는 모든 심사대에 인원 배정
		for (int i = 0; i < n; i++) {
			if (time[i] == 0)
				time[i] += ability[i];
		}

		int j_free;
		int min_idx;
		m = m - n;
		while (m--) {
			long long _min = 1000 * 1000 * 1000 * 1000 * 10; //심사대의 최대 검사해야 하는 시간이다.
			
			for (int j = 0; j < n; j++) {
				if (_min > time[j]) {
					_min = time[j]; 
					j_free = j; // j_free 는 사람을 배치해야 하는 노는 심사대
				}
			}

			vector<int> candid(n);
			min_idx = j_free;
			int _min2 = time[j_free] + ability[j_free]; //그 심사대에 사람을 배치할 경우 걸리는 시간.
			for (int k = 0; k < n; k++) {
				if ((k != j_free) && (time[k] + ability[k] < time[j_free] + ability[j_free])) { //조금 기다리더라도, 그 심사대 보다 빨리 끝날 경우
					////_min2 = time[k] + ability[k]; //일단 보류.
					//if (_min2 < time[k] + ability[k]) //또, 가장 빨리 끝날 경우
					//	time[k] += ability[k]; //사람을 배치한다. 
					candid[k] = 1; //후보군 몇인지 확인하고
				}
			}
			
			long long _min3 = 1000 * 1000 * 1000 * 1000 * 10;
			for (int l = 0; l < n; l++) {
				if(candid[l])
					if (time[l] + ability[l] < _min3) {
						_min3 = time[l] + ability[l];
						min_idx = l; // 그 중에서도 가장 빨리 끝낼 수 있는 후보군 찾고
					}
			}

			if (j_free != min_idx)
				time[min_idx] += ability[min_idx];
			else
				time[j_free] += ability[j_free];

		}


		printf("#%d ", test_case + 1);
		printf("%d\n", time[j_free] > time[min_idx] ? time[j_free] : time[min_idx]);
	}
	return 0;
}
