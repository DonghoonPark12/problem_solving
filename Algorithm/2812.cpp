#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
//�� �ڸ��� vector�� ���� + ���� ū ���� ����ġ 1 ~ ���� ���� ��ŭ
using namespace std;

int main()
{
	int N = 0, K = 0;
	int num = 0;
	int Answer = 0;

	scanf("%d %d", &N, &K);//4 2 
	scanf(" %d", &num);// 1  9  2  4
	                   //(4)(1)(3)(2)

	//int *arr = (int*)malloc(sizeof(int)*N);
	//int arr[500000] = { 0 };
	//vector<char> v;
	int i = 0;
	int **arr = new int *[2];// 2��

	for (int i = 0; i < 2; i++) {
		arr[i] = new int[N];//��
		memset(arr[i], 0, sizeof(int) * N);
	}

	while (num != 0)
	{
		//v.push_back(num % 10);
		arr[0][i++] = num % 10;
		num = num / 10;
	}

	// �� ��° �࿡ �켱 ������ ��� ���� ���ΰ�...

