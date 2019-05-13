#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
using namespace std;
/*
* Vector<char>로는 왜 안됬는지 생각해 볼 것. it 연산에서 에러가 났다. 
*
* 예제에는 입력받은 string을 list<char> editor(s.begin(), s.end()) 해서 풀었다.
* 어떤 장점이 있는지 생각해 볼 것.
*/

/*
* 
* L: 커서를 왼쪽으로 옮길 때는 it--
*  : 커서가 문장의 맨 앞이면 it--; if(it<0) 조건문;
* D: it++;
*  : 
* 중간에 값을 추가하는 v.insert(it, 값)이 필요할 듯.
*/

int main() {
	string s = " ";
	int n;//명령문 수
	//int max;//커서, 문자열 길이
	//char c;
	char p;//P 명령에서 입력된 문자
	char o;
	//scanf("%s", s);
	//vector<char> s;
	//while ((c = getchar()) != '\n') {
	//	s.push_back((char)c);
	//}
	//getline(cin, s); //스트링 만으로 하려 하였으나, 에러가 떴고,
	list<char> editor(s.begin(), s.end()); // list에 넣어 준다. 
	auto it = editor.end(); //string 형에도 iterator가 사용 가능 하다. 
	//max = s.size();
	//it = max = s.size();//맨 끝으로 간다. 

	scanf(" %d", &n);

	while (n--) {
		scanf(" %c", &o);
		switch (o) {
		case 'L': {
			//--it; //여기서 왜 오류가 날까?

			//if (it < s.begin()) { 보다는 아래 식으로 
			//	it = s.begin();
			//}
			if (it != editor.begin())
				it--;
			break;
		}
		case 'D': {
			//it++; it이 NULL 보다 오른쪽으로 가면 에러 뜬다. 
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
			//s.insert(it, c); string 의 insert는 "c" 식으로 직접 입력만 가능
			//s.insert(it, p);
			editor.insert(it, p);
			it++;//커서 왼쪽에 추가 하기 위하여.
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
	//printf("%s", &s); //문자열 '%s'에 'char *' 형식의 인수가 필요

	for (char c : editor) { //list 출력
		cout << c;
	}
	cout << '\n';
	return 0;
}