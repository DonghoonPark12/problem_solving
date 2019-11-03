#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Employee {
/* �߻� Ŭ����: �ϳ� �̻��� ��� �Լ��� ���� �����Լ��� ������ Ŭ���� */
private:
	char name[100];
public:
	Employee(char *name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0; //���� �����Լ�, �� ���� �޿� 

	virtual void ShowSalaryInfo() const = 0; //���� �����Լ�
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(char *name, int money)
		:salary(money), Employee(name)
	{
		//strcpy(this->name, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const	{
		//cout << "name: " << name << endl;
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime; //�̴޿� ���� �ð��� �հ�
	int payPerHour; //�ð��� �޿�
public:
	TemporaryWorker(char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int Time) { //���� �ð��� �߰�
		workTime += Time;
	}
	int GetPay() const { //�� ���� �޿�
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout<< "Salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult; //�� �Ǹ� ����
	double bonusRatio; //�󿩱� ����
public:
	SalesWorker(char *name, int money, double ratio)
		:PermanentWorker(name, money),salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		// PremanentWorker�� Getpay() �Լ� ȣ��
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	//PermanentWorker::ShowSalaryInfo();
	void ShowSalaryInfo() const{
		ShowYourName();
		cout<< "Salary: " << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL {
	enum { RISK_A = 30, RISK_B = 20, RISK_C = 10 };
}

class ForeignSalesWorker : public SalesWorker {
private:
	//enum RISK_LEVEL;
	const int riskLevel;
public:
	ForeignSalesWorker(char *name, int money, double ratio, int risky)
		: SalesWorker(name, money, ratio), riskLevel(risky)
	{}
	
	int RiskPay() const {
		return (int)(SalesWorker::GetPay() * riskLevel/100.0);
	}

	int GetPay() const {
		return SalesWorker::GetPay() + RiskPay();
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "Risk Pay: " << RiskPay() << endl;
		cout << "Sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	//PermanentWorker *empList[50];
	Employee *empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee *emp)
	{
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
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler; // ��Ʈ�� Ŭ������ ��ü ����

	//������ ���
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//�ӽ��� ���
	TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba); //Employee Ŭ������ ��� ���� ���̱� ������ Employee ��ü �迭�� ������ �����ϴ�.

	//������ ���
	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); //�������� 7000
	handler.AddEmployee(seller); //Employee Ŭ������ ��� ���� ���̱� ������ Employee ��ü �迭�� ������ �����ϴ�.

	//���� ������ ���
	ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// �̹��޿� �����ؾ� �� �޿� ����
	handler.ShowAllSalaryInfo();

	// �̹��޿� �����ؾ� �� �޿��� �� ��
	handler.ShowTotalSalary();
	return 0;
}