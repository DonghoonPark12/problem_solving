#include <stdio.h>

int main()
{
	char *str;
	int cnt = 0;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets("%s", str);

	while (*str != Null)
	{
		if (*str == 47)
			cnt++;
	}

	printf("���� ������ ������ %d�� �Դϴ�.", cnt);

	return 0;
}