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
	string Source = "원";
	string Dest = "달러";
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
	cout << getSourceString() << "을 " << getDestString() << " 로 바꿉니다. ";
	cout << getSourceString() << "을 입력하세요>> ";
	cin >> src;
	cout << "변환 결과 : " << convert(src) << getDestString() << '\n';
}

int main() {
	WonToDollar wd(1010);
	wd.run(); //공유되는 멤버 함수 호출
	return 0;
}