#include <iostream>
using namespace std;

/*
1. 2���� N���� ��� ���� �� ���´�
2. ���� �������� ���� �� �߿��� ���� ���� �Ҽ��� ã�´�.
3. �� ���� ����� ��� �����.
*/
int arr[1001];
bool check[1001];

int cnt = 0;
void eratos(int n) {
	for (int i = 2; i <= n; i++) { //ó���� ��� �Ҽ��� ����. check[0], check[1]�� false
		check[i] = true;
	}
	for (int i = 2; i*i <= n; i++) {
		if (check[i] == true) {
			for (int j = i * i; j <= n; j += i) { //i*k (k < i) ������ �̹� �˻�Ǿ����Ƿ� j���� ���� i*2 ���� i*i�� ������ �� �ִ�.
				check[j] = false;
			}
		}
	}

	//������ �򰥸��� �Ʒ��� ���� �ص� �ȴ�.
	//for (int i = 2; i <= n; i++) {
	//	if (check[i] == true) {
	//		for (int j = i; j <= n; j += i) {  //�ٸ� ����� ���ؼ� j += i�� �߿��ϴ�.
	//			check[j] = false;
	//		}
	//	}
	//}
}
int main() {
	int n, k; cin >> n >> k;
	eratos(n);

	return 0;
}

int main() {
	cin >> n;
	eratos(n);

	return 0;
}