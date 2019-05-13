#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int h,m;
		int Ans_h = 0;
		int Ans_m = 0;
		for (int i = 0; i < 2; i++) {
			scanf(" %d %d", &h, &m);
			Ans_h += h; Ans_m += m;
			if (Ans_m >= 60) {
				Ans_h++;
				Ans_m -= 60;
			}
			if (Ans_h > 12) {
				Ans_h -= 12;
			}
		}



		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d %d\n", Ans_h, Ans_m);
	}

	return 0;

}