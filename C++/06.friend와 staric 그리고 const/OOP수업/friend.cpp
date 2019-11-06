#include <iostream>
using namespace std;

class Count {
private:
	int x;

public:
	Count()
		:x(0)
	{};
	void print() const {
		cout << this->x << endl;
		cout << this << endl;
	}

	friend void setX(Count &, int);
};

void setX(Count &c, int val) {
	c.x = val;
}

int main() {
	Count counter;  //0x7777;
	Count counter2; //0x8888;

	//cout << "counter.x after instantiation: ";
	counter.print();  //this->x
	counter2.print(); //this->x 

	setX(counter, 8);
	cout << "counter.x after call to setX friend function: ";
	counter.print();
	return 0;
}