#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class PermanentWorker {
private:
	char name[100];
	int salary;
public:
	PermanentWorker(char *name, int money)
		:salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const	{
		cout << "name: " << name << endl;
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler{
private:
	PermanentWorker *empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(PermanentWorker*emp){
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
	}

	~EmployeeHandler(){
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler; // 컨트롤 클래스의 객체 생성

	//정규직 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번달에 지급해야 할 급여 정보
	handler.ShowAllSalaryInfo();

	// 이번달에 지분해야 할 급여의 총 합
	handler.ShowTotalSalary();
	return 0;
}