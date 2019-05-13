#include <stdio.h>

int main()
{
	int n;
	int len;

	int T, test_case;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		/////////////////////
		char str[31];
		scanf("%s", str);

		for (int i = 10; i >= 1; i--) {
			for (int j = 0; j < i; j++) {
				a += str[j];
				b += str[j + i];
			}

			if (a == b)
				len = i;
		}

	}

	return 0;
}


