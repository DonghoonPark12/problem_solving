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
	for (int i = n - 1; i > 0; i--) { //pivot을 찾는다. 
		if (arr[i] > arr[i - 1]) {    //a[i] > a[i-1]인 i 지점을 찾는다. 
			pivot = i;
			break;
		}
	}

	if (pivot < 0) {				  //i=0이라면 계속 증가하는 구조이기 때문에 순열의 맨 마지막이며
		cout << "-1";                 //다음 순열은 없다.
		return 0;
	}

	for (int i = n - 1; i >= pivot; i--) { //맨 뒤에서 부터 검사해서 pivot-1 인덱스의 값 보다 큰 수를 찾는다.
		if (arr[i] > arr[pivot - 1]) {
			swap(arr[i], arr[pivot - 1]);  //스왑한다.
			break;
		}
	}

	sort(arr + pivot, arr + n);//arr+n은 숫자를 가리키지 않는다.

	for (int i = 0; i < n; i++) {          //pivot 지점 부터 끝까지 오름 차순으로 정렬한다.
		cout << arr[i] << " ";
	}

	return 0;
}