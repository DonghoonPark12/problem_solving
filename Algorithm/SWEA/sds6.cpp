#include <iostream>
using namespace std;

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;

		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;
