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
//			//(ũ�Ⱑ ������) ���� ������ ���� ���
//			if (s[0].compare(s[i]) == 0) 
//			{
//				cnt++;
//			}
//			else
//			{
//				//Ȥ�� ũ�Ⱑ ������, �ϳ��� �ٸ� ���
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
//			//�ϳ� �߰��ϰų� ������ ��
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
int first_voca[26] = { 0 }; //�빮�� ����  26��
int voca[26] = { 0, };
int main() {
    int n; 
    string st; 
    cin >> n >> st; // �ܾ��� ������ ù �ܾ� �Է�
    for (int i = 0; i < st.size(); i++) 
{
        first_voca[st[i] - 'A']++; // ù ��° �ܾ�A�� �� ���ĺ��� ������ counting
    }
    int answer = 0;
    int ch1, ch2;
    for (int i = 0; i < n - 1; i++) { // ������ ���� �ܾ��� ù ��° �ܾ ������ Ȯ���ϰ� ������ answer ����
        string s;
        cin >> s;
        ch1 = 0;
        ch2 = 0;

        memset(voca, 0, sizeof(voca));

        // ������ ���� �ܾ�B�� �� ���ĺ��� ������ counting
        for (int j = 0; j < s.size(); j++) 
        { 
            voca[s[j] - 'A']++;
        }
        for (int j = 0; j < 26; j++) {
            // A�� B���� ���� ���ĺ��� ����
            if (first_voca[j] > voca[j])
                ch1 += first_voca[j] - voca[j]; 

            // A�� B���� ���� ���ĺ��� ����
            if (first_voca[j] < voca[j])
                ch2 += voca[j] - first_voca[j]; 
        }
        if (ch1 <= 1 && ch2 <= 1)
            answer++; // �Ѵ� 1�����̸� ����� �ܾ�
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
//			//(ũ�Ⱑ ������) ���� ������ ���� ���
//			if (s[0].compare(s[i]) == 0) 
//			{
//				cnt++;
//			}
//			else
//			{
//				//Ȥ�� ũ�Ⱑ ������, �ϳ��� �ٸ� ���
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
//			//�ϳ� �߰��ϰų� ������ ��
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
int first_voca[26] = { 0 }; //�빮�� ����  26��
int voca[26] = { 0, };
int main() {
    int n; 
    string st; 
    cin >> n >> st; // �ܾ��� ������ ù �ܾ� �Է�
    for (int i = 0; i < st.size(); i++) 
{
        first_voca[st[i] - 'A']++; // ù ��° �ܾ�A�� �� ���ĺ��� ������ counting
    }
    int answer = 0;
    int ch1, ch2;
    for (int i = 0; i < n - 1; i++) { // ������ ���� �ܾ��� ù ��° �ܾ ������ Ȯ���ϰ� ������ answer ����
        string s;
        cin >> s;
        ch1 = 0;
        ch2 = 0;

        memset(voca, 0, sizeof(voca));

        // ������ ���� �ܾ�B�� �� ���ĺ��� ������ counting
        for (int j = 0; j < s.size(); j++) 
        { 
            voca[s[j] - 'A']++;
        }
        for (int j = 0; j < 26; j++) {
            // A�� B���� ���� ���ĺ��� ����
            if (first_voca[j] > voca[j])
                ch1 += first_voca[j] - voca[j]; 

            // A�� B���� ���� ���ĺ��� ����
            if (first_voca[j] < voca[j])
                ch2 += voca[j] - first_voca[j]; 
        }
        if (ch1 <= 1 && ch2 <= 1)
            answer++; // �Ѵ� 1�����̸� ����� �ܾ�
    }
    cout << answer << endl;
}