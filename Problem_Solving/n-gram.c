/* n-gram�� ���ڿ����� N���� ���ӵ� ���(Charater�� Token�̵�)�� �����ϴ� ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	//char text[30] = "Hello";
	//int length;

	//length = strlen(text);

	/* ���� ���� */
	/*
	// 2-gram 
	for (int i = 0; i < length - 1; i++)
	{
		printf("%c%c\n", text[i], text[i + 1]);
	}

	// 3-gram 
	for (int i = 0; i < length - 2; i++)
	{
		printf("%c%c%c\n", text[i], text[i + 1], text[i + 2]);
	}
	*/

	/* �ܾ� ���� */
	char text[100] = "This is C language";
	char *tokens[30] = { NULL, }; // �ڸ� ���ڿ��� �����͸� ������ �迭
	int count = 0;

	char *ptr = strtok(text, " "); // text���ڿ��� �ڸ�. ���� ���ڸ� ������� 

	while (ptr != NULL) // NULL�� ������ ���� �� ���� �ݺ�
	{
		tokens[count] = ptr; // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ���� 

		count++; //�� Token�� ���� ��ŭ ī��Ʈ 

		ptr = strtok(NULL, " "); //  ���� ���ڿ��� �߶� ������ ��ȯ 
		// ���ڿ��� �ε����� �ٷ�� ����� �Ű澲�� �ȴ�.
	}

	// 2-gram�̹Ƿ� �迭�� ���������� ��� �� �� �ձ����� �ݺ���
	for (int i = 0; i < count - 1; i++)
	{
		printf("%s %s\n", tokens[i], tokens[i + 1]);    // ���� ���ڿ��� �״��� ���ڿ� ���(�迭���� ��ū�� ����Ű�� ������ �ּҰ� ����)
	}

	/* Palindrom �Ǻ� */


	return 0;
}