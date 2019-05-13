#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum)
		:bullet(bnum)
	{}
	void Shot() {
		cout << "BBang"<<endl;
		bullet--;
	}
	int getBnum() {
		return bullet;
	}
};

class Police {
private:
	int handcuffs;
	Gun *pistol;
public:
	Police(int bnum, int bcuff)//(1)기본 생성자
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(const Police &copy)//(3)깊은 복사를 위한 복사 생성자 정의 
		: handcuffs(copy.handcuffs)
	{
		if (copy.pistol != NULL)
			//pistol = new Gun(copy.pistol->getBnum());//pman1의 Gun객체의 Bnum수 만큼 새로운 공간을 할당
			pistol = new Gun(*(copy.pistol));//copy의 pistol이 가리키는 것(Gun 객체)와 같은 크기의 공간을 할당
		else
			pistol = NULL;//copy의 공간이 없으면 복사되는 객체의 포인터도 공간할당이 없다(!!)
	}

	Police& operator=(const Police &ref)//(6)대입 연산자의 오버로딩
	{ 
		if (pistol != NULL)
			delete pistol;

		if (ref.pistol != NULL) {
			//pistol = new Gun(ref.pistol->getBnum());
			pistol = new Gun(*(ref.pistol));
		}
		else {
			pistol = NULL;
		}
		handcuffs = ref.handcuffs;
		return *this;
	}

	void PutHancuff() {
		cout << "SNAP" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG" << endl;
		else
			pistol->Shot();
			//bullet--;
	}
	void Show() {
		cout << "Bnum: " << pistol->getBnum() << "Handcuffs: " << handcuffs << endl;
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
		cout << "Destructer!" << endl;
	 }
};

int main() {
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHancuff();
	pman1.Show();

	//Police pman2 = pman1;//(2)얕은 복사가 일어난다.
	//pman2.Shot();
	//pman2.PutHancuff();
	//pman2.Show(); //(4,2)

	//pman1.Show(); //(4,3) (2)얕은 복사가 일어난다. // (5,3) (4)깊은 복사가 일어난다. 

	Police pman3(9, 8);
	pman3 = pman1;

	pman3.Show();
	pman1.Show();

	return 0; //(5) pman3의 객체가 소멸하면서 pman1의 객체도 같이 소멸되어 버린다. 
}