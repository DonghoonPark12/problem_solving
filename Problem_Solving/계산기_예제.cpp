
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int N;
string str;

int main()
{
	std::ios::sync_with_stdio(false);
	for (int T = 1; T <= 10; T++)
	{
		vector<int> v; // 후위 표기법으로
		stack<int> st; // sub stack
		cin >> N >> str;
		for (int i = 0; i < N; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				v.push_back(str[i] - '0');

			else if (str[i] == '(') st.push('(');
			else if (str[i] == ')')
			{
				while (st.top() != '(')
				{
					v.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			else if (str[i] == '*') st.push('*');
			else // '+'
			{
				if (st.empty()) st.push('+');
				else
				{
					while (st.top() == '*')
					{
						v.push_back(st.top());
						st.pop();
					}
					st.push('+');
				}
			}
		}

		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}

		stack<int> ans;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= 0 && v[i] <= 9)
				ans.push(v[i]);

			else
			{
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				if (v[i] == '+') ans.push(a + b);
				else ans.push(a*b);
			}
		}
		cout << "#" << T << " " << ans.top() << "\n";
	}
	return 0;
}