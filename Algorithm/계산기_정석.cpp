#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int get_priority(char c) {
	switch (c) {
	case '*':
		return 3;
	case '+':
		return 2;
	case ')':
		return 1;
	case '(':
		return 0;
	}
	return -1;
}

void infix_to_postfix(string &str) {
	string out = "";
	int currPriority;
	stack<char> op;
	int size = str.size();

	for (int i = 0; i < size; i++) {
		currPriority = get_priority(str[i]);
		if (currPriority == -1)
			out.push_back(str[i]);
		else {
			while (!op.empty() && currPriority && get_priority(op.top()) > currPriority) {
				out.push_back(op.top());
				op.pop();
			}
			if (!op.empty() && op.top() == '(' && str[i] == ')') {
				op.pop();
			}
			else {
				op.push(str[i]);
			}
		}
	}
	while (!op.empty()) {
		out.push_back(op.top());
		op.pop();
	}

	str = out;
}

int evaluate_postfix(string str) {

	int temp1, temp2;
	stack<int> s;
	int size = str.size();

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
	int T = 10, N;
	string str;

	for (int t = 1; t <= T; t++) {
		scanf("%d\n", &N);
		cin >> str;

		infix_to_postfix(str);

		printf("#%d %d\n", t, evaluate_postfix(str));
	}

	return 0;
}