//#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Answer;
/*
void swap(int *p, int *q)
{
int tmp = *p;
*p = *q;
*q = tmp;
}

int partition(int s[], int low, int high)
{
int j = low, pivotpoint;
int pivotitem = s[low];
for (int i = low + 1; i <= high; i++)
{
if (s[i] > pivotitem)
{
j++;
swap(&s[i], &s[j]);
}
}
pivotpoint = j;
swap(&s[low], &s[pivotpoint]);
return pivotpoint;
}

void quicksort(int arr[], int low, int high)
{
int pivot = partition(arr, low, high);
if (high > low)
{
quicksort(arr, low, pivot - 1);
quicksort(arr, pivot + 1, high);
}
}
*/
int main(void)
{
	int test_case;

	//freopen("input.txt", "r", stdin);

	//setbuf(stdout, NULL);

	/////////////////////////////////////////////////////////////////////////////////////////////
	int num, n;
	int max_cnt = 1;
	int cnt = 0;
	int score;//참가자들 점수
	int index;

	//scanf("%d", &test_case);
	int arr[1000] = { 0 };
	//	int *ptr = arr;
	for (int i = 0; i < 10; i++)
	{
		//scanf("%d", &num);
		for (int i = 0; i < 1000; i++)
		{
			scanf("%d", &n);
			arr[i] = n;
		}

		//quicksort(arr, 0, 1000);

		for (int i = 0; i < 1000; i++)
		{
			cnt = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] == arr[j])
					cnt += 1;
			}

			if (cnt >= max_cnt)
			{
				index = arr[i];
				max_cnt = cnt;
			}

		}
		Answer = index;

		printf("#%d ", test_case + 1);
		printf(" %d\n", Answer);
	}


	/////////////////////////////////////////////////////////////////////////////////////////////

	// Print the answer to standard output(screen).



	return 0;

}
