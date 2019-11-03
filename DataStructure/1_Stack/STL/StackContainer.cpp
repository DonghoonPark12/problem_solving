#include <iostream>
#include <stack>
using namespace std;
/*
	push, pop : �ð� ���⵵�� O(1). �ֳ��ϸ� ���� �������� ���� ��������ϱ�.
	size : �迭 �� ��� O(1), ����Ʈ�� ��� O(n
*/
int main() {
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty())
		cout << "Stack is empty!" << endl;

	return 0;
}