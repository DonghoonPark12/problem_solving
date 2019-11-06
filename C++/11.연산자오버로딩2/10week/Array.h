#ifndef  ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;
/*
	�� ���� ������ ����� ����(&)�� �����;� �ϴ� ���� ��
	: �׷��� �ʰ� ������ ���޵Ǿ� ����, �Ű����� ��ü�� �����Ǹ�
	  �Ű����� ��ü ������ ���ؼ� ���� �����ڰ� �ٽ� ȣ��Ǹ�(!!)

	  ���� �����ڰ� ȣ��� �� �Ű����� ��ü�� �� �ٽ� �����Ǿ� ���� �ݺ�.

	  �̴� ����(&)�� �ƴ� '���� ���� ��ü ȣ��'�� ��, ���� �����ڰ� ȣ��Ǵ� ���� �����̴�. 
*/
class Array {
private:
	int size;
	int* ptr;
public:
	Array(int = 10);
	Array(const Array&); //�ں��� ������, �ݵ�� ����(&)�� �����;� �Ѵ�. ����, const ��ü�� ������ �� �ֵ���(?) const �������� �Ѵ�(?).
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
