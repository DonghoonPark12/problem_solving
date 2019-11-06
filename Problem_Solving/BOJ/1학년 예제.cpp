/*
* long long - target type will have width of at least 64 bits (since C++11)
* (unsigned) long long int 출력 %llu (-2^32 +1 ~ 2^32)
* long int 출력 %ld
* long long int 출력 &lld (0 ~ 2^64 -1 )
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
using namespace std;
int arr[100] = { 0, };
long long memo[100][21]; //

long long GetSolve(int input, int idx, int sum) // 11 , 1 , arr[0]
{
	if (sum < 0 || sum > 20) return 0;

	if (idx == input - 1)return sum == arr[input - 1]; //idx가 10이라면, sum이 arr[10] 같을경우 1 다르면 0 리턴

	if (memo[idx][sum] != -1) return memo[idx][sum]; //if(memo[1][arr[0]])	!= -1 이면  // 해당 idx, sum 일때 Count 값은 XX 였다. 

	long long  count = 0;

	count += GetSolve(input, idx + 1, sum + arr[idx]);

	count += GetSolve(input, idx + 1, sum - arr[idx]);



	return memo[idx][sum] = count;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int input;
	memset(memo, -1, sizeof(memo)); //void * memset ( void * ptr, int value, size_t num );
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%lld\n", GetSolve(input, 1, arr[0]));
	return 0;
}

