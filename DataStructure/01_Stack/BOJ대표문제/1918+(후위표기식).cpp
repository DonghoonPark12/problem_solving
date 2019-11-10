#include <string>
#include <stack>
#include <deque>
#include <iostream>
using namespace std;

/*
	���� ǥ��� -> ���� ǥ������� �ٲܶ� Stack�� �̿��Ѵ�.
	
	�ٽ� : '������'�� ������ ������� ������',                  while(!S.empty() && pr(S.top()) >= pr(c)) {
	        
			���ÿ� �ִ� ������(top)���� �켱������ ����
			
			���ÿ� �ִ� ������(top)�� �켱������ ���ų� ũ�ٸ�
			 
			���ÿ� �ִ� �����ڸ� ��� pop�� �� �� ����ϰ�      {
			
			���� �����ڴ� ���ÿ� push�Ѵ�.                       S.push(c);


	���� ǥ��� ����� ������ Stack�� �̿��Ѵ�. 
*/
int pr(char c) {
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else if (c == '(') return 0;
}

int main() {
	stack<char> st;
	string str; cin >> str;
	int size = str.length();

	for (int i = 0; i < size; i++) {
		char c = str[i];
		if (c >= 'A' && c <= 'Z') cout << c; //�ǿ����� �״�� ���
		else if (c == '(') st.push(c); //���� ��ȣ�� push
		else if (c == ')') {  //���� ��ȣ�� ���� ��ȣ�� ���ö� ���� ���
			while (st.top() != '(') {
				cout << st.top(); st.pop();
			}
			st.pop();//���� ��ȣ�� ���X
		}
		else { //�� �������� ���
			while (!st.empty() && pr(st.top()) >= pr(c)) { //������ Top���� �켱���� ���ؼ� ������ ���ų� ���ٸ� ��� �Ѵ�.
				cout << st.top(); st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}
	return 0;
}
//bool IsOP(char c) {
//	if (c == '+' || c == '*' || c == '/' || c == '-')
//		return true;
//	else
//		return false;
//}
//
//int main() {
//	stack<char> st;
//	string str; cin >> str;
//	int size = str.length();
//	bool flag = false;
//	deque<char> postexpress;
//	for (int i = 0; i < size; i++) {
//		char c = str[i];
//		if (c == ')' && !IsOP(st.top())) {
//			deque<char> dq;
//			dq.push_back(st.top()); st.pop();
//			dq.push_back(st.top()); st.pop();
//			dq.push_front(st.top()); st.pop();
//			while (!dq.empty()) {
//				postexpress.push_back(dq.front()); dq.pop_front();
//			}
//		}
//		else if (c == ')') {
//			postexpress.push_back(st.top()); st.pop();
//			postexpress.push_front(st.top()); st.pop();
//		}
//		else {
//			if (c != '(')
//				st.push(c);
//		}
//	}
//	while (!st.empty()) {
//		char c = st.top();
//		if (IsOP(c)) {
//			postexpress.push_back(c); st.pop();
//		}
//		else {
//			postexpress.push_front(c); st.pop();
//		}
//	}
//	size = postexpress.size();
//	for (int i = 0; i < size; i++) {
//		cout << postexpress[i];
//	}
//	return 0;
//}

