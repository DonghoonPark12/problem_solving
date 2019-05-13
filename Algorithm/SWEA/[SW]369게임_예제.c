#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1. 테스트 케이스 먼저 만들 것.
// 3 13 31 44 36 103 130 350 136 309 360 999 1000

int clap(int n)
{
	int clap = 0;
	while (n != 0)
	{
		int t = n%10; // 중복 연산을 피하기 위함
		if ((t == 3) || (t == 6) || (t == 9))
		{
			clap++;//박수치는 횟수
		}
		n /= 10; 
	}
	return clap;
}

int main(void)
{
	setbuf(stdout, NULL);
	int n,temp;
	scanf("%d", &n);
	
	for (int j = 1; j <= n; j++)
	{
		if (clap(j) > 0)
		{
			temp = clap(j);//Memoization
			for (int i = 0; i < temp; i++)
			{
				printf("-");
			}
			printf(" ");
		}
		else
		{
			printf("%d ", j);
		}
	}

	return 0;
}

/* 배열에 넣는 방법도 있다. */

int N = 0;  // 정수N까지 숫자 369 게임
char buf[5] = { 0 };

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int flag = 0;
		sprintf(buf, "%d", i);
		if ((buf[0] == '3') || (buf[0] == '6') || (buf[0] == '9')) flag++;
		if ((buf[1] == '3') || (buf[1] == '6') || (buf[1] == '9')) flag++;
		if ((buf[2] == '3') || (buf[2] == '6') || (buf[2] == '9')) flag++;

		if (flag == 3) printf("---");
		else if (flag == 2) printf("--");
		else if (flag == 1) printf("-");
		else printf("%d", i);

		if (i != N) printf(" ");
	}
}
