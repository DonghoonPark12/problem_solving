#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
N=input()
a=map(float,raw_input().split()) //
a.sort()
print("%.2f" % (sum([x/a[-1]*100 for x in a])/N))
*/


int main(void)
{
	int N;//���� ��
	float Answer = 0.f;// �Ǽ��� ���������� 0�� 0.f�� �ʱ�ȭ �ؾ� �Ѵ�. 
	float arr[1000] = { 0 }; //ó�� ���� ���� �ڷ����� float�� �� ������ ���������� ����ȯ �� �ʿ� ����. 

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);//��������

	for (int i = 0; i < N; i++)
		Answer += arr[i] / arr[N - 1] * 100;

	printf("%.2f\n", Answer / N);
	/////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;

}
