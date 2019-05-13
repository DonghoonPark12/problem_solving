#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
//각 자리수 vector에 대입 + 가장 큰 수에 가중치 1 ~ 숫자 갯수 만큼
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
	int **arr = new int *[2];// 2행

	for (int i = 0; i < 2; i++) {
		arr[i] = new int[N];//열
		memset(arr[i], 0, sizeof(int) * N);
	}

	while (num != 0)
	{
		//v.push_back(num % 10);
		arr[0][i++] = num % 10;
		num = num / 10;
	}

	// 두 번째 행에 우선 순위를 어떻게 잡을 것인가...

