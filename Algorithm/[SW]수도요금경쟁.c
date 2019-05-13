#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		int p, q, r, s, w, A, B;
		scanf("%d %d %d %d %d", &p, &q, &r, &s, &w);
		/*
		P: A사의 1리터당 요금
		Q: B사의 R리터 이하 요금
		S: B사의 R리터 초과시 1리터당 요금
		W: 한달간 사용하는 수도양

		A = P * W;

		B
		if(W<=R)
		B = Q
		else
		B = Q + (W-R)*S;
		*/


		A = w * p;

		if (r >= w)
			B = q; 
		else
			B = q + (w - r) * s;

		if (A >= B)
			printf("#%d %d\n", test_case, B);
		else
			printf("#%d %d\n", test_case, A);
	}
	return 0;
}


