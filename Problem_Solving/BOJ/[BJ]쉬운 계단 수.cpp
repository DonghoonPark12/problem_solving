#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define abs(m) ((m > 0) ? m: -m)


int arr[10 ^ 99 - 1] = { 0 };
int Answer = 0;

int power(int n, int m)
{
	for (int i = 1; i<m; i++) 
		n *= n;
	return n;
}
int f(int num, int N) {
	int j = 0;
	arr[10 ^ 99 - 1] = { 0 };//�迭 �ʱ�ȭ

	while (num > 0) {   // �� �ڸ����� ���ڸ� ���ؾ��ϹǷ� 1�� �ڸ��� ��� �����ش�.
		arr[j] = num % 10;  //������, 1�� �ڸ� �����ֱ�
		num = num / 10;     //���ڸ��� ���ֱ�
		j++;
	}

	j = 0;

	for(int i=0;i<N-1;i++)
	{
		if ((arr[i] - arr[i + 1] != 1) || (arr[i] - arr[i + 1] != -1))
			return 0;
	}
	return 1;	
}
int main(void)
{
	int N, Answer = 0;
	//setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);

	/////////////////////////////////////////////////////////////////////////////////////////////////

	scanf("%d", &N);//4 -> 1000 ~ 9999 // 6-> 100000  ~ 999999

	for (int i = power(10,N-1); i <= power(10,N) -1; i++)
	{
		//scanf("%d ", arr[i]);
		Answer += f(i,N); //i�� �� �ڸ����� �迭�� ����
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%d\n", Answer);
	return 0;

}