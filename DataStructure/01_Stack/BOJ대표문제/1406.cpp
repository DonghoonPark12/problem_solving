#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
using namespace std;
/*
	���ڿ� ���̰� 100,000���� �����Ѵٸ�(M), O(M^2) ��ŭ ������ ���� �� �ִ�. 
	�ֳ��ϸ� �Ź� ���ڰ� �տ� �߰��ȴٰ� ���� ��, ���ڿ��� ����(M) ��ŭ �̵�������� �ϱ� �����̴�.
*/

/*
* Vector<char>�δ� �� �ȉ���� ������ �� ��. it ���꿡�� ������ ����. 
*
* �������� �Է¹��� string�� list<char> editor(s.begin(), s.end()) �ؼ� Ǯ����.
* � ������ �ִ��� ������ �� ��.
*/

/*
* 
* L: Ŀ���� �������� �ű� ���� it--
*  : Ŀ���� ������ �� ���̸� it--; if(it<0) ���ǹ�;
* D: it++;
*  : 
* �߰��� ���� �߰��ϴ� v.insert(it, ��)�� �ʿ��� ��.
*/

int main() {
	string s = " ";
	int n;//��ɹ� ��
	//int max;//Ŀ��, ���ڿ� ����
	//char c;
	char p;//P ��ɿ��� �Էµ� ����
	char o;
	//scanf("%s", s);
	//vector<char> s;
	//while ((c = getchar()) != '\n') {
	//	s.push_back((char)c);
	//}
	//getline(cin, s); //��Ʈ�� ������ �Ϸ� �Ͽ�����, ������ ����,
	list<char> editor(s.begin(), s.end()); // list�� �־� �ش�. 
	auto it = editor.end(); //string ������ iterator�� ��� ���� �ϴ�. 
	//max = s.size();
	//it = max = s.size();//�� ������ ����. 

	scanf(" %d", &n);

	while (n--) {
		scanf(" %c", &o);
		switch (o) {
		case 'L': {
			//--it; //���⼭ �� ������ ����?

			//if (it < s.begin()) { ���ٴ� �Ʒ� ������ 
			//	it = s.begin();
			//}
			if (it != editor.begin())
				it--;
			break;
		}
		case 'D': {
			//it++; it�� NULL ���� ���������� ���� ���� ���. 
			//if (it >= s.end()) {
			//	it = s.end();
			//}

			if (it != editor.end()) {
				it++;
			}
			break;
		}
		case 'P': {
			scanf(" %c", &p);
			//p = stoi(s);
			//s.insert(it, c); string �� insert�� "c" ������ ���� �Է¸� ����
			//s.insert(it, p);
			editor.insert(it, p);
			it++;//Ŀ�� ���ʿ� �߰� �ϱ� ���Ͽ�.
			break;
		}
		case 'B': {
			if (it != editor.begin()) {
				auto tmp = it;
				it--;
				editor.erase(it);
				it = tmp;
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	//printf("%s", &s); //���ڿ� '%s'�� 'char *' ������ �μ��� �ʿ�

	for (char c : editor) { //list ���
		cout << c;
	}
	cout << '\n';
	return 0;
}


#include <iostream>
#include <list>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;

	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();

	int n;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor != editor.begin()) {
				--cursor;
			}
		}
		else if (cmd == 'D') {
			if (cursor != editor.end()) {
				++cursor;
			}
		}
		else if (cmd == 'B') { //O(���ڿ� ����)
			if (cursor != editor.begin()) {
				auto temp = cursor;
				--cursor;
				editor.erase(cursor);
				cursor = temp;
			}
		}
		else if (cmd == 'P') { //O(���ڿ� ����)
			char c;
			cin >> c;
			editor.insert(cursor, c);
		}
	}

	for (char c : editor) {
		cout << c;
	}
	cout << '\n';

	return 0;
}