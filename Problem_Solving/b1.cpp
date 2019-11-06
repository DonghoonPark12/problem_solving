#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int N;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d",&T);
	for (int t = 0; t<T; t++) {
		int cnt = 0;
		N = 0;
		scanf(" %d", &N);

		while (1) {
			if (N == 0) break;

			cnt++;
			if (N & 1) {
				break;
			}
		    N = N >> 1;

		}

		printf("%d\n",cnt);
	}
	//code
	return 0;
}