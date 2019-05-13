#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SET_BIT(n,pos) ( (n) |= (1 << pos) ) //변수 n 안에 있는 pos 번째 비트를 1로 설정. 
#define CLR_BIT(n,pos) ( (n) &= (~1<< pos) ) //변수 n 안에 있는 pos 번째 비트를 0으로 설정.
#define GET_BIT(n,pos) ( (n) & (1 << pos) ) //변수 n 안에 있는 pos 번째 비트를 반환





void display_bit(int value)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if (GET_BIT(value, i)) //변수 n 안에 있는 i번째 비트를 반환
			printf("1");
		else
			printf("0");
	}
	//printf("\n");

	return;
}
