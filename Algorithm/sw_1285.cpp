#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define abs(a) ((a)>0 ? (a) : (-a))
/*
���� ����: ���� 0�� ���� ������ ������ ���� �Ÿ��� �ش��ϴ� �ο���
�־��� ��:
- ���� ������ ��� 1000�� ����. ����� ���� �־����� �Ÿ� ���� 1000�� ���� 
- �Ÿ� ������ ������ ��, �ּ� ���� ���� ���� ������ ���� �ǰڴ�. 
- �迭�� ���� ���� �� abs ������ �ִ´�. 

Ǯ�� ���:
*/
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quicksort(int arr[], int low, int high) {
	int pi;
	if (low < high) {
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
int arr[1000];//���� ���� �Ÿ��� ����. 
int main() {

	int tmp;
	int tc; scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {

		int N; scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf(" %d", &tmp);
			arr[i] = abs(tmp); //���� ���� ���ϸ� ���� �Ÿ��� � ������ ������ �ҽǵȴ�. 
		}                      //�� �ƴϴ�. �Ÿ��� ��Ÿ���� �ȴ�. 

		quicksort(arr,0,N-1);

		int min = arr[0];
		int cnt = 0;
		for (int i = 0; arr[i] == min; i++) {
			cnt++;
		}
		printf("#%d %d %d\n", t+1, arr[0],cnt); 

		for (int i = 0; i < N; i++) {
			arr[i] = 0;
		} 
	}


}