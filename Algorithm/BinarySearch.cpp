#include <iostream>

int BSearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else {
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
		opCount += 1;
	}
	printf("ºñ±³¿¬»êÈ½¼ö : %d \n", opCount);
	return -1;//Ã£Áö ¸øÇßÀ» ¶§ -1
}

int BSearch_recur(int arr[], int first, int last, int target) {
	int mid;
	if (first > last)
		return -1;

	mid = (first + last) / 2;
	if (target == arr[mid])
		return mid;
	else if (target < arr[mid])
		return BSearch_recur(arr, first, mid-1 , target);
	else
		return BSearch_recur(arr, mid+1, last, target);
}

int main() {
	int arr[] = {1,3,5,7,9 };
	int idx;
	int arr1[500] = { 0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };


	//idx = BSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 1);
	//if (idx == -1) printf("Å½»ö ½ÇÆĞ\n");
	//else printf("Å¸°Ù ÀÎµ¦½º: %d \n", idx);

	//idx = BSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 2);
	//if (idx == -1) printf("Å½»ö ½ÇÆĞ\n");
	//else printf("Å¸°Ù ÀÎµ¦½º: %d \n", idx);

	//idx = BSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 3);
	//if (idx == -1) printf("Å½»ö ½ÇÆĞ\n");
	//else printf("Å¸°Ù ÀÎµ¦½º: %d \n", idx);

	idx = BSearch_recur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1) printf("Å½»ö ½ÇÆĞ\n");
	else printf("Å¸°Ù ÀÎµ¦½º: %d \n", idx);
	
	idx = BSearch_recur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1) printf("Å½»ö ½ÇÆĞ\n");
	else printf("Å¸°Ù ÀÎµ¦½º: %d \n", idx);

	return 0;
}