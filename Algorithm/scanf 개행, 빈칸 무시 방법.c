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
//nt T, test_case;
//scanf("%d", &T);
	int a, b;
	int n;
	/*
	while (scanf("%d %d\n", &a, &b) == 2)
	{
			printf("%d", a + b);

	}
	*/
	/*
	while (1)
	{
		scanf("%d %d", &a, &b);
		printf("%d", a + b);
	}
	*/
	//scanf("%d", &n);

	/*
	�Է�
	3
	A B C
	D E F
	G H I
	*/
	/*
	scanf("%d\n", &n); //���๮��(10)�� ���� �������ν�, x�� ���๮�ڸ� ���� �ʵ��� �Ѵ�. 
	while (n--)
	{
		char x, y, z;
		scanf("%c %c %c\n", &x, &y, &z);
		printf("%d %d %d\n", x, y, z);
	}
	*/
	scanf("%d", &n);  
	while (n--)
	{
		char x, y, z;
		scanf(" %c %c %c", &x, &y, &z); //Ȥ�� ���� ���ڸ� �����Ϸ��� �տ� ��ĭ' '�� �δ� ����� ���� ���ȴ�. 
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}
