#include <iostream>
using namespace std;

#define ABS(a) (((a) > 0) ? (a) : -(a))

int main() {
	int n; cin >> n;
	int len = 2 * n -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++) {
			if (ABS(n - 1 - j) <= i)
				printf("*");
			else if (j > n - 1 + i)
				break;
			else
				printf(" ");
		}
		printf("\n");
	}

	//for (int i = 1; i <= n; i++)
	//{
	//	cout.width(n - i);
	//	cout.fill(' ');
	//	cout << "";

	//	for (int j = 1; j <= 2 * i - 1; j++)
	//		cout << "*";

	//	cout.width(n - i);
	//	cout.fill(' ');
	//	cout << "";

	//	cout << "\n";
	//}
	return 0;
}

