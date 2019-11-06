/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

/* 
������ ���� N�϶� '���� ���� ����'�� ������ ���� N�� ���Ͽ� ���� ������ �ǰų� �� �̻��� �� �� ������ ��� ���ɼ��� �ִ�.
N���̶�� ���� ���� �ְ� ������ ���� N-1�����ؼ� �����̸� �Ǵ� 

4���� ��� 10�ִ� 6 7 7 �ּ� �� ��� ����(x) 

1
N
m���� ���� ���� ���� ( n(n+1)/2 )*m <-- �ʿ� ���� �������

�׽�Ʈ ���̽��� ���� �� �� ������(n��)�� ���� ������ '�ñ׸�n'�� ��� �� �ʿ䰡 �ִ�.  
ex) 5 6 7 �̶�� (3+2+1) *3���� ����
ex) 9 6 7 8 �̶�� (4+3+2+1) *3���� ���� <-- �ʿ� ���� �������

-> ���� ���� ���� - (������ ��)  ���� ũ�⸸ �ϸ� �ǳ�.
-> ���� ���� ���� + (�����ڼ�)....  �̰� ������ ���� ���Ѵ�. 1���� ���� ������ ������ ���� ���Ѵ�. 
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Answer;

int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int n; // �����ڼ�
		int cnt = 0;
		int score;//�����ڵ� ����
		int temp = 0;//�ִ� ���� �Ǻ��� �� ���̴� ����.
		int *arr;
		scanf("%d", &n);
		//int arr[] = { 0 }; //�迭�� ũ��� ����� �̸� ���ؾ� �ϴ� ����
		
		arr = (int *)malloc(sizeof(int) * n);//������ �� ��ŭ�� (int) ���� �Ҵ�.

		for (int i = 0; i < n; i++) //�迭�� �ִ°� Sorting�ϴµ�(X) �ִ�� �̾Ƴ��µ�(O) ������ ������. �ٸ� ���� ��� �ֳ�?
		{
			scanf("%d", &score);
			arr[i] = score;
		}

		for (int j = 0; j < n; j++) //������ �� ���� ���� ������ ã�Ƴ���.
		{							
			if (arr[j] > temp)
			{
				temp = arr[j];
			}
		}

		for (int k = 0; k < n; k++)//n���� ������ �� (���� ���� ���� - �����ڼ�) ���� �ʰ��ϴ� �ο����� ī��Ʈ �Ѵ�.
		{
			if (arr[k] > temp-n)
			{
				cnt++;
			}
		}
		Answer = cnt;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}