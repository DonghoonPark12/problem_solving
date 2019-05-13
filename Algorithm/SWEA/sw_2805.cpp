#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int n; cin >> n;
		int Answer = 0;
		vector<vector<int>> arr(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);
			}
			scanf("\n");
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				//cout << abs(n / 2 - j) << endl;
				//cout << 7 - abs(n / 2 - j) << endl;
				if ((i >= abs(n / 2 - j)) && (i < (n - abs(n / 2 - j))))
					Answer += arr[j][i];
			}
		}


		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;
}

