#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 재귀적 방식은 시스템 내부 호출 Stack을 사용하여 오버 헤드가 일어날 가능성이 있다.(Overlapping Recursuve Calls) 
* 반대로, 동적 계획법은 오버헤드가 발생하지 않는다. 
* 피보나치 문제는 Memoization을 기반으로한 동적 계획법 대표문제
* 동적 계획법은 Optimal Subsructure + Overlapping Recursuve Calls인 경우 사용.
* Optimal Subsructure: 큰 문제의 최적 솔루션에 작은 문제의 최적 솔루션이 포함되는 경우
* Overlapping Recursuve Calls: 재귀 해법으로 풀면 재귀 호출이 심하게 중복되는 경우
*/
/*
int f(int n)
{
	if (n < 2)
		return n;
	else
		return f(n - 2) + f(n - 1);
}//호출 중복이 너무 발생

int f(int n)
{
	int a[100] = { 0, };
	a[0] = 0, a[1] = 1;

	for (int i = 2; i < n; i++)
	{
		a[n] = a[n - 1] + a[n - 2];
	}

	return a[n];
}
*/
// Memoization을 기반으로 한 동적 계획법: 최적화 문제를 해결하는 알고리즘
// 입력 크기가 작은 부분 문제들을 모두 해결한 후에, 그 해들을 이용하여 보다 큰 크기의 문제들을 해결(Optimal Subsructure)

int memo[40] = { 1,1, };

int fibonacci(int n) {
	
	if(n <= 1) return memo[n];
	else
	{
		if (memo[n] > 0) return memo[n];
	}
	return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

}

int main(void)
{
	int test_case, T;
	int N;
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);

		fibonacci(N);
		if (N == 0) printf("1 0\n");
		else if (N == 1) printf("0 1\n");
		else
		{
			printf("%d %d\n", memo[N - 2], memo[N - 1]);
		}
	}
	return 0;
}