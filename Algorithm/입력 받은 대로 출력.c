#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//scanf�� ���ϰ�: ���������� �Է� ���� ���� ����
//����, ���� ������ �Է� �޾ƾ� �ϴ� ��쿡�� 
//while(scanf("%d %d", &a, &b) == 2)�� ���� ����� �� �ִ�.
//scanf�� ����� �ٹٲ��� �����Ѵ�. 
//%c �Է� �޴°� ����. ����, �ٹٲ޵� ����.

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	/* 
	�Է�
	Hello
	Baekjoon
	Online Judge
	*/
	char str[100];
	/*
	while (scanf("%[^\n]\n", str) == 1) 
	{
		printf("%s\n", str);
	}
	//�ٹٲ��� �Է� ���� �ʾ�, �ڿ� ���๮�� �ٿ��ش�.
	//����, ������ �Է� ���� �� ����. 
	//��, �������� �����ϴ� ��� ������ �����ϰ� ���ں��� �Է� �ް� �ȴ�. 
	*/
	/*
	�Է�
		Hello

	Baekjoon
			Online Judge
	*/
	/*
	char c;

	while ((c = getchar()) && c != EOF)
	{
		printf("%c", c);
	}
	printf("\n");
	*/

	/*
	�Է�
	5
	12345
	*/
	/*
	int n;
	int sum = 0;
	int x;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &x);
		sum += x;
	}
	printf("%d\n", sum);
	*/

	//%s�� ��쵵 ������ �����ؼ� �Է� ���� �� �ִ�. 
	//�Է� ���� �� �ִ� ������ ������ �������� ������ �׸�ŭ �Է� �޴´�. 
	char a[100];
	while (scanf("%10s", a) == 1) // 
	{
		printf("%s\n", a);
	}

	/* ��ġ �ʴ� ���� �Է� ���� ���� �� */
	int x, y;
	scanf("%d %*d %d", &x, &y);
	printf("%d %d\n", x, y);
	return 0;
}