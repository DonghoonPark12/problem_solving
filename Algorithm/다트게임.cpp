#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int n, n_his, Ans;
	char b;
	char dart[10];

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%s", &dart);

	/*
	�� ���� �޴´�.
	�״��� �ΰ��� ���� �� �ɼ��� ������, �ι�° ���� ���� �ʴ´�.
	�׸��� ������ �޾Ƴ��� �ΰ��� ������ ����� ����
	*/
	int test_case;
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++) {

		for (int i = 0; i < 3; i++) {
			int opt = 0;
			int flag = 0;
			scanf("%1d", &n); //1 //*

			if (n <= 10 && n >= 0) {
				n_his = n;
			}

			if (n > 10) {
				flag = 1;
				opt = n;
			}

			if (!flag) {
				scanf("%1c", &b); //S

				if (b == 'S') {
					Ans += n;
				}
				else if (b == 'D') {
					Ans += n * n;
				}
				else { // B == 'S'
					Ans += n * n * n;
				}
				flag = 0;
			}

			if (opt) {
				if (opt == '*') {
					Ans -= n_his;
					Ans += n_his * 2;
				}
				else { // opt == #
					Ans -= n_his;
					Ans += n_his * (-1);
				}
			}
		}
	}
}
