#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* 
* 0<= N <=99
* <10 ��� 0X�� ����� �� �ڸ��� ���Ѵ�.
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
		int f = New / 10 ; //�� // 2
		int b = New % 10 ; //�� // 6

		if(f+b<10)
			New = b * 10 + (f + b); //60 + 8
		else
			New = b * 10 + (f + b)%10; // if �� �Ƚᵵ 1�� �ڸ��� �ʿ��ϸ� %10 ���ش�. 

		*/
		New = (New % 10) * 10 + (New / 10 + New % 10) % 10;
		cnt++;

		if (New == N ) break;

	}
	printf("%d", cnt);

	return 0;
}