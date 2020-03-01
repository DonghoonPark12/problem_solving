#include <iostream>
#include <vector>
using namespace std;
/*
	My code
	pass --> (), [()], ()[()]
	No pass --> ( ()[()] )
*/
//int main() {
//	string str; cin >> str;
//	int len = str.length();
//	vector<char> st;
//	
//	int tmp, value, top;
//	tmp = value = 0; top = -1;
//	for (int i = 0; i < len; i++) {
//		if (str[i] == '[' || str[i] == '(') {
//			st.push_back(str[i]); top++;
//		}
//		if (str[i] == ')' && st.back() == '(') {
//			tmp += 2;
//			if (top > 0 && i + 1 < len) {
//				if (str[i + 1] == ')' && st[top - 1] == '(') {
//					tmp *= 2; st.pop_back(); st.pop_back(); i += 1;
//				}
//				else if (str[i + 1] == ']' && st[top - 1] == '[') {
//					tmp *= 3; st.pop_back(); st.pop_back(); i += 1;
//				}
//				else {
//					st.pop_back();
//				}
//			}
//			else {
//				st.pop_back(); top--;
//			}
//		}
//		else if (str[i] == ']' && st.back() == '[') {
//			tmp += 3;
//			if (top > 0 && i + 1 < len) {
//				if (str[i + 1] == ')' && st[top - 1] == '(') {
//					tmp *= 2; st.pop_back(); st.pop_back(); i += 1;
//				}
//				else if (str[i + 1] == ']' && st[top - 1] == '[') {
//					tmp *= 3; st.pop_back(); st.pop_back(); i += 1;
//				}
//				else {
//					st.pop_back();
//				}
//			}
//			else {
//				st.pop_back(); top--;
//			}
//		}
//		value += tmp; tmp = 0;
//	}
//	if (!st.empty()) {
//		cout << "0"; return 0;
//	}
//	cout << value;
//
//	return 0;
//}



//#include <iostream>
//#include <stack>
//#include <string>
//#include <cmath>
//using namespace std;
//
//string input;
//stack<char> s;
//int main(void){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); //cin 실행속도 향상
//	cin >> input;
//
//	long long result = 0;
//	int temp = 1;
//	bool impossible = false;
//
//	for (int i = 0; i < input.size(); i++)	{
//		if (input[i] == '(')	{
//			temp *= 2;
//			s.push('(');
//		}
//		else if (input[i] == '[')	{
//			temp *= 3;
//			s.push('[');
//		}
//		//불가능한 경우
//		else if (input[i] == ')' && (s.empty() || s.top() != '('))	{
//			impossible = true;	break;
//		}
//
//		else if (input[i] == ']' && (s.empty() || s.top() != '['))	{
//			impossible = true; 	break;
//		}
//		else if (input[i] == ')')	{
//			if (input[i - 1] == '(')
//				result += temp;
//			s.pop();
//			temp /= 2;
//		}
//		else if (input[i] == ']')	{
//			if (input[i - 1] == '[')
//				result += temp;
//			s.pop();
//			temp /= 3;
//		}
//	}
//
//	if (impossible || !s.empty())
//		cout << 0 << "\n";
//	else
//		cout << result << "\n";
//	return 0;
//}

#include <cstdio>
#include <stack>
using namespace std;

int sum, tmp = 1;
char str[33];
stack<char> stk;

int main() {
	scanf("%s", str + 1);

	for (int i = 1; str[i]; i++) {
		switch (str[i]) {
		case '(':
			tmp *= 2, stk.push('('); break;
		case '[':
			tmp *= 3, stk.push('['); break;
		case ')':
			if (str[i - 1] == '(') 
				sum += tmp;
			if (stk.empty()) 
				return 0;
			if (stk.top() == '(') 
				stk.pop();
			tmp /= 2; break;
		case ']':
			if (str[i - 1] == '[') 
				sum += tmp;
			if (stk.empty()) 
				return 0;
			if (stk.top() == '[') 
				stk.pop();
			tmp /= 3;
		}
	}

	printf("%d", stk.empty() ? sum : 0);

	return 0;
}