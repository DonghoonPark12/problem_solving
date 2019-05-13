#include <iostream>
using namespace std;

class SoSimple {
public:
	static int simObjCnt;
public:
	SoSimple() {
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main() {
	cout << SoSimple::simObjCnt << "번째 soSimple 객체" << endl; //클래스의 이름을 이용해서 접근하는 것을 권장. 
	SoSimple sim1;
	SoSimple sim2;

	cout << sim1.simObjCnt << "번째 soSimple 객체" << endl; //멤버변수에 접근하는 것과 같은 착각을 불러 일으킨다. 
	cout << sim2.simObjCnt << "번째 soSimple 객체" << endl;
	return 0;
}
