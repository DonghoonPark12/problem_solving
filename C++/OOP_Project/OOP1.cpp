#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
/*
1. ���� �輳 �� �� ���� ����ü�� ���� �����Ǿ�� �Ѵ�. 
2. ����ü�� ����Ʈ ���·� ������ �������� �Ѵ�. 

�����
- ���̵� �ߺ� �ɶ� ����ó�� �ȵ��ִ�.
- ��Ͽ� ���� ����� �Է½� ����ó�� �ȵ��ִ�. ex)5
- ��, ��ݽ� ���̵� ���� ���� ���ٽ� ����ó�� �ȵ��ִ�. 
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

void init() { //��ü�� ���µ� �� �ʱ�ȭ �ϰڴٴ� �ž�?
	

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
			"1.���� �輳" << "\n" 
			<< "2.�Ա�" << "\n"
			<< "3.���" << "\n" 
			<< "4. �������� ��ü ���" << "\n"
			<< "5. ���α׷� ����" << "\n" << endl;

		cout << "����: ";
		int n; cin >> n;
		//select(n);

		int id;
		int won;
		if (n == 1) {
			//char name[10];
			//account tmp;
			//string name;
			cout << "\n[������������]" << endl;
			cout << "����: ";
			int n2; cin >> n2;
			if (n2 == 1) {
				char name[10];
				account *ptr = new account; //����ü ���� �Ҵ�
				cout << "\n[���뿹�ݰ��� �輳]" << endl;
				cout << "���� ID:"; cin >> ptr->id;
				cout << "�̸�:"; //getline(cin, name);
				scanf("%s", name);	strcpy(ptr->name, name); //���ο� ����ü�� �����Ͽ� �̸��� �ְ�, head(����ü ������)�� �����Ϸ��� �ϴµ�..
				cout << "�Աݾ�: "; cin >> ptr->won;
				cout << "������: "; cin >> ptr->rate;
				if (head == NULL) {
					//*head = person; �̷��� �ϴϱ� �ȉ��. 
					head = ptr; //����ü �����Ͱ� ����ü�� ����Ű�� �ϴµ� �� �ȵɱ�..?
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
				account *ptr = new account; //����ü ���� �Ҵ�
				cout << "\n[�ſ�ŷڰ��� �輳]" << endl;
				cout << "���� ID:"; cin >> ptr->id;
				cout << "�̸�:"; //getline(cin, name);
				scanf("%s", name);	strcpy(ptr->name, name); //���ο� ����ü�� �����Ͽ� �̸��� �ְ�, head(����ü ������)�� �����Ϸ��� �ϴµ�..
				cout << "�Աݾ�:"; cin >> ptr->won;
				cout << "������: "; cin >> ptr->rate;
				cout << "�ſ���: "; cin >> ptr->credit;
				if (head == NULL) {
					//*head = person; �̷��� �ϴϱ� �ȉ��. 
					head = ptr; //����ü �����Ͱ� ����ü�� ����Ű�� �ϴµ� �� �ȵɱ�..?
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
			cout << "\n[��   ��]" << endl;
			cout << "���� ID:"; cin >> id;
			cout << "�Աݾ�:"; cin >> won;
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
			cout << "�Ա� �Ϸ�!\n";
		}
		else if (n == 3) {
			cout << "\n[��   ��]" << endl;
			cout << "���� ID:"; cin >> id;
			cout << "��ݾ�:"; cin >> won;
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
			cout << "��� �Ϸ�!\n";
		}
		else if (n==4){
			cout << "----------------" << endl;
			cout << "[��ü ���� ����]"<<endl ;
			account *search = head;
			while (1) {
				cout << "���� ID:"<<search->id << endl;
				cout << "�̸�:" << search->name << endl;
				cout << "�ܾ�:" << search->won << endl<<endl;
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

