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
		P: A���� 1���ʹ� ���
		Q: B���� R���� ���� ���
		S: B���� R���� �ʰ��� 1���ʹ� ���
		W: �Ѵް� ����ϴ� ������

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


