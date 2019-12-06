/* 명품 c++ 5.7문제 */
#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};

Accumulator::Accumulator(int myvalue)
	:value(myvalue)
{ }

Accumulator& Accumulator::add(int n)
{
	value += n;
	return *this;
}

int Accumulator::get()
{
	return value;
}


int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}