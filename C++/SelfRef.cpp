#include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int n)
		:num(n)
	{
		cout << "°´Ã¼ »ý¼º" << endl;
	}
	SelfRef &Adder(int n) {
		num += n;
		return *this;
	}
	SelfRef ShowTowNumber() {
		cout << num << endl;
		return *this;
	}
};

int main() {
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowTowNumber();
	ref.ShowTowNumber();
	ref.Adder(1).Adder(2).ShowTowNumber().ShowTowNumber();

	return 0;
}