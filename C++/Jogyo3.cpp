#include <iostream>
#include <string>
using namespace std;

class employee {
private:
	string firstname;
	string lastname;
	int monthlysalary;
public:
	employee(int a) {
		cout << a << "번째이름과 성을 입력하시오\n" << endl;
		cin >> firstname;
		cin >> lastname;
		cout << "월급을 입력하시오\n" << endl;
		cin >> monthlysalary;
		if (monthlysalary <= 0) {
			monthlysalary = 0;
			cout << "월급을 잘못입력하셨습니다" << endl;
		}
	#include <iostream>
#include <string>
using namespace std;

class employee {
private:
 string firstname;
 string lastname;
 int monthlysalary;
public:
 employee(int a){
  cout <<a<< "번째이름과 성을 입력하시오\n" << endl;
  cin >> firstname;
  cin >> lastname;
  cout << "월급을 입력하시오\n" << endl;
  cin >> monthlysalary;
  if (monthlysalary <= 0) {
   monthlysalary = 0;
   cout << "월급을 잘못입력하셨습니다" << endl;
  }
 }
 void setfirstname(string f) {
  firstname = f;
 }
 string getfirstname() {
  return firstname;
 }
 void setlastname(string l) {
  lastname = l;
 }
 string getlastname() {
  return lastname;
 }
 void setmonthlysalary(int s) {
  monthlysalary = s;
 }
 int getmonthlysalary() {
  return monthlysalary;
 }
};

int main() {
 employee lisaroberts(1);
 employee markstein(2);

 cout << "employee`s yearly salaries: " << endl;
 cout << lisaroberts.getfirstname()
  << lisaroberts.getlastname()<<": "
  << lisaroberts.getmonthlysalary()*12 << endl;
 cout << markstein.getfirstname()
  << markstein.getlastname()<<": "
  << markstein.getmonthlysalary()*12 << endl;

 cout << "employee`s yearly salaries after 10% raise: " << endl;
 cout << lisaroberts.getfirstname()
  << lisaroberts.getlastname() << ": "
  << lisaroberts.setmonthlysalary(lisaroberts.getmonthlysalary()*1.1)  << endl;
 cout << markstein.getfirstname()
  << markstein.getlastname() << ": "
  << markstein.getmonthlysalary() * 12 << endl;

 return 0;
} 

​
}
	void setfirstname(string f) {
		firstname = f;
	}
	string getfirstname() {
		return firstname;
	}
	void setlastname(string l) {
		lastname = l;
	}
	string getlastname() {
		return lastname;
	}
	void setmonthlysalary(int s) {
		monthlysalary = s;
	}
	int getmonthlysalary() {
		return monthlysalary;
	}
};

int main() {
	employee lisaroberts(1);
	employee markstein(2);

	cout << "employee`s yearly salaries: " << endl;
	cout << lisaroberts.getfirstname()
		<< lisaroberts.getlastname() << ": "
		<< lisaroberts.getmonthlysalary() * 12 << endl;
	cout << markstein.getfirstname()
		<< markstein.getlastname() << ": "
		<< markstein.getmonthlysalary() * 12 << endl;

	cout << "employee`s yearly salaries after 10% raise: " << endl;
	cout << lisaroberts.getfirstname()
		<< lisaroberts.getlastname() << ": "
		<< lisaroberts.setmonthlysalary(lisaroberts.getmonthlysalary()*1.1) << endl;
	cout << markstein.getfirstname()
		<< markstein.getlastname() << ": "
		<< markstein.getmonthlysalary() * 12 << endl;

	return 0;
}

​
