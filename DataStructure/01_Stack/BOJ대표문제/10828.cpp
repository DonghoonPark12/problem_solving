#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

#define STACK_CAPACITY 10000

int main() {
	int n, m; //scanf("%d\n", &n);
	cin >> n;
	string str;
	stack<int> s;
	while (n-- > 0) { //n�� 14 ��� 14�� ����
		//getline(cin, str, ' '); //�̷��� push 1 �̷��� �ް� �ǰ�, �״����� \n push 2 �̷��� �޴´�. 
		//scanf(" %s", str);
		cin >> str;
		if (str.compare("push")==0) { //���� ���̱� ������ ������ 0�� ��ȯ�Ѵ�. 
			cin >> m;
			s.push(m);
		}
		else if (str.compare("pop")==0) { //Ȥ�� (str == "pop") ó�� string�� == " "���� ���� �� �����ϴ�!!
			if (s.empty() != 1) {
				printf("%d\n", s.top());
				s.pop();
			}
			else 
				printf("-1\n");
		}
		else if (str.compare("size")==0) {
			printf("%d\n",s.size());
		}
		else if (str.compare("empty")==0) {
			printf("%d\n", s.empty());
		}
		else if (str.compare("top")==0) {
			if (s.empty() != 1) {
				printf("%d\n", s.top());
			}
			else
				printf("-1\n"); // ���ÿ� ��� �ִ� ������ ������ -1�� ����϶� �ߴ�. ���� �ȹٷ� ����.
		}
		else {

		}
	}
	return 0;
}