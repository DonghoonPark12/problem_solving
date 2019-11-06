#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class person {
private:
	char *name; 
	int age;
public:
	person(char *myname, int myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPerson() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	//person(const person &copy)
	//	:age(copy.age)
	//{
	//	name = new char[strlen(copy.name) + 1];//이렇게 하면 복사 생성자가 하나의 문자열을 공유하지 않는다. 
	//	strcpy(name, copy.name);
	//}

	~person() {
		delete[]name;
		cout << "call destructor!" << endl;
	}
};
int main() {
	person man1("Lee Dong Hun", 29);
	person man2 = man1; //얕은 복사 
	man1.ShowPerson();
	man2.ShowPerson();
}