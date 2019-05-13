#include <iostream>
using namespace std;
//Compiler version g++ 6.3.0

int arr[2001];
/*
0->arr[1000]
-1->arr[999]
-1000->arr[0]
1->arr[1001]
1000->arr[2000]
*/

int main()
{
	int n;
	int tmp;

	scanf("%d", &n);

	for (int i = 0; i<n; i++) {
		scanf(" %d", &tmp);

		arr[tmp + 1000] = 1;//-1000,

	}
	for (int j = 0; j <= 2000; j++) {
		if (arr[j])
			printf("%d ", j - 1000);
	}

	return 0;
}