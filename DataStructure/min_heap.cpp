#include <iostream>
#include <functional>
#include <queue>
using namespace std;

class rect {
public:
	rect(int w, int h) : _w(w), _h(h) {}

	void print() {
		cout << "rect:" << _w << "*" << _h << "=" << _w * _h << endl;
	}
	// greater-than operator > 를 정의합니다. 이 operator는 min-heap을 정의할 때 쓰입니다. 
	// class 대신에 struct를 쓰는 것도 가능합니다.
	//
	bool operator > (const rect& rhs) const {
		return _w * _h < rhs._w * rhs._h;
	}

private:
	int _w, _h;
};

int main()
{
	priority_queue<rect, vector<rect>, greater<rect> > pq;
	pq.push(rect(1, 5));
	pq.push(rect(7, 6));
	pq.push(rect(1, 2));
	pq.push(rect(8, 2));

	while (!pq.empty()) {
		rect t = pq.top(); //t는 객체
		pq.pop();

		t.print();  // print (1,2), (1,5), (8,2), (7,6) 
	}
}