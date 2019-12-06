#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run();
};

class WonToDollar : public Converter {
private:
	string Source = "��";
	string Dest = "�޷�";
public:
	WonToDollar(int r)
		:Converter(r)
	{}
	virtual string getSourceString();
	virtual string getDestString();
	virtual double convert(double won);
};
string WonToDollar::getSourceString() {
	return Source;
}
string WonToDollar::getDestString() {
	return Dest;
}
double WonToDollar::convert(double won) {
	return won / Converter::ratio;
}

void Converter::run() {
	double src;
	cout << getSourceString() << "�� " << getDestString() << " �� �ٲߴϴ�. ";
	cout << getSourceString() << "�� �Է��ϼ���>> ";
	cin >> src;
	cout << "��ȯ ��� : " << convert(src) << getDestString() << '\n';
}

int main() {
	WonToDollar wd(1010);
	wd.run(); //�����Ǵ� ��� �Լ� ȣ��
	return 0;
}