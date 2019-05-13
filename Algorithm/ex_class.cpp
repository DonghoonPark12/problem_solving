#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
class Calculator {
private:
	double a;//³»ºÎ º¯¼ö ¸¸µé ÇÊ¿ä ¾ø´Ù. 
	double b;
	int cnt_Add = 0;
	int cnt_Div = 0;
	int cnt_Min = 0;
	int cnt_Mul = 0;
public:
	void ShowOpCount();
	void Init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
};
int main() {
	Calculator cal;
	cal.Init();
	cout << "3.2+2.4= " << cal.Add(3.2,2.4) << endl;
	cout << "3.5/1.7= " << cal.Div(3.5,1.7) << endl;
	cout << "2.2-1.5= " << cal.Min(2.2,1.5) << endl;
	cout << "4.9/1.3= " << cal.Div(4.9,1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

void Calculator::ShowOpCount(){
	cout << "µ¡¼À: " << cnt_Add << " »¬¼À: " << cnt_Min << " °ö¼À: " << cnt_Mul << " ³ª´°¼À: " << cnt_Div << endl;
}

void Calculator::Init()
{
	cnt_Add = 0;
	cnt_Div = 0;
	cnt_Min = 0;
	cnt_Mul = 0;
}

double Calculator::Add(double a, double b)
{
	cnt_Add++;
	return a+b;
}

double Calculator::Div(double a, double b)
{
	cnt_Div++;
	return a/b;
}

double Calculator::Min(double a, double b)
{
	cnt_Min++;
	return a-b;
}

double Calculator::Mul(double a, double b)
{
	cnt_Mul++;
	return a*b;
}
*/
class Printer {
private:
	char str2[30];
	string str; //String Å¬·¡½º
public:
	void SetString2(char *s);
	void SetString(string str);
	void ShowString();
};
int main() {
	Printer pnt;
	pnt.SetString2("Hello worlds!");
	pnt.ShowString();

	pnt.SetString2("I love C++");
	pnt.ShowString();
	return 0;
}

void Printer::SetString2(char * s)
{
	strcpy(str2, s);
}

void Printer::SetString(string str_)
{
	//string::iterator end_pos = remove(str.begin(), str.end(), ' ');
	//str.erase(end_pos, str.end());
	//str.erase(remove(str.begin(), str.end(), ' '), str.end());
	//getline(cin, str); Å°º¸µå ÀÔ·Â

	//1)
	str.erase();
	str = str_;

	//2)

}


void Printer::ShowString()
{
	cout << str2 << endl;
}
