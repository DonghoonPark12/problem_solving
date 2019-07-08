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

		//ó������ ��� �ɻ�뿡 �ο� ����
		for (int i = 0; i < n; i++) {
			if (time[i] == 0)
				time[i] += ability[i];
		}

		int j_free;
		int min_idx;
		m = m - n;
		while (m--) {
			long long _min = 1000 * 1000 * 1000 * 1000 * 10; //�ɻ���� �ִ� �˻��ؾ� �ϴ� �ð��̴�.
			
			for (int j = 0; j < n; j++) {
				if (_min > time[j]) {
					_min = time[j]; 
					j_free = j; // j_free �� ����� ��ġ�ؾ� �ϴ� ��� �ɻ��
				}
			}

			vector<int> candid(n);
			min_idx = j_free;
			int _min2 = time[j_free] + ability[j_free]; //�� �ɻ�뿡 ����� ��ġ�� ��� �ɸ��� �ð�.
			for (int k = 0; k < n; k++) {
				if ((k != j_free) && (time[k] + ability[k] < time[j_free] + ability[j_free])) { //���� ��ٸ�����, �� �ɻ�� ���� ���� ���� ���
					////_min2 = time[k] + ability[k]; //�ϴ� ����.
					//if (_min2 < time[k] + ability[k]) //��, ���� ���� ���� ���
					//	time[k] += ability[k]; //����� ��ġ�Ѵ�. 
					candid[k] = 1; //�ĺ��� ������ Ȯ���ϰ�
				}
			}
			
			long long _min3 = 1000 * 1000 * 1000 * 1000 * 10;
			for (int l = 0; l < n; l++) {
				if(candid[l])
					if (time[l] + ability[l] < _min3) {
						_min3 = time[l] + ability[l];
						min_idx = l; // �� �߿����� ���� ���� ���� �� �ִ� �ĺ��� ã��
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
