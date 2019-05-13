#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[16];
int arr1[16];
int arr2[16];

void deci_to_bi(int n) {
	int tmp[16] = { 0 };
	int i = 0;
	while (n) {
		tmp[i++] = n % 2;
		n /= 2;
	}

	for (int j = i - 1; j >= 0; j--) {
		if (tmp[j]) {
			printf("#");
		}
		else
			printf(" ");
	}
}
int main() {
	int t;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int test_case; scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		int n;  scanf("%d ", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d, ", arr1 + i);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d, ", arr2 + i);
		}

		for (int i = 0; i < n; i++) {
			arr[i] = arr1[i] | arr2[i];
		}

		for (int i = 0; i < n; i++) {
			deci_to_bi(arr[i]);
			printf("\n");
		}

		//arr1, arr2 배열 초기화도 들어가야 한다. 

	}

}
