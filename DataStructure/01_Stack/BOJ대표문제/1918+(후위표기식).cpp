#include <string>
#include <stack>
#include <deque>
#include <iostream>
using namespace std;

/*
	중위 표기식 -> 후위 표기식으로 바꿀때 Stack을 이용한다.
	
	핵심 : '연산자'는 스택이 비어있지 않으면',                  while(!S.empty() && pr(S.top()) >= pr(c)) {
	        
			스택에 있는 연산자(top)와의 우선순위를 비교해
			
			스택에 있는 연산자(top)의 우선순위가 같거나 크다면
			 
			스택에 있는 연산자를 모두 pop을 한 후 출력하고      {
			
			현재 연산자는 스택에 push한다.                       S.push(c);


	후위 표기식 계산할 때에도 Stack을 이용한다. 
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
		if (c >= 'A' && c <= 'Z') cout << c; //피연산자 그대로 출력
		else if (c == '(') st.push(c); //열린 괄호는 push
		else if (c == ')') {  //닫힌 괄호면 열린 괄호가 나올때 까지 출력
			while (st.top() != '(') {
				cout << st.top(); st.pop();
			}
			st.pop();//여는 괄호는 출력X
		}
		else { //★ 연산자의 경우
			while (!st.empty() && pr(st.top()) >= pr(c)) { //스택의 Top과의 우선순위 비교해서 스택이 같거나 높다면 출력 한다.
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

