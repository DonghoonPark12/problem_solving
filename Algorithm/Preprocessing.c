//#include <stdio.h>
#include "stdafx.h"

#define ARRAY_INIT(array, size, value)	{ int i; for(i=0; i<size; i++) {array[i] = value;} }

int main()
{
	int i;
	int arr[10] = { 5, 6, 7, 8, 9, 10, 22, 33, 44, 66 };
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ARRAY_INIT(arr, 10, 0);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}