#include<iostream>
using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int N; //������ ����
		int K; //������ ����

		scanf("%d %d", &N, &K);

		int **arr = new int*[N];
		int *arr_K = new int[K]();

		for (int i = 0; i < N; i++) {// �ش� ����, ���� ����, ���� ����  -> ���ٸ� 1, K
			arr[i] = new int[3]{ 0 };
		}

		int num_of_zero = 0;
		int pront = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i][0]);
			if (arr[i][0] == 0) {
				if (i == 0) {// �� �� �޿��
					arr[i][0] = 1;
					arr_K[0]++;
					pront = 1;
				}
				else if (i == N - 1) {// �� �� �޿��
					arr[i][0] = K;
					arr_K[K - 1]++;
				}
				else {
					num_of_zero++;
					arr[i][1] = pront;
				}
			}
			else {
				arr_K[arr[i][0] - 1]++;
				pront = arr[i][0];
			}
		}
		int max_number = 0;
		if (num_of_zero == 0) {// 0 �� ���ٸ�
			for (int i = 0; i < K; i++) {
				if (max_number < arr_K[i]) {
					max_number = arr_K[i];
				}
			}
		}
		else {// 0 �� �����ϸ�
			for (int i = 0; i < N; i++) {
				if (arr[i][0] == 0) {
					int a = i;
					while (arr[a][0] == 0) {
						a++;
					}
					arr[i][2] = arr[a][0];
					if (arr[i][1] == arr[i][2]) {
						arr[i][0] = arr[i][2];
						arr_K[arr[i][0] - 1]++;
					}
				}
			}

			for (int i = 0; i < N; i++) {
				if (arr[i][0] == 0) {
					arr_K[arr[i][1] - 1]++;
					arr_K[arr[i][2] - 1]++;
				}
			}
			for (int i = 0; i < K; i++) {
				if (arr_K[i] == 0) {
					int a = i;
					if (i == 0) {
						while (arr_K[a] == 0) {
							a++;
						}
						arr_K[a]--;
					}
					else if (i == K - 1) {
						while (arr_K[a] == 0) {
							a--;
						}
						arr_K[a]--;
					}
					else {
						while (arr_K[a] == 0) {
							a--;
						}
						arr_K[a]--;
						a = i;
						while (arr_K[a] == 0) {
							a++;
						}
						arr_K[a]--;
					}
				}
			}
			for (int i = 0; i < K; i++) {
				if (max_number < arr_K[i]) {
					max_number = arr_K[i];
				}
			}
		}

		printf("#%d %d\n", test_case, max_number);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}