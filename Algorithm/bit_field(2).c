#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SET_BIT(n,pos) ( (n) |= (1 << pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� 1�� ����. 
#define CLR_BIT(n,pos) ( (n) &= (~1<< pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� 0���� ����.
#define GET_BIT(n,pos) ( (n) & (1 << pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� ��ȯ





void display_bit(int value)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if (GET_BIT(value, i)) //���� n �ȿ� �ִ� i��° ��Ʈ�� ��ȯ
			printf("1");
		else
			printf("0");
	}
	//printf("\n");

	return;
}
