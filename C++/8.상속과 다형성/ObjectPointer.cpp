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
	Person *ptr1 = new Student(); // Student는 Person을 상속하므로, Person형 포인터 변수는 Student 객체를 가리킬 수 있다. 
	Person *ptr2 = new PartTimeStudent(); //PartTimeStudent는 Person을 간접상속하므로, Person형 포인터는 PartTimeStudent 객체를 가리킬 수 있다. 
	Student *ptr3 = new PartTimeStudent(); //PartTimeStudent는 Student를 상속하므로, Student형 포인터는 PartTimeStudent 객체를 가리킬 수 있다. 

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1, ptr2, ptr3;
	return 0;
}