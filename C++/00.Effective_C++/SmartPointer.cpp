#include <memory>
#include <iostream>
using namespace std;
/*
	스마트 포인터
	: 포인터 처럼 동작하는 클래스 템플릿

	보통 new 키워드를 이용해 기본 포인터가 실제 메모리를 가리키게 한 후에,
	스마트 포인터(기본 포인터) 형식으로 사용한다. 

	C+11 이전 - auto_ptr
	C+11 이후 - unique_ptr, shared_ptr, weak_ptr
*/

/*
	(1)
	C++11 이후
	unique_ptr : 하나의 스마트 포인터만이 특정 객체를 소유.
				 객체에 소유권 개념을 도입.
				 해당 객체의 소유권을 가지고 있을 때만, 소멸자가 해당 객체 삭제 가능.
				 delete를 사용하여 메모리 해제 필요 없다.
*/
unique_ptr<int> ptr01(new int(5)); //int형 unique_ptr인 ptr01을 선언하고 초기화
cout << *ptr01 << '\n'; //포인터 처럼 동작하여 실제 값 출력 가능

auto ptr02 = move(ptr01); //ptr01에서 ptr02로 소유권 이전
						  //ptr01가 관리하는 데이터 주소 값을 ptr03가 갖게 된다. 
cout << ptr01.get() << '\n'; //.get()은 실제 주소값을 얻는 메소드
cout << ptr03.get() << '\n';

//unique_ptr<int> ptr3 = ptr01; //대입 연산자를 이용한 소유권 이전은 Error.

ptr01.reset(); //ptr02가 가리키는 메모리 영역 삭제. 그런데 형식 지정자가 없다??
ptr02.reset();

/*
	C++14 이후
	make_unique() 함수 사용하면 unique_ptr 객체를 안전하게 생성.
	전달받은 인수를 사용해 지정된 타입의 객체를 생성하고,
	생성된 객체를 가리키는 unique_ptr을 반환.
	본 함수 사용하면, 예외 발생에 안전하게 대처 가능.
*/

#include <iostream>
#include <memory>
using namespace std;

class Person{
private:
	string name_;
	int age_;
public:
	Person(const string& name, int age); // 기초 클래스 생성자의 선언
	~Person() { cout << "소멸자가 호출되었습니다." << endl; }
	void ShowPersonInfo();
};
int main(void) {
	unique_ptr<Person> hong = make_unique<Person>("길동", 29);
	hong->ShowPersonInfo();
	return 0;
}
Person::Person(const string& name, int age){ // 기초 클래스 생성자의 정의{
	name_ = name;
	age_ = age;
	cout << "생성자가 호출되었습니다." << endl;
}

void Person::ShowPersonInfo() { 
	cout << name_ << "의 나이는 " << age_ << "살입니다." << endl; 
}


/*
	(2)
	shared_ptr : 하나의 특정 객체를 참조하는 스마트 포인터가 총 몇개인지 참조하는 스마트 포인터.
				 참조 횟수가 계산되는 스마트 포인터.
				 참조 갯수가 0일 경우 데이터를 메모리에서 해제.
				 원시 포인터 하나를 여러 소유자에게 할당할 경우 사용된다.
				 절대! 서로가 상대방 객체를 가리키게 해서는 참조가 0이 될 수 없다. --> 메모리 해제 안됨.
*/

shared_ptr<int> ptr01(new int(5));
cout << ptr01.use_count() << endl; //1
auto ptr02(ptr01);  //복사 생성자를 이용한 초기화
cout << ptr01.use_count() << endl; //2
auto ptr03 = ptr01; //대입을 통한 초기화
cout << ptr01.use_count() << endl; //3

shared_ptr<Person> p1 = make_shared<Person>("길동", 29);
cout << "현재 소유자 수 : " << p1.use_count() << endl; // 1
auto p2 = p1; // 대입 연산자를 이용한 초기화
cout << "현재 소유자 수 : " << p1.use_count() << endl; // 2
p2.reset(); // shared_ptr인 p2을 해제함.
cout << "현재 소유자 수 : " << p1.use_count() << endl; // 1

/*
	weak_prt : 하나 이상의 shared_ptr 객체가 소유하는 객체에 대한 접근을 제공하지만,
			   소유자의 수에는 포함되지 않는 스마트 포인터.
			   객체를 관찰하지만 동시에 해당 객체를 활성 상태로 유지 하지 않으려는 경우 사용된다.
			   shared_ptr에서 서로가 상대방을 참조하고 있는 상황을 순환 참조(circular reference)라고 하는데,
			   순환 참조를 제거하기 위해 사용된다. 
*/
shared_ptr<int> sp1(new int(10));
weak_ptr<int> wp1 = sp1;

cout << sp1.use_count() << endl; //1 
cout << wp1.use_count() << endl; //1
{
	shared_ptr<int> sp2 = wp1.lock(); //weak_ptr의 lock 매소드가 실행도면 shared_ptr 객체가 생성.

	cout << sp1.use_count() << endl; //2
	cout << wp1.use_count() << endl; //2, 실제 데이터에는 3개의 스마트 포인터가 가리킴
} //이때 sp2 객체가 소멸 되며 sp2 객체가 소멸(데이터가 사라지는건 아니다!!)