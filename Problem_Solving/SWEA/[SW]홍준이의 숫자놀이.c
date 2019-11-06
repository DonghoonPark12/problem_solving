#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int A, B; //signed
		scanf("%d %d\n", &A, &B); //(1 ≤ A, B ≤ 109)

		float x=0, y=0; //signed
		x = (1 - B*y) / A; //y값을 모른다. 
		y = (1 - A*x) / B;


		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d %d\n", x, y);
	}

	return 0;

}