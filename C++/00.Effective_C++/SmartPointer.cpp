#include <memory>
#include <iostream>
using namespace std;
/*
	����Ʈ ������
	: ������ ó�� �����ϴ� Ŭ���� ���ø�

	���� new Ű���带 �̿��� �⺻ �����Ͱ� ���� �޸𸮸� ����Ű�� �� �Ŀ�,
	����Ʈ ������(�⺻ ������) �������� ����Ѵ�. 

	C+11 ���� - auto_ptr
	C+11 ���� - unique_ptr, shared_ptr, weak_ptr
*/

/*
	(1)
	C++11 ����
	unique_ptr : �ϳ��� ����Ʈ �����͸��� Ư�� ��ü�� ����.
				 ��ü�� ������ ������ ����.
				 �ش� ��ü�� �������� ������ ���� ����, �Ҹ��ڰ� �ش� ��ü ���� ����.
				 delete�� ����Ͽ� �޸� ���� �ʿ� ����.
*/
unique_ptr<int> ptr01(new int(5)); //int�� unique_ptr�� ptr01�� �����ϰ� �ʱ�ȭ
cout << *ptr01 << '\n'; //������ ó�� �����Ͽ� ���� �� ��� ����

auto ptr02 = move(ptr01); //ptr01���� ptr02�� ������ ����
						  //ptr01�� �����ϴ� ������ �ּ� ���� ptr03�� ���� �ȴ�. 
cout << ptr01.get() << '\n'; //.get()�� ���� �ּҰ��� ��� �޼ҵ�
cout << ptr03.get() << '\n';

//unique_ptr<int> ptr3 = ptr01; //���� �����ڸ� �̿��� ������ ������ Error.

ptr01.reset(); //ptr02�� ����Ű�� �޸� ���� ����. �׷��� ���� �����ڰ� ����??
ptr02.reset();

/*
	C++14 ����
	make_unique() �Լ� ����ϸ� unique_ptr ��ü�� �����ϰ� ����.
	���޹��� �μ��� ����� ������ Ÿ���� ��ü�� �����ϰ�,
	������ ��ü�� ����Ű�� unique_ptr�� ��ȯ.
	�� �Լ� ����ϸ�, ���� �߻��� �����ϰ� ��ó ����.
*/

#include <iostream>
#include <memory>
using namespace std;

class Person{
private:
	string name_;
	int age_;
public:
	Person(const string& name, int age); // ���� Ŭ���� �������� ����
	~Person() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }
	void ShowPersonInfo();
};
int main(void) {
	unique_ptr<Person> hong = make_unique<Person>("�浿", 29);
	hong->ShowPersonInfo();
	return 0;
}
Person::Person(const string& name, int age){ // ���� Ŭ���� �������� ����{
	name_ = name;
	age_ = age;
	cout << "�����ڰ� ȣ��Ǿ����ϴ�." << endl;
}

void Person::ShowPersonInfo() { 
	cout << name_ << "�� ���̴� " << age_ << "���Դϴ�." << endl; 
}


/*
	(2)
	shared_ptr : �ϳ��� Ư�� ��ü�� �����ϴ� ����Ʈ �����Ͱ� �� ����� �����ϴ� ����Ʈ ������.
				 ���� Ƚ���� ���Ǵ� ����Ʈ ������.
				 ���� ������ 0�� ��� �����͸� �޸𸮿��� ����.
				 ���� ������ �ϳ��� ���� �����ڿ��� �Ҵ��� ��� ���ȴ�.
				 ����! ���ΰ� ���� ��ü�� ����Ű�� �ؼ��� ������ 0�� �� �� ����. --> �޸� ���� �ȵ�.
*/

shared_ptr<int> ptr01(new int(5));
cout << ptr01.use_count() << endl; //1
auto ptr02(ptr01);  //���� �����ڸ� �̿��� �ʱ�ȭ
cout << ptr01.use_count() << endl; //2
auto ptr03 = ptr01; //������ ���� �ʱ�ȭ
cout << ptr01.use_count() << endl; //3

shared_ptr<Person> p1 = make_shared<Person>("�浿", 29);
cout << "���� ������ �� : " << p1.use_count() << endl; // 1
auto p2 = p1; // ���� �����ڸ� �̿��� �ʱ�ȭ
cout << "���� ������ �� : " << p1.use_count() << endl; // 2
p2.reset(); // shared_ptr�� p2�� ������.
cout << "���� ������ �� : " << p1.use_count() << endl; // 1

/*
	weak_prt : �ϳ� �̻��� shared_ptr ��ü�� �����ϴ� ��ü�� ���� ������ ����������,
			   �������� ������ ���Ե��� �ʴ� ����Ʈ ������.
			   ��ü�� ���������� ���ÿ� �ش� ��ü�� Ȱ�� ���·� ���� ���� �������� ��� ���ȴ�.
			   shared_ptr���� ���ΰ� ������ �����ϰ� �ִ� ��Ȳ�� ��ȯ ����(circular reference)��� �ϴµ�,
			   ��ȯ ������ �����ϱ� ���� ���ȴ�. 
*/
shared_ptr<int> sp1(new int(10));
weak_ptr<int> wp1 = sp1;

cout << sp1.use_count() << endl; //1 
cout << wp1.use_count() << endl; //1
{
	shared_ptr<int> sp2 = wp1.lock(); //weak_ptr�� lock �żҵ尡 ���൵�� shared_ptr ��ü�� ����.

	cout << sp1.use_count() << endl; //2
	cout << wp1.use_count() << endl; //2, ���� �����Ϳ��� 3���� ����Ʈ �����Ͱ� ����Ŵ
} //�̶� sp2 ��ü�� �Ҹ� �Ǹ� sp2 ��ü�� �Ҹ�(�����Ͱ� ������°� �ƴϴ�!!)