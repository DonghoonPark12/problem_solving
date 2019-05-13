#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define S(n) ( ((long long)(n)) * ((n)+1)/2)

long long Ans;
int T, N, K;

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T); 
	for (int t = 1; t <= T; t++) {
		int y = 0, x = 0; Ans = 1;

		scanf("%d%d", &N, &K); 
		for (char str; K; K--) {
			scanf(" %c", &str);
			if ('U' == str) y--; 
			if ('R' == str) x++; 
			if ('D' == str) y++; 
			if ('L' == str) x--;

			//Ans += ((y + x < N) ? (S(y + x + 1) - (((y + x) % 2) ? x : y)) : ((long long)N*N - S(2 * N - y - x - 2) - N + 1 + (((y + x) % 2) ? y : x)));
			if (y + x < N)
				if ((y + x) % 2)
					Ans += S(y + x + 1) - x;
				else
					Ans += S(y + x + 1) - y;
			else
				if((y + x) % 2)
					Ans += (long long)N*N - S(2 * N - y - x - 2) - N + 1 + y;
				else
					Ans += (long long)N*N - S(2 * N - y - x - 2) - N + 1 + x;
		
		}
		printf("Case #%d\n%lld\n", t, Ans);
	}
	return 0;
}