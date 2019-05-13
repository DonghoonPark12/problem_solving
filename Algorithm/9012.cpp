#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

int N;
char s[51];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		stack<char> st;
		scanf("%s", s);
		for (int i = 0; s[i]; i++) {
			if (s[i] == '(') st.push(s[i]);
			else if (!st.empty() && st.top() == '(') st.pop();
			else st.push(s[i]);
		}
		if (st.empty()) printf("YES\n");
		else printf("NO\n");
	}
}



//#define	_CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//char tmp_arr[50];
//char stack[50];
//int top = -1;
//int pop();
//void push(char n);
//int pair_(char l, char r);
//int main(void)
//{
//	int N;
//	int Answer = 0;
//	freopen("input.txt", "r", stdin);
//	scanf("%d ", &N);
//	char tmp;
//	for (int i=0; i < N; i++) {
//		while (scanf("%c", &tmp)>0) { //파일의 끝(EOF)면 -1이 반환, 맨마지막 예제는 줄바꿈 문자열이 아니라 EOF 이다. 
//			if (tmp == 10) break;
//			push(tmp);
//			if ( (top != 0) && pair_(stack[top-1], stack[top] )) {
//				pop(); pop();
//			}
//		}
//		if (top != -1)
//			cout << "NO" << endl;
//		else 
//			cout << "YES" << endl;
//		top = -1;//stack reset
//	}
//
//	return 0;
//
//}
//
//int pair_(char l, char r) {
//	if ((l == '(') && (r == ')'))
//		return 1;
//	else
//		return 0;
//}
//int pop() {
//	if (top < 0)
//		return 0;
//	else
//		return stack[top--];
//}
//
//void push(char n) {
//	if (top == 50 - 1)
//		return;
//	else
//		stack[++top] = n;
//}
