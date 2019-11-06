#define	_CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
int N, flag, idx;
char map[405], stack[205];
int main(void)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	for (int i = 0; i < 10; i++) {
		scanf("%d\n", &N);
		scanf("%s\n", &map);
		idx = 0;
		flag = 1;
		for (int j = 0; j<N; j++)
		{
			if (map[j] == '(' || map[j] == '[' || map[j] == '{' || map[j] == '<')
				stack[idx++] = map[j];
			else {
				if (stack[--idx] / 10 != map[j] / 10) {
					flag = 0;
					break;
				}
			}
		}
		if (idx != 0)   flag = 0; //A2_��â�� ���� stack[]�� ����� �ʴ´�.
		printf("#%d %d\n", i + 1, flag);
	}
	return 0;
}
*/
/*
#include <iostream>
#include <stack>

using namespace std;

int n;
char ch;

bool f(stack<char> &s)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	cin >> n;
	while (n--) {
		cin >> ch;
		if (!s.empty()) {
			if (s.top() + 2 == ch || s.top() + 1 == ch) {
				s.pop(); continue;
			}
		}
		s.push(ch);
	}
	return s.empty() ? 1 : 0;
}

int main()
{
	// ios::sync_with_stdio(false); �� �� stdio�� iostream�� ���������� ������ �� �ֵ��� �㰡���ִ� �� 
	// ios::sync_with_stdio�� cpp�� iostream�� c�� stdio�� ����ȭ�����ִ� ����

	ios::sync_with_stdio(false); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		stack<char> s;
		cout << '#' << tc << ' ' << f(s) << '\n';
	}
	return 0;
}
*/
/*
	Sets whether the standard C++ streams are synchronized to the standard C streams after each input/output operation.

	The standard C++ streams are the following: std::cin, std::cout, std::cerr, std::clog, std::wcin, std::wcout, std::wcerr and std::wclog

	The standard C streams are the following: stdin, stdout and stderr
*/


#include <stdio.h>
int N;
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	while (scanf("%d", &N) != EOF) {
		int res = 1;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for (int i = 1; i <= N; i++) {
			char x; scanf(" %c", &x);
			if (x == '(') cnt1++;
			if (x == ')') cnt1--;

			if (x == '[') cnt2++;
			if (x == ']') cnt2--;

			if (x == '{') cnt3++;
			if (x == '}') cnt3--;

			if (x == '<') cnt4++;
			if (x == '>') cnt4--;

			if (cnt1 < 0 || cnt2 < 0 || cnt3 < 0 || cnt4 < 0) res = 0;
		}
		if (!(cnt1 == 0 && cnt2 == 0 && cnt3 == 0 && cnt4 == 0)) res = 0;
		static int tc = 0;
		printf("#%d %d\n", ++tc, res);
	}
}
/*
* < { [] [ [ { ] ���� ]�� �ʱ� ������ �������� ���Ѵ�.
* �ٸ�, ¦�� ��� ������ cnt1~4�� ��� 0�� �Ǵ� ������ ������ ��.
*/