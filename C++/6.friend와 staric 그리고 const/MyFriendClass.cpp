#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//class Girl; //없어도 된다. 11행이 Girl클래스가 존재함을 알린다.

class Boy {
private:
	int height;
	friend class Girl; //Girl 클래스에 대한 friend 선언(두가지 역할: Girl 클래스가 존재한다, Girl 클래스를 프렌드로 선언한다)
public:
	Boy(int len)
		: height(len)
	{}
	void ShowYourFriendInfo(Girl &frn);
	//friend class Girl; //Girl 클래스에 대한 friend 선언
};

class Girl {
private:
	char phNum[20];
public:
	Girl(char *num) {
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy; //Boy 클래스에 대한 friend 선언
};

void Boy::ShowYourFriendInfo(Girl &frn) {
	cout << "Her phone number: " << frn.phNum << endl; //Girl클래스의 멤버변수 phNum의 존재를 알기 위해서 Girl클래스의 뒤에 
}                                                      // Boy클래스의 멤버함수를 정의한다.

void Girl::ShowYourFriendInfo(Boy &frn) {
	cout << "His height: " << frn.height << endl;
}

int main() {
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}


