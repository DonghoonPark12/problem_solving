#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:                          //<파이썬의 self와 c++의 this>
	void set_name(string name) { //객체의 멤버함수가 호출될 때 컴파일러는 객체의 주소를 멤버함수에 묵시적(?)으로 전달하며
		this->name = name;       //this는 컴파일러에 의해 이 주소를 받도록 몰래 삽입된 매개변수의 이름이다. 
	}                            //클래스의 non-static 멤버함수에서만 사용이 가능하다 (정적이면 사용 불가).

								 //파이썬의 self가 객체가 객체의 주소를 받는거고, 이게 c++의 this역할과 동일.
								 //파이썬에서 self가 있어서 맴버함수 안에서 맴머 변수에 접근이 가능했다.          
	string get_name(){ return name; }
};

class WordGame {
	int num_player;
	string compare;
	string input;
public:
	WordGame()
		:compare("아버지")
	{};
	~WordGame() { delete[]p; } //메모리 반환 -> 프로그램 종료 :어차피 프로그램 종료되면 자동 메모리 반환이지만...
                               // 포인터 p는 사라있지만, p가 가리키는 곳에 접근하면 안됨.
							   // 소멸자는 객체가 사라질 때 필요한 마무리 작업을 하기 위함이다.
							   // ex) 할당받은 Heap 메모리를 운영체제에게 돌려줌, 열어놓은 파일을 저장하고 닫음. 네트워크 해제.
	Player *p; //객체 포인터 선언
	void playgame();
};

void WordGame::playgame() {
	cout << "끝말 잇기 게임을 시작합니다" << endl;
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	cin >> num_player;          //<주요 개념>
	p = new Player[num_player]; //객체 포인터에 객체 배열 할당, 기본 생성자 호출된다. (매개변수 있는 생성자 호출할 수 없다).
	                            //new연산자는 Heap이라는 시스템 공간(?, 메모리 영역)으로 부터 메모리 할당 받는다.
	string name;
	for (int i = 0; i < num_player; i++) {
		cout << "참가자의 이름을 입력하세요. 반칸없이>>";
		cin >> name; p[i].set_name(name);
	}

	cout << "\n시작하는 단어는 아버지 입니다" << endl;

	int st = 0; //게임 플레이어를 반복하게 하는 변수
	int size = 0; //비교할 왼쪽 단어의 길이를 파악해 끝의 두 바이트 위치를 찾기 위한 변수
	while (1) {
		cout << p[st].get_name() << ">> ";
		cin >> input; 
		
		size = compare.size();
		if ((compare.at(size-2) != input.at(0)) || (compare.at(size-1) != input.at(1))) { break; }
		compare = input; 
		st = (st + 1) % num_player;
	}
	cout << p[st].get_name() << "이 졌습니다.";
}

int main() {
	WordGame wg;
	wg.playgame();
	return 0;
}

