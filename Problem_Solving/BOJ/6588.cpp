#include <iostream>
#include <vector>

using namespace std;
/*
	����: 4 ���� ū ��� ¦���� �� Ȧ���Ҽ��� ������ ��Ÿ�� �� �ִ�.
*/
int n;
const int Max = 1000000;
bool arr[Max+1];

void eratos() {
	for (int i = 2; i <= Max; i++) //2�� �Ҽ��� ����!!!
		arr[i] = true;

	for (int i = 2; i*i <= Max; i++) {//i�� ������ �ص� n���� �۰ų� ������
		if(arr[i]) // �Ҽ��̸�
			for (int j = i*i; j <= Max; j += i) { //�� i*i���� ���� ����??
				arr[j] = false; // ����� ��� �Ҽ��� �ƴϴ�.
		}
	}
}

int main() {
//	for (int i = 1; i <= 1000001; i++) { arr[i] = i; }
	//era_fn(era); //n ���� ���� �� �߿��� �Ҽ��� �����. 
	eratos();
	while (1) {
		cin >> n;
		if (n == 0) break;

		int o1 = 0, o2 = 0; bool flag = false;
		for (o1 = 3; o1 <= n - 1; o1++) { //Ȧ�� ���� �����ϴ� 3���� ����, ����(n)���� �� �ʿ䵵 ����. 
			if (arr[o1]) { //0�� �ƴϰ� : �Ҽ��̸�
				o2 = n - o1; // o1 + o2 = n�� �����ϴ� o2�� ������,
				if (arr[o2]) { //o2�� �Ҽ��̸�
					cout << n << " = " << o1 << " + " << o2; flag = true;
					break;
				}
			}

		}
		if (!flag) {
			cout << "Goldbach's conjecture is wrong.";
			break;
		}
	}
	return 0;
}
