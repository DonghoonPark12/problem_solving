//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <stdlib.h>
//using namespace std;
//
//#define ABS(n) ( ((n) > 0) ? (n) : -(n) )
//
//int main()
//{
//	int cnt = 0;
//	int n; cin >> n;
//	cin.ignore();
//	//char arr[100][11];
//	string s[100];
//	
//	int j = 0;
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, s[i]);
//		sort(s[i].begin(), s[i].end());
//	}
//
//	int _size = s[0].size();
//	for (int i = 1; i < n; i++)
//	{
//		if (_size == s[i].size())
//		{
//			//(크기가 같으며) 같은 구성을 가진 경우
//			if (s[0].compare(s[i]) == 0) 
//			{
//				cnt++;
//			}
//			else
//			{
//				//혹은 크기가 같지만, 하나만 다른 경우
//				int sw = 0;
//				for (j = 0; j < s[i].size(); j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//				}
//				if ( ABS(sw - _size) == 1)
//					cnt++;
//			}
//		}
//		else
//		{
//			//하나 추가하거나 빼었을 때
//			if (_size - s[i].size() == 1)
//			{
//				int sw = 0;
//				for (j = 0; j < s[i].size(); j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//				}
//				if (sw == s[i].size())
//					cnt++;
//			}
//			else if(s[i].size() - _size == 1)
//			{
//				int sw = 0;
//				for (j = 0; j < _size; j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//					else
//						break;
//				}
//				if (sw == _size)
//					cnt++;
//			}
//		}
//	}
//	cout << cnt;
//	return 0;
//}

#include<iostream>
#include<string>
#include <cstring>

using namespace std;
int first_voca[26] = { 0 }; //대문자 갯수  26개
int voca[26] = { 0, };
int main() {
    int n; 
    string st; 
    cin >> n >> st; // 단어의 개수와 첫 단어 입력
    for (int i = 0; i < st.size(); i++) 
{
        first_voca[st[i] - 'A']++; // 첫 번째 단어A의 각 알파벳의 개수를 counting
    }
    int answer = 0;
    int ch1, ch2;
    for (int i = 0; i < n - 1; i++) { // 다음에 오는 단어들과 첫 번째 단어가 같은지 확인하고 같으면 answer 증가
        string s;
        cin >> s;
        ch1 = 0;
        ch2 = 0;

        memset(voca, 0, sizeof(voca));

        // 다음에 오는 단어B의 각 알파벳의 개수를 counting
        for (int j = 0; j < s.size(); j++) 
        { 
            voca[s[j] - 'A']++;
        }
        for (int j = 0; j < 26; j++) {
            // A가 B보다 많은 알파벳의 개수
            if (first_voca[j] > voca[j])
                ch1 += first_voca[j] - voca[j]; 

            // A가 B보다 적은 알파벳의 개수
            if (first_voca[j] < voca[j])
                ch2 += voca[j] - first_voca[j]; 
        }
        if (ch1 <= 1 && ch2 <= 1)
            answer++; // 둘다 1이하이면 비슷한 단어
    }
    cout << answer << endl;
}//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <stdlib.h>
//using namespace std;
//
//#define ABS(n) ( ((n) > 0) ? (n) : -(n) )
//
//int main()
//{
//	int cnt = 0;
//	int n; cin >> n;
//	cin.ignore();
//	//char arr[100][11];
//	string s[100];
//	
//	int j = 0;
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, s[i]);
//		sort(s[i].begin(), s[i].end());
//	}
//
//	int _size = s[0].size();
//	for (int i = 1; i < n; i++)
//	{
//		if (_size == s[i].size())
//		{
//			//(크기가 같으며) 같은 구성을 가진 경우
//			if (s[0].compare(s[i]) == 0) 
//			{
//				cnt++;
//			}
//			else
//			{
//				//혹은 크기가 같지만, 하나만 다른 경우
//				int sw = 0;
//				for (j = 0; j < s[i].size(); j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//				}
//				if ( ABS(sw - _size) == 1)
//					cnt++;
//			}
//		}
//		else
//		{
//			//하나 추가하거나 빼었을 때
//			if (_size - s[i].size() == 1)
//			{
//				int sw = 0;
//				for (j = 0; j < s[i].size(); j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//				}
//				if (sw == s[i].size())
//					cnt++;
//			}
//			else if(s[i].size() - _size == 1)
//			{
//				int sw = 0;
//				for (j = 0; j < _size; j++)
//				{
//					if (s[0][j] == s[i][j])
//						sw++;
//					else
//						break;
//				}
//				if (sw == _size)
//					cnt++;
//			}
//		}
//	}
//	cout << cnt;
//	return 0;
//}

#include<iostream>
#include<string>
#include <cstring>

using namespace std;
int first_voca[26] = { 0 }; //대문자 갯수  26개
int voca[26] = { 0, };
int main() {
    int n; 
    string st; 
    cin >> n >> st; // 단어의 개수와 첫 단어 입력
    for (int i = 0; i < st.size(); i++) 
{
        first_voca[st[i] - 'A']++; // 첫 번째 단어A의 각 알파벳의 개수를 counting
    }
    int answer = 0;
    int ch1, ch2;
    for (int i = 0; i < n - 1; i++) { // 다음에 오는 단어들과 첫 번째 단어가 같은지 확인하고 같으면 answer 증가
        string s;
        cin >> s;
        ch1 = 0;
        ch2 = 0;

        memset(voca, 0, sizeof(voca));

        // 다음에 오는 단어B의 각 알파벳의 개수를 counting
        for (int j = 0; j < s.size(); j++) 
        { 
            voca[s[j] - 'A']++;
        }
        for (int j = 0; j < 26; j++) {
            // A가 B보다 많은 알파벳의 개수
            if (first_voca[j] > voca[j])
                ch1 += first_voca[j] - voca[j]; 

            // A가 B보다 적은 알파벳의 개수
            if (first_voca[j] < voca[j])
                ch2 += voca[j] - first_voca[j]; 
        }
        if (ch1 <= 1 && ch2 <= 1)
            answer++; // 둘다 1이하이면 비슷한 단어
    }
    cout << answer << endl;
}