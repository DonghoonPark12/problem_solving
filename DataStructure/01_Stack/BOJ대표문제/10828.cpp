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
	while (n-- > 0) { //n이 14 라면 14번 돈다
		//getline(cin, str, ' '); //이러면 push 1 이렇게 받게 되고, 그다음은 \n push 2 이렇게 받는다. 
		//scanf(" %s", str);
		cin >> str;
		if (str.compare("push")==0) { //사전 순이기 때문에 같으면 0을 반환한다. 
			cin >> m;
			s.push(m);
		}
		else if (str.compare("pop")==0) { //혹은 (str == "pop") 처럼 string은 == " "으로 직접 비교 가능하다!!
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
				printf("-1\n"); // 스택에 들어 있는 정수가 없으면 -1을 출력하라 했다. 문제 똑바로 읽자.
		}
		else {

		}
	}
	return 0;
}