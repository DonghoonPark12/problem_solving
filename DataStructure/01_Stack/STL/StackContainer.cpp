#include <iostream>
#include <stack>
using namespace std;
/*
	push, pop : 시간 복잡도는 O(1). 왜냐하면 제일 위에서만 빼고 집어넣으니까.
	size : 배열 일 경우 O(1), 리스트일 경우 O(n
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