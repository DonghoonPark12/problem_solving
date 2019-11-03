#include <iostream>
using namespace std;

class Person {
public:
	void Sleep() { cout << "Sleep" << '\n'; }
};

class Student:public Person {
public:
	void Study() { cout << "Study" << '\n'; }
};

class PartTimeStudent :public Student {
public:
	void Work() { cout << "Work" << '\n'; }
};

int main() {
	Person *ptr1 = new Student(); // Student�� Person�� ����ϹǷ�, Person�� ������ ������ Student ��ü�� ����ų �� �ִ�. 
	Person *ptr2 = new PartTimeStudent(); //PartTimeStudent�� Person�� ��������ϹǷ�, Person�� �����ʹ� PartTimeStudent ��ü�� ����ų �� �ִ�. 
	Student *ptr3 = new PartTimeStudent(); //PartTimeStudent�� Student�� ����ϹǷ�, Student�� �����ʹ� PartTimeStudent ��ü�� ����ų �� �ִ�. 

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1, ptr2, ptr3;
	return 0;
}