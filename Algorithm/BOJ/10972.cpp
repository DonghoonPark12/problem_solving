#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];

void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int pivot = -1;
	
	//10792
	for (int i = n - 1; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			pivot = i;
			break;
		}
	}

	if (pivot < 0) {
		cout << "-1";
		return 0;
	}

	//for (int i = 0; i < n; i++) {
	//	cout << arr[i] << " ";
	//}
	
	for (int i = n - 1; i >= pivot; i--) {
		if (arr[i] < arr[pivot - 1]) {
			swap(arr[i], arr[pivot - 1]);
			break;
		}
	}

	//sort(arr + pivot, arr+n);//arr+n은 숫자를 가리키지 않는다.
	int idx2 = n - 1;
	while (pivot < idx2) {
		swap(arr[pivot], arr[idx2]);
		pivot++;
		idx2--;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
