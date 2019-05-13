#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define abs(a) ((a)>0 ? (a) : (-a))
/*
문제 정의: 돌이 0에 가장 가깝게 떨어진 곳의 거리와 해당하는 인원수
주어진 것:
- 돌을 던지는 사람 1000명 이하. 사람들 마다 주어지는 거리 정보 1000개 이하 
- 거리 정보를 소팅한 후, 최소 값을 살펴 동일 갯수를 보면 되겠다. 
- 배열에 집어 넣을 때 abs 값으로 넣는다. 

풀이 방법:
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
int arr[1000];//던진 돌의 거리별 정보. 
int main() {

	int tmp;
	int tc; scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {

		int N; scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf(" %d", &tmp);
			arr[i] = abs(tmp); //절대 값을 취하면 실제 거리가 어떤 값인지 정보가 소실된다. 
		}                      //가 아니다. 거리만 나타내면 된다. 

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