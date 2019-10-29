#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	���� ���� : ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. 


	A[i] : ������ �ϴ� ���� A�� ��
	m < A[i] : A[i]�� pop �ؾ� �ϱ� ������, m���� A[i]������ ��� ���� ������� push�ؾ� �Ѵ�.
	m > A[i] : �Ұ����� ����. pop�� �ϸ� A[i]�� �ƴ� �ٸ� ���� A�� �߰��ȴ�.
	m == A[i]�� ��� : pop�� �ؼ� A[i]�� ����� �ȴ�.
*/
int main() {
	int t; cin >> t;
	int n;
	int cnt = 0; //������ ������ �Ѵ�. �پ���� �ʴ´�.
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
			//if (n > top) return 0; //������ �ϴ� ��(n)�� ���� ������ �ְ� �����ٵ� ũ�ٸ� �̰� �Ұ����� ���
			
			int top;
			bool found = false;
			//if (!st.empty()){ //&& top != n) {
				top = st.top();
				st.pop();
				ans += '-';
				if (top == n) found = true; //���� top�� ���� ������ ��µǾ� �ϴ� n���̾�� �Ѵ�. 
			//}
			if (!found) { cout << "NO" << '\n'; return 0; }
		}
	}
	for (auto i : ans)
		cout << i << '\n';

	return 0;
}