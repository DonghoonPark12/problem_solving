#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//Compiler version g++ 6.3.0
int arr[20000001];
int main()
{
	int n; scanf("%d", &n);
	int tmp;
	for (int i = 0; i<n; i++) {
		scanf(" %d", &tmp);
		arr[tmp + 10000000]++;
	}

	int m; scanf(" %d", &m);
	for (int i = 0; i<m; i++) {
		scanf(" %d", &tmp);
		printf("%d ", arr[tmp + 10000000]);
	}
	return 0;
}