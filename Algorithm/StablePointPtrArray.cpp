#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{}
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos) {
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}

typedef Point *POINT_PTR;

class BoundCheckPointPtrArray
{
private:
	POINT_PTR *arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {};//복사를 막는다. 
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) {}//대입을 막는다. 
public:
	BoundCheckPointPtrArray(int len)
		: arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[](int idx) const { //18행 함수와 오버로딩 관계, 어짜피 수정이 불가능 하기 때문에 참조형으로 반환하지 않는다. 
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointPtrArray() { delete[]arr; }
};

int main() {
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		//cout << *(arr[i]);//연산자 오버로딩 함수 호출
		cout << arr[i];//연산자 오버로딩 함수 호출
	}

	for (int i = 0; i < arr.GetArrLen(); i++) {
		delete arr[i];//연산자 오버로딩 함수 호출
	}
	
	return 0;
}
