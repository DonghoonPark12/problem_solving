#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ABS(n) ( ((n) >= 0) ? (n) : -(n))
using namespace std;

int main() {
	int n; cin >> n;

	//9
	int num = 2 * n;

	for (int i = 1; i < num; i++)  //1 ~ 9
	{
		for (int j = 1; j <= num; j++) //1 ~ 10
		{
			if (j <= i || j > num - i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}