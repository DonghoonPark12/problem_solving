#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int get_priority(char c){
	switch (c){
	case '(':
		return 0; break;
	case '*':
		return 3; break;
	case '+':
		return 2; break;
	case ')':
		return 1; break;
	default:
		return -1;
	}
}

void infix_to_postfix(string &str){
	string out = " ";
	int curPriority;
	stack<char> op;
	int size = str.size();

	for (int i = 0; i < size; i++){
		curPriority = get_priority(str[i]);
		if (curPriority < 0)// 피 연산자일 경우
			out.push_back(str[i]);//출력 string에 push_back``
		else {
			// 스택의 top에 있는 것보다 현재 연산자가 더 크다면, 
			// 빼서, str에 넣는다. 같으면 놔 둔다. 
			while (!op.empty() && curPriority && get_priority(op.top()) > curPriority) {
				out.push_back(op.top());
				op.pop();
			}
			if (!op.empty() && op.top() == '(' && str[i] == ')') {
				op.pop();
			}
			else {
				//스택이 비었다면 일단 넣는다.
				op.push(str[i]);//연산자는 op Stack에 push
			}
		}
	}

	while (!op.empty()) {
		out.push_back(op.top());
		op.pop();
	}

	str = out; //만들어진 String을 넘겨줄 수도 있다. 
}

int evaluate_postfix(string str) {
	int temp1, temp2;
	int size = str.size();
	stack<int> s;
	
	for (int i = 0; i < size; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			s.push(str[i] - '0');
		else {
			temp1 = s.top(); s.pop();
			temp2 = s.top(); s.pop();
			if (str[i] == '*')
				temp1 *= temp2;
			else if (str[i] == '+')
				temp1 += temp2;
			s.push(temp1);
		}
	}
	return s.top();
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int N;
	string str; //C++ string 자료형 생성
	for (int test_case = 1; test_case <= 10; test_case++){
		scanf("%d\n", &N);
		cin >> str;

		infix_to_postfix(str);

		printf("#%d %d\n", test_case, evaluate_postfix(str));

	}
	return 0;
}