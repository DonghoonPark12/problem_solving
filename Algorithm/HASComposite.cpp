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
	Police(int bnum, int bcuff)//(1)�⺻ ������
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(const Police &copy)//(3)���� ���縦 ���� ���� ������ ���� 
		: handcuffs(copy.handcuffs)
	{
		if (copy.pistol != NULL)
			//pistol = new Gun(copy.pistol->getBnum());//pman1�� Gun��ü�� Bnum�� ��ŭ ���ο� ������ �Ҵ�
			pistol = new Gun(*(copy.pistol));//copy�� pistol�� ����Ű�� ��(Gun ��ü)�� ���� ũ���� ������ �Ҵ�
		else
			pistol = NULL;//copy�� ������ ������ ����Ǵ� ��ü�� �����͵� �����Ҵ��� ����(!!)
	}

	Police& operator=(const Police &ref)//(6)���� �������� �����ε�
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

	//Police pman2 = pman1;//(2)���� ���簡 �Ͼ��.
	//pman2.Shot();
	//pman2.PutHancuff();
	//pman2.Show(); //(4,2)

	//pman1.Show(); //(4,3) (2)���� ���簡 �Ͼ��. // (5,3) (4)���� ���簡 �Ͼ��. 

	Police pman3(9, 8);
	pman3 = pman1;

	pman3.Show();
	pman1.Show();

	return 0; //(5) pman3�� ��ü�� �Ҹ��ϸ鼭 pman1�� ��ü�� ���� �Ҹ�Ǿ� ������. 
}