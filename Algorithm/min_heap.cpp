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
	// greater-than operator > �� �����մϴ�. �� operator�� min-heap�� ������ �� ���Դϴ�. 
	// class ��ſ� struct�� ���� �͵� �����մϴ�.
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
		rect t = pq.top(); //t�� ��ü
		pq.pop();

		t.print();  // print (1,2), (1,5), (8,2), (7,6) 
	}
}