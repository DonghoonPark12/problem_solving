#include <iostream>
using namespace std;

int h(int n) {
	int arr[5];//�������� 1000 ���ϸ� �־����ٰ� �Ͽ�����
	int i=0;
	int a = 0;
	/*
	* 999 -> 9 9 9
	* 135 -> 5 3 1
	* 473 -> 3 7 4
	* 1000 -> 0 0 0 1
	*/
	while (n != 0) {
		arr[i] = n % 10;
		n = n / 10;
		i++;
		a++;//�ڸ����� �Ǻ��ϴ� ô��
	}
	for (int j = 0; j < a-2; j++) { //3�ڸ� ����� 1��, 4�ڸ� ����� 2�� ���� �Ѵ�. 
		if ((arr[j] - arr[j + 1]) != (arr[j+1] - arr[j+2]))
			return 0;
	}
	return 1;
}

int main() {
	int n;
	int Ans = 0;
	cin >> n;

	if (n <= 99)
		Ans = n; //99 ���ϴ� ��� �Ѽ�
	else {
		Ans += 99;
		for (int i = 100; i <= n; i++) {
			Ans += h(i);// �Ѽ� ���� ���θ� �Ǻ��ϴ� �Լ�
		}
	}
	printf("%d\n", Ans);

	return 0;
}