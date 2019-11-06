#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	int a, b;
	cin >> T;
	for (int t = 0; t<T; t++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}

#include <stdio.h>
void main() {
	int input, a, b, i;
	scanf("%d", &input);
	for (i = 0; i < input; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}