#include <iostream>
using namespace std;

class Data {
private: 
	int data;
public:
	Data(int num)
		:data(num)
	{}
	void ShowData() { cout << "Data: " << data << '\n'; }
	void Add(int num) { data += num; }
};

typedef struct Data {
	int data;
	void(*ShowData)(Data *); //함수 포인터의 인자로 구조체 포인터를 받고 있다. 
	void(*Add) (Data *, int);
}Data;

void ShowData(Data *THIS) { cout << "Data: " << THIS->data << '\n'; }
void Add(Data *THIS, int num) { THIS->data += num; }


int main() {
	//Data obj(15);
	//obj.Add(17);
	//obj.ShowData();

	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };
	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);

	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}