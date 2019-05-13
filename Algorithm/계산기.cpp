#define _CRT_SECURE_NO_WARNINGS
/*
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N, ans, tmp;
string str;

int main()
{

	std::ios::sync_with_stdio(false);
	for (int T = 1; T <= 10; T++)
	{
		ans = 0;
		stack<int> st;
		cin >> N >> str;
		for (int i = 0; i < N; i++)
		{
			if (i & 1)
			{
				if (str[i] == '+') continue;
				else // '*'
				{
					tmp = st.top() * (str[i + 1] - '0');
					st.pop();
					st.push(tmp);
					i++;
				}
			}
			else st.push(str[i] - '0');
		}

		while (!st.empty())
		{
			ans += st.top();
			st.pop();
		}
		cout << "#" << T << " " << ans << "\n";
	}
	return 0;
}
*/

/*
#include<stdio.h>
char a[150];
int main(){
  int test, size;
  freopen("input.txt", "r", stdin);
  setbuf(stdout, NULL);
  for (int test = 1; test <= 10; test++){
    scanf("%d", &size);
    int sum = 0;
    scanf("%s", a);
    int top1 = 0, top2 = 0, val = 0, s1[150], s2[150];
    for (int i = 0; i < size; i++){
      if (a[i] == '+') s2[top2++] = '+';
      else if (a[i] == '*'){s1[top1 - 1] = s1[top1 - 1] * (a[i + 1] - '0');
        i++;
      }
      else s1[top1++] = a[i] - '0';
    }
    for (int i = 0; i<top1; i++) val += s1[i];
    printf("#%d %d\n", test, val);
  }
  return 0;
}
*/



#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    int T = 10, N;
    string str;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
    for (int t = 1; t <= T; t++) {
        scanf("%d\n", &N);
        cin >> str;
 
        int ans = 0, temp = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '+') {
                ans += temp;
                temp = 0;
            }
            if (str[i] >= '0' && str[i] <= '9')
                temp = str[i] - '0';
            if (str[i] == '*') {
                temp *= str[i + 1] - '0';
                i++;
            }
        }
        if (temp > 0) ans += temp;
         
        printf("#%d %d\n", t, ans);
    }
 
    return 0;
}
