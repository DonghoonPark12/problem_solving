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
		if (curPriority < 0)// �� �������� ���
			out.push_back(str[i]);//��� string�� push_back``
		else {
			// ������ top�� �ִ� �ͺ��� ���� �����ڰ� �� ũ�ٸ�, 
			// ����, str�� �ִ´�. ������ �� �д�. 
			while (!op.empty() && curPriority && get_priority(op.top()) > curPriority) {
				out.push_back(op.top());
				op.pop();
			}
			if (!op.empty() && op.top() == '(' && str[i] == ')') {
				op.pop();
			}
			else {
				//������ ����ٸ� �ϴ� �ִ´�.
				op.push(str[i]);//�����ڴ� op Stack�� push
			}
		}
	}

	while (!op.empty()) {
		out.push_back(op.top());
		op.pop();
	}

	str = out; //������� String�� �Ѱ��� ���� �ִ�. 
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
	string str; //C++ string �ڷ��� ����
	for (int test_case = 1; test_case <= 10; test_case++){
		scanf("%d\n", &N);
		cin >> str;

		infix_to_postfix(str);

		printf("#%d %d\n", test_case, evaluate_postfix(str));

	}
	return 0;
}