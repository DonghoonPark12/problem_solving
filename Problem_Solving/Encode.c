#include <stdio.h>
//��ũ�� ������ ������Ͽ� 
int main()
{
	int key;
	char *str;

	// 8bits ���� ������ ��.
	printf("Ű ���� �Է��Ͻÿ�: ");
	scanf("%d", &key);

	printf("��ȣȭ�� ���� �Է� �Ͻÿ�: ");
	scanf("%s", str);

	printf("%s: ", str);
	while (*str != NULL) //Encoding
	{
		XOR_BIT(*str, key); //8bits�� ���������� XOR ���� �ȴ�.
		str++;
	}

	printf("%s�� ���ڵ� ��\n", str);

	printf("%s: ", str);
	while (*str != NULL) // �ٽ� �����ϸ� Decoding�� �Ǵ� �ɱ�
	{
		XOR_BIT(*str, key); //8bits�� ���������� XOR ���� �ȴ�.
		str++;
	}

	printf("%s�� ���ڵ� ��\n", str);

	return 0;

}