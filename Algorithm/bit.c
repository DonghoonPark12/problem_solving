#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BIT_XOR(n,pos) ((n) ^= (1<< (pos)))

int main()
{
	int i=0;
	char key;
	char sen[100] = { 0 };

	printf("Ű ���� �Է��Ͻÿ�: ");
	scanf("%c",&key);
//	fflush(stdin);
	printf("\n ������ �Է��Ͻÿ�: ");
	scanf("%s", sen);

	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char�� ���� XOR ���� ��, 8bits�� �Ѳ����� XOR ����ȴ�.
		i++;
	}

	i = 0;
	while (sen[i] != '\0')
	{
		printf("%d", sen[i]);
		i++;
	}
	printf("�� ���ڵ� ��.\n");

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
		sen[i] ^= key; //char�� ���� XOR ���� ��, 8bits�� �Ѳ����� XOR ����ȴ�.
		i++;
	}

	while (sen[i] != '\0')
	{
		printf("%d", sen[i]);
		i++;
	}
		printf("�� ���ڵ� ��.\n");

	return 0;
}