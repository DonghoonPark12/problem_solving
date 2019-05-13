#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BIT_XOR(n,pos) ((n) ^= (1<< (pos)))

int main()
{
	int i=0;
	char key;
	char sen[100] = { 0 };

	printf("키 값을 입력하시오: ");
	scanf("%c",&key);
//	fflush(stdin);
	printf("\n 문장을 입력하시오: ");
	scanf("%s", sen);

	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char형 끼리 XOR 연산 즉, 8bits가 한꺼번에 XOR 연산된다.
		i++;
	}

	i = 0;
	while (sen[i] != '\0')
	{
		printf("%d", sen[i]);
		i++;
	}
	printf("로 인코딩 됨.\n");

	i = 0;
	while (sen[i] != '\0')
	{
		printf("%d", sen[i]);
		i++;
	}
	printf(": ");

	i = 0;
	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char형 끼리 XOR 연산 즉, 8bits가 한꺼번에 XOR 연산된다.
		i++;
	}

	while (sen[i] != '\0')
	{
		printf("%d", sen[i]);
		i++;
	}
		printf("로 디코딩 됨.\n");

	return 0;
}