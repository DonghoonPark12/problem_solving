#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void)
{
	int N;
	int Answer = 0;
	//freopen("input.txt", "r", stdin);
	cin >> N;


	return 0;

}

#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{


		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}

#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, Answer = 0;
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int arr[100000] = { 0 };
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d ", arr[i]);
	}

	printf("%d\n", Answer);
	return 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int ���� 1�� �Է¹޴� ����
// scanf("%f %f", &b, &c);               // float ���� 2�� �Է¹޴� ���� 
// scanf("%lf %lf %lf", &d, &e, &f);     // double ���� 3�� �Է¹޴� ����
// scanf("%c", &g);                      // char ���� 1�� �Է¹޴� ����
// scanf("%s", &var);                    // ���ڿ� 1�� �Է¹޴� ����
// scanf("%lld", &AB);                   // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int ���� 1�� ����ϴ� ����
// printf("%f %f", b, c);                // float ���� 2�� ����ϴ� ����
// printf("%lf %lf %lf", d, e, f);       // double ���� 3�� ����ϴ� ����
// printf("%c", g);                      // char ���� 1�� ����ϴ� ����
// printf("%s", var);                    // ���ڿ� 1�� ����ϴ� ����
// printf("%lld", AB);                   // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	// freopen("input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		�� �κп� �������� �˰��� ������ ���ϴ�.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}


