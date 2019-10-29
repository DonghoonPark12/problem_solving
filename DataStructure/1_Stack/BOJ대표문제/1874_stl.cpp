#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	문제 조건 : 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 


	A[i] : 만들어야 하는 수열 A의 수
	m < A[i] : A[i]를 pop 해야 하기 때문에, m부터 A[i]까지의 모든 수를 순서대로 push해야 한다.
	m > A[i] : 불가능한 경우다. pop을 하면 A[i]가 아닌 다른 수가 A에 추가된다.
	m == A[i]인 경우 : pop을 해서 A[i]를 만들면 된다.
*/
int main() {
	int t; cin >> t;
	int n;
	int cnt = 0; //오로지 증가만 한다. 줄어들지 않는다.
	stack<int> st;
	string ans;
	while (t--) {
		cin >> n;
		if (n > cnt) {
			while (cnt < n) {
				st.push(++cnt);
				ans += '+';
			}
			st.pop();
			ans += '-';
		}
		else { //(n<=top)
			//int top = st.top();
			//if (n > top) return 0; //뺄려고 하는 값(n)이 현재 스택의 최고 값보다도 크다면 이건 불가능한 경우
			
			int top;
			bool found = false;
			//if (!st.empty()){ //&& top != n) {
				top = st.top();
				st.pop();
				ans += '-';
				if (top == n) found = true; //현재 top의 값이 무조건 출력되야 하는 n값이어야 한다. 
			//}
			if (!found) { cout << "NO" << '\n'; return 0; }
		}
	}
	for (auto i : ans)
		cout << i << '\n';

	return 0;
}