/*
	연산자의 갯수는 N-1보다 많을 수도 있다??!!!!
	주어진 연산자를 모두 사용하지 않고, 모든 수의 사이에 연산자를 끼워 넣을 수도 있다?(조합)
*/

#include <iostream>
using namespace std;
int n; 
int num[11];
int op[4];
int ans;
int _max, _min;
int cnt;
void rec(int i, int ans, int sum, int minus, int mul, int div) {
	if (i >= n) return;
	cnt++;
	if (i == n - 1) {
		if (ans > _max) _max = ans;
		if (ans < _min) _min = ans;
		return;
	}

	//if (sum)   {  rec(i + 1, ans + num[i+1], op[0] - 1, op[1], op[2], op[3]); }
	//if (minus) {  rec(i + 1, ans - num[i+1], op[0], op[1] - 1, op[2], op[3]); }
	//if (mul)   {  rec(i + 1, ans * num[i+1], op[0], op[1], op[2] - 1, op[3]); }
	//if (div)   {  rec(i + 1, ans / num[i+1], op[0], op[1], op[2], op[3] - 1); }

	if (sum)   {  rec(i + 1, ans + num[i+1], sum - 1, minus, mul, div); }
	if (minus) {  rec(i + 1, ans - num[i+1], sum, minus - 1, mul, div ); }
	if (mul)   {  rec(i + 1, ans * num[i+1], sum, minus, mul - 1, div ); }
	if (div)   {  rec(i + 1, ans / num[i+1], sum, minus, mul, div - 1); }

	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	_min = 0x7fffffff;
	_max = -1 * _min;

	rec(0, num[0], op[0], op[1], op[2], op[3]);

	cout << _max << '\n';
	cout << _min << '\n';
	cout << cnt;
	return 0;
}
