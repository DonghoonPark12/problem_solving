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
	cout << getSourceString() << "을 " << getDestString() << " 로 바꿉니다. ";
	cout << getSourceString() << "을 입력하세요>> ";
	cin >> src;
	cout << "변환 결과 : " << convert(src) << getDestString() << '\n';
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
	toMile.run(); //파생 클래스에서 기본 클래스에 선언된 함수 호출
	return 0;
}

