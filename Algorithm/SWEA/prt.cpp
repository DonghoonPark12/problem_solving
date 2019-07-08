#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int t, num[8], k;
	for (int tc = 1; tc <= 10; ++tc) {
		scanf("%d", &t);
		for (int i = 0; i<8; ++i) scanf("%d", num + i);

		k = 0;
		while (true) {
			num[k % 8] -= k % 5 + 1;
			if (num[k % 8] <= 0) break;
			k++;
		}
		/*
		배열 원소에 돌아가면서 1~5의 값을 빼준다. -= k%5 + 1
		원소는 idx가 8보다 크면 안된다. num[k%8]
		*/
		num[k % 8] = 0;
		printf("#%d", tc);
		for (int i = 1; i <= 8; ++i) 
			printf(" %d", num[(k + i) % 8]);
		printf("\n");
	}
}

#include <cstdio>
 
int main(void) {
    int T, i, j, a[8];
    for (T = 1; T <= 10; T++) {
        scanf("%d\n", &i);
        for (i = 0; i < 8; i++) {
            scanf("%d", &a[i]);
        }
        i = 0;
        while (1) {
            a[i % 8] -= (i % 5 + 1);
            if (a[i % 8] <= 0) {
                a[i % 8] = 0;
                i++;
                break;
            }
            i++;
        }
        printf("#%d", T);
        for (j = 0; j < 8; j++) {
            printf(" %d", a[(i + j) % 8]);
        }
        printf("\n");
    }
 
    return 0;
}