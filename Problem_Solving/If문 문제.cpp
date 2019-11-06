#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* 
* 0<= N <=99
* <10 라면 0X로 만들고 각 자리수 더한다.
* 
*/
int main()
{
	int N;
	scanf("%d", &N); //26

	int cnt = 0;
	int New = N;
	while (1)
	{
		/*
		int f = New / 10 ; //앞 // 2
		int b = New % 10 ; //뒤 // 6

		if(f+b<10)
			New = b * 10 + (f + b); //60 + 8
		else
			New = b * 10 + (f + b)%10; // if 문 안써도 1의 자리만 필요하면 %10 해준다. 

		*/
		New = (New % 10) * 10 + (New / 10 + New % 10) % 10;
		cnt++;

		if (New == N ) break;

	}
	printf("%d", cnt);

	return 0;
}