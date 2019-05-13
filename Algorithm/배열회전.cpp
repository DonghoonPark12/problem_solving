#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[7][7];

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int test_case;  scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		int n; scanf(" %d", &n);

		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &tmp); arr[i][j] = tmp;
			}
		}
		printf("#%d\n", t + 1);
		for (int i = 0; i < n; i++) {

			for (int y1 = n - 1; y1 >= 0; y1--) {
				printf("%d", arr[y1][i]);
			}
			printf(" ");
			for (int x1 = n - 1; x1 >= 0; x1--) {
				printf("%d", arr[n - 1 - i][x1]);
			}
			printf(" ");
			for (int y1 = 0; y1 < n; y1++) {
				printf("%d", arr[y1][n-1-i]);
			}
			printf("\n");
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0;
			}
		}
	}

	return 0;
}
