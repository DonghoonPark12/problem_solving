#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int M,N;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t = 0; t<T; t++) {
		int cnt = 0;
		M = 0; N = 0;
		scanf(" %d %d", &M,&N);

		while (1) {
			if (N == M) {
				cnt = -1; break;
			}

			cnt++;
			if ((N&1) ^ (M&1)) { //xor
				break;
			}
			N = N >> 1;
			M = M >> 1;
		}

		printf("%d\n", cnt);
	}
	//code
	return 0;
}