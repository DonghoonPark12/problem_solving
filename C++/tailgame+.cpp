#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:                          //<���̽��� self�� c++�� this>
	void set_name(string name) { //��ü�� ����Լ��� ȣ��� �� �����Ϸ��� ��ü�� �ּҸ� ����Լ��� ������(?)���� �����ϸ�
		this->name = name;       //this�� �����Ϸ��� ���� �� �ּҸ� �޵��� ���� ���Ե� �Ű������� �̸��̴�. 
	}                            //Ŭ������ non-static ����Լ������� ����� �����ϴ� (�����̸� ��� �Ұ�).

								 //���̽��� self�� ��ü�� ��ü�� �ּҸ� �޴°Ű�, �̰� c++�� this���Ұ� ����.
								 //���̽㿡�� self�� �־ �ɹ��Լ� �ȿ��� �ɸ� ������ ������ �����ߴ�.          
	string get_name(){ return name; }
};

class WordGame {
	int num_player;
	string compare;
	string input;
public:
	WordGame()
		:compare("�ƹ���")
	{};
	~WordGame() { delete[]p; } //�޸� ��ȯ -> ���α׷� ���� :������ ���α׷� ����Ǹ� �ڵ� �޸� ��ȯ������...
                               // ������ p�� ���������, p�� ����Ű�� ���� �����ϸ� �ȵ�.
							   // �Ҹ��ڴ� ��ü�� ����� �� �ʿ��� ������ �۾��� �ϱ� �����̴�.
							   // ex) �Ҵ���� Heap �޸𸮸� �ü������ ������, ������� ������ �����ϰ� ����. ��Ʈ��ũ ����.
	Player *p; //��ü ������ ����
	void playgame();
};

void WordGame::playgame() {
	cout << "���� �ձ� ������ �����մϴ�" << endl;
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	cin >> num_player;          //<�ֿ� ����>
	p = new Player[num_player]; //��ü �����Ϳ� ��ü �迭 �Ҵ�, �⺻ ������ ȣ��ȴ�. (�Ű����� �ִ� ������ ȣ���� �� ����).
	                            //new�����ڴ� Heap�̶�� �ý��� ����(?, �޸� ����)���� ���� �޸� �Ҵ� �޴´�.
	string name;
	for (int i = 0; i < num_player; i++) {
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
		cin >> name; p[i].set_name(name);
	}

	cout << "\n�����ϴ� �ܾ�� �ƹ��� �Դϴ�" << endl;

	int st = 0; //���� �÷��̾ �ݺ��ϰ� �ϴ� ����
	int size = 0; //���� ���� �ܾ��� ���̸� �ľ��� ���� �� ����Ʈ ��ġ�� ã�� ���� ����
	while (1) {
		cout << p[st].get_name() << ">> ";
		cin >> input; 
		
		size = compare.size();
		if ((compare.at(size-2) != input.at(0)) || (compare.at(size-1) != input.at(1))) { break; }
		compare = input; 
		st = (st + 1) % num_player;
	}
	cout << p[st].get_name() << "�� �����ϴ�.";
}

int main() {
	WordGame wg;
	wg.playgame();
	return 0;
}

