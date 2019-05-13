/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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


int main(void)
{
	int T, test_case;
	//int Answer;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int arr[100] = { 0, };
		int dump;
		int Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d", &dump); //dump ¼öÇà È½¼ö
		
		for (int i = 0; i < 100; i++)
		{
			scanf("%d", &arr[i]);
		}
		//quicksort(arr, 0, 99);
		//for (int i = 0; i < 100; i++)
		//{
		//	printf("%d  ", arr[i]);
		//}
		quicksort(arr, 0, 99);
		while (dump != 0) 
		{

		
			arr[0]--;
			arr[99]++;

			quicksort(arr, 0, 99);

			dump--;

			if ( (arr[0] - arr[99]) <= 1)
				break;
		
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", (arr[0] - arr[99]));

	}

	return 0;//Your program should return 0 on normal termination.
}