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

void Converter::run() {
	double src;
	cout << getSourceString() << "�� " << getDestString() << " �� �ٲߴϴ�. ";
	cout << getSourceString() << "�� �Է��ϼ���>> ";
	cin >> src;
	cout << "��ȯ ��� : " << convert(src) << getDestString() << '\n';
}


class KmToMile : public Converter {
private:
	string Source = "Km";
	string Dest = "Mile";
public:
	KmToMile(double r)
		:Converter(r)
	{}
	string getSourceString();
	string getDestString();
	double convert(double km);
};
string KmToMile::getSourceString() { return Source;}
string KmToMile::getDestString() { return Dest; }

double KmToMile::convert(double km) {
	//cout << Converter::ratio << '\n';
	return km / Converter::ratio;
}


int main() {
	KmToMile toMile(1.609344);
	toMile.run(); //�Ļ� Ŭ�������� �⺻ Ŭ������ ����� �Լ� ȣ��
	return 0;
}

