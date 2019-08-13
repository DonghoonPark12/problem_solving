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
	for (int i = n - 1; i > 0; i--) { //pivot�� ã�´�. 
		if (arr[i] > arr[i - 1]) {    //a[i] > a[i-1]�� i ������ ã�´�. 
			pivot = i;
			break;
		}
	}

	if (pivot < 0) {				  //i=0�̶�� ��� �����ϴ� �����̱� ������ ������ �� �������̸�
		cout << "-1";                 //���� ������ ����.
		return 0;
	}

	for (int i = n - 1; i >= pivot; i--) { //�� �ڿ��� ���� �˻��ؼ� pivot-1 �ε����� �� ���� ū ���� ã�´�.
		if (arr[i] > arr[pivot - 1]) {
			swap(arr[i], arr[pivot - 1]);  //�����Ѵ�.
			break;
		}
	}

	sort(arr + pivot, arr + n);//arr+n�� ���ڸ� ����Ű�� �ʴ´�.

	for (int i = 0; i < n; i++) {          //pivot ���� ���� ������ ���� �������� �����Ѵ�.
		cout << arr[i] << " ";
	}

	return 0;
}