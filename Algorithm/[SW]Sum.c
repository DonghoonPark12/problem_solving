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
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%d", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int sum = 0;
		int arr[100][100] = { 0, };
		int arr_V[100] = { 0, };
		int arr_H[100] = { 0, };
		int arr_D  = 0;
		int arr_D2 = 0;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				scanf("%d", &(arr[i][j]));
				arr_V[i] += arr[i][j];
				arr_H[j] += arr[i][j];
				
				if(i == j)
					arr_D += arr[i][j];

				if (i + j == 99)
					arr_D2 += arr[i][j];
			}
		}
		/*
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n ##%d",i);
		}
		*/	
		quicksort(arr_V, 0, 99); quicksort(arr_H, 0, 99);

		int temp[4] = { arr_V[0],arr_H[0],arr_D,arr_D2 };
		int max = 0;
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] > max)
				max = temp[i];
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("Case #%d ", test_case + 1);
		printf("%d\n", max);
	}



	return 0;

}
