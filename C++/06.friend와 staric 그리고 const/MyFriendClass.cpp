#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//class Girl; //��� �ȴ�. 11���� GirlŬ������ �������� �˸���.

class Boy {
private:
	int height;
	friend class Girl; //Girl Ŭ������ ���� friend ����(�ΰ��� ����: Girl Ŭ������ �����Ѵ�, Girl Ŭ������ ������� �����Ѵ�)
public:
	Boy(int len)
		: height(len)
	{}
	void ShowYourFriendInfo(Girl &frn);
	//friend class Girl; //Girl Ŭ������ ���� friend ����
};

class Girl {
private:
	char phNum[20];
public:
	Girl(char *num) {
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy; //Boy Ŭ������ ���� friend ����
};

void Boy::ShowYourFriendInfo(Girl &frn) {
	cout << "Her phone number: " << frn.phNum << endl; //GirlŬ������ ������� phNum�� ���縦 �˱� ���ؼ� GirlŬ������ �ڿ� 
}                                                      // BoyŬ������ ����Լ��� �����Ѵ�.

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


