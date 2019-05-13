#include <iostream>
using namespace std;

int h(int n) {
	int arr[5];//문제에서 1000 이하만 주어진다고 하였으니
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
		a++;//자리수를 판별하는 척도
	}
	for (int j = 0; j < a-2; j++) { //3자리 수라면 1번, 4자리 수라면 2번 수행 한다. 
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
		Ans = n; //99 이하는 모두 한수
	else {
		Ans += 99;
		for (int i = 100; i <= n; i++) {
			Ans += h(i);// 한수 인지 여부를 판별하는 함수
		}
	}
	printf("%d\n", Ans);

	return 0;
}