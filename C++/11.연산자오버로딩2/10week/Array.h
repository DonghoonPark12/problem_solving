#ifndef  ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;
/*
	★ 복사 생성자 선언시 참조(&)를 가져와야 하는 이유 ★
	: 그렇지 않고 값으로 전달되어 지면, 매개변수 객체가 생성되며
	  매개변수 객체 생성을 위해서 복사 생성자가 다시 호출되며(!!)

	  복사 생성자가 호출될 때 매개변수 객체가 또 다시 생성되어 무한 반복.

	  이는 참조(&)가 아닌 '값에 의한 객체 호출'일 때, 복사 생성자가 호출되는 요인 때문이다. 
*/
class Array {
private:
	int size;
	int* ptr;
public:
	Array(int = 10);
	Array(const Array&); //★복사 생성자, 반드시 참조(&)를 가져와야 한다. 또한, const 객체를 복사할 수 있도록(?) const 참조여야 한다(?).
	~Array();
	int getsize() const;

	const Array& operator=(const Array&); //assignment operator
	bool operator==(const Array&) const; //quality operator
	
	bool operator!=(const Array& right) const {
		return !(*this == right);
	}

	int& operator[](int);
	int operator[](int) const;

	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);
};

#endif // ! ARRAY_H
