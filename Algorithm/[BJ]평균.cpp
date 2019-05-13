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
	int N;//과목 수
	float Answer = 0.f;// 실수로 선언했으면 0도 0.f로 초기화 해야 한다. 
	float arr[1000] = { 0 }; //처음 부터 과목 자료형을 float로 해 놓으면 나눗셈에서 형변환 할 필요 없다. 

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);//내림차순

	for (int i = 0; i < N; i++)
		Answer += arr[i] / arr[N - 1] * 100;

	printf("%.2f\n", Answer / N);
	/////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;

}
