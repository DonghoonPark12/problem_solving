#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
/* 2217. 로프
* '모든 로프를 사용할 수 없으며'가 문제를 Greedy하게 풀게 만든다. 
*/

int main(void)

{
	int N, Answer = 0;
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int arr[100000] = { 0 };
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d\n", &arr[i]);
	}

	sort(arr, arr + N);
	
	int max = 0;
	for (int i = 0; i < N; i++)//0,1,2
	{
		if (arr[i] * (N - i) > max)//45,60,50 *1 
			max = arr[i] * (N - i);
	}
	
	//arr[0] * N
	//arr[1] * N-1
	//arr[N-1]

	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%d\n", max);
	return 0;

}