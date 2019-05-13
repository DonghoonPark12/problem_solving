#ifndef SORT
#define SORT
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
		if (s[i] > pivotitem){ //내림 차순 할 경우 '<'로 바꿔준다. 
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

#endif // !SORT

