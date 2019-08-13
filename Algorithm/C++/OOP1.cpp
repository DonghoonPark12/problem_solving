#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
/*
1. 계좌 계설 할 때 마다 구조체가 새로 생성되어야 한다. 
2. 구조체를 리스트 형태로 줄줄이 이으려고 한다. 

취약점
- 아이디가 중복 될때 예외처리 안되있다.
- 목록에 없는 기능을 입력시 예외처리 안되있다. ex)5
- 입, 출금시 아이디 없는 곳에 접근시 예외처리 안되있다. 
*/
typedef struct _account {
	int id;
	//string name;
	char name[10];
	int won;
	struct _account *next;
	int rate;
	int credit;
}account;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

void init() { //객체도 없는데 뭘 초기화 하겠다는 거야?
	

}

int main() {
	account *head = NULL;
	account *tail = NULL;
	//account *person = head;
	init();
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	while (1) {
		cout << "\n------Menu-----" << "\n" <<
			"1.계좌 계설" << "\n" 
			<< "2.입금" << "\n"
			<< "3.출급" << "\n" 
			<< "4. 계좌정보 전체 출력" << "\n"
			<< "5. 프로그램 종료" << "\n" << endl;

		cout << "선택: ";
		int n; cin >> n;
		//select(n);

		int id;
		int won;
		if (n == 1) {
			//char name[10];
			//account tmp;
			//string name;
			cout << "\n[계좌종류선택]" << endl;
			cout << "선택: ";
			int n2; cin >> n2;
			if (n2 == 1) {
				char name[10];
				account *ptr = new account; //구조체 동적 할당
				cout << "\n[보통예금계좌 계설]" << endl;
				cout << "계좌 ID:"; cin >> ptr->id;
				cout << "이름:"; //getline(cin, name);
				scanf("%s", name);	strcpy(ptr->name, name); //새로운 구조체를 생성하여 이름을 넣고, head(구조체 포인터)로 연결하려고 하는데..
				cout << "입금액: "; cin >> ptr->won;
				cout << "이자율: "; cin >> ptr->rate;
				if (head == NULL) {
					//*head = person; 이렇게 하니까 안됬다. 
					head = ptr; //구조체 포인터가 구조체를 가리키게 하는데 왜 안될까..?
					tail = head;
					tail->next = NULL;
				}
				else {
					tail->next = ptr;
					tail = tail->next;
					tail->next = NULL;
				}
			}
			else if (n2 == 2) {
				char name[10];
				account *ptr = new account; //구조체 동적 할당
				cout << "\n[신용신뢰계좌 계설]" << endl;
				cout << "계좌 ID:"; cin >> ptr->id;
				cout << "이름:"; //getline(cin, name);
				scanf("%s", name);	strcpy(ptr->name, name); //새로운 구조체를 생성하여 이름을 넣고, head(구조체 포인터)로 연결하려고 하는데..
				cout << "입금액:"; cin >> ptr->won;
				cout << "이자율: "; cin >> ptr->rate;
				cout << "신용등급: "; cin >> ptr->credit;
				if (head == NULL) {
					//*head = person; 이렇게 하니까 안됬다. 
					head = ptr; //구조체 포인터가 구조체를 가리키게 하는데 왜 안될까..?
					tail = head;
					tail->next = NULL;
				}
				else {
					tail->next = ptr;
					tail = tail->next;
					tail->next = NULL;
				}
			}
			else
			{ }
		}
		else if (n == 2) {
			cout << "\n[입   금]" << endl;
			cout << "계좌 ID:"; cin >> id;
			cout << "입금액:"; cin >> won;
			account *search = head;
			//while (search->next != NULL) {
			while(1){
				if (search->id == id) {
					search->won += won;
					break;
				}
				else
					search = search->next;
			}
			cout << "입금 완료!\n";
		}
		else if (n == 3) {
			cout << "\n[출   금]" << endl;
			cout << "계좌 ID:"; cin >> id;
			cout << "출금액:"; cin >> won;
			account *search = head;
			//while (search->next != NULL) {
			while(1){
				if (search->id == id) {
					search->won -= won;
					break;
				}
				else
					search = search->next;
			}
			cout << "출금 완료!\n";
		}
		else if (n==4){
			cout << "----------------" << endl;
			cout << "[전체 계좌 정보]"<<endl ;
			account *search = head;
			while (1) {
				cout << "계좌 ID:"<<search->id << endl;
				cout << "이름:" << search->name << endl;
				cout << "잔액:" << search->won << endl<<endl;
				if (search->next == NULL) break;
				search = search->next;
			}
			cout << "----------------" << endl;
		}
		else {

		}
	}
	return 0;
}

