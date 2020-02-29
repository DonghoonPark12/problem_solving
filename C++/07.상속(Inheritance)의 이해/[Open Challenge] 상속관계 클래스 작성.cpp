#include <iostream>
#include <string>
using namespace std;

enum productType {
	_BOOK = 1,
	_MUSICCD,
	_CONVBOOK
};

class Product {
private:
	int id, Price;
	string ProdInfo, Producer;
public:
	Product(int _id, string _ProdInfo, string _Producer, int _Price)
		:id(_id), ProdInfo(_ProdInfo), Producer(_Producer), Price(_Price)
	{}
	virtual void ShowInfo() {
		cout << "--- ��ǰID : " << id << '\n';
		cout << "��ǰ���� : " << ProdInfo << '\n';
		cout << "������ : " << Producer << '\n';
		cout << "���� : " << Price << '\n';
	}
};

class Book : public Product {
private:
	string Title, Author, ISBN;
public:
	Book(int _id, string _ProdInfo, string _Producer, int _Price, string _Title, string _Author, string _ISBN)
		: Product(_id, _ProdInfo, _Producer, _Price), Title(_Title), Author(_Author), ISBN(_ISBN)
	{}
	void ShowInfo() {
		Product::ShowInfo();
		cout << "ISBN : " << ISBN << '\n';
		cout << "å���� : " << Title << '\n';
		cout << "���� : " << Author << '\n';
	}
};

class ConversationBook : public Book {
private:
	string Laguage;
public:
	ConversationBook(int _id, string _ProdInfo, string _Producer, int _Price, string _Title, string _Author, string _ISBN, string _Laguage)
		: Book(_id, _ProdInfo, _Producer, _Price, _Title, _Author, _ISBN), Laguage(_Laguage)
	{}
	void ShowInfo() {
		Book::ShowInfo();
		cout << "��� : " << Laguage <<'\n';
	}
};

class CompactDisc : public Product {
private:
	string Title, Singer;
public:
	CompactDisc(int _id, string _ProdInfo, string _Producer, int _Price, string _Title, string _Singer)
		: Product(_id, _ProdInfo, _Producer, _Price), Title(_Title), Singer(_Singer)
	{}
	void ShowInfo() {
		Product::ShowInfo();
		cout << "�ٹ����� : " << Title << '\n';
		cout << "�����̸� : " << Singer << '\n';
	}
};

class ProductHandler {
private:
	Product* ProdList[100];
	int ProdNum;
public:
	ProductHandler()
		: ProdNum(0)
	{}

	void ShowMenu() {
		int sel, sel2;
		cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << '\n';
		while (1) {
			cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? "; cin >> sel;
			if (sel == 1) {
				cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ? "; cin >> sel2; cin.ignore();
				if (sel2 == _BOOK) {
					int id = this->ProdNum;
					cout << "��ǰ����>>"; string ProdInfo;   getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "������>>";   string Producer;   getline(cin, Producer); //tmp.Producer = str;
					cout << "����>>";     int Price;         cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "å����>>";   string Title;    getline(cin, Title);
					cout << "����>>";     string Author;   getline(cin, Author);     //tmp.author = str;
					cout << "ISBN>>";     string ISBN;     getline(cin, ISBN);       //tmp.ISBN = str;
					this->AddProduct(new Book(id, ProdInfo, Producer, Price, Title, Author, ISBN));
				}
				else if (sel2 == _MUSICCD) {
					int id = this->ProdNum;
					cout << "��ǰ����>>"; string ProdInfo; getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "������>>";   string Producer; getline(cin, Producer); //tmp.Producer = str;
					cout << "����>>";     int Price;       cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "�ٹ�����>>"; string Title;    getline(cin, Title);    //tmp.Title = str;
					cout << "����>>";     string Singer;   getline(cin, Singer);   //tmp.Singer = str;
					this->AddProduct(new CompactDisc(id, ProdInfo, Producer, Price, Title, Singer));
				}
				else if (sel2 == _CONVBOOK) {
					//ConversationBook tmp;
					int id = this->ProdNum;
					cout << "��ǰ����>>"; string ProdInfo; getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "������>>";   string Producer; getline(cin, Producer); //tmp.Producer = str;
					cout << "����>>";     int Price;       cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "å����>>";   string Title;    getline(cin, Title);
					cout << "����>>";     string Author;   getline(cin, Author);     //tmp.author = str;
					cout << "���>>";     string Lauguage; getline(cin, Lauguage);   //tmp.language = str;
					cout << "ISBN>>";     string ISBN;     getline(cin, ISBN);       //tmp.ISBN = str;
					this->AddProduct(new ConversationBook(id, ProdInfo, Producer, Price, Title, Author, ISBN, Lauguage));
				}
				else {
					cout << "Wrong Select !!" << '\n';
					continue;
				}
			}
			else if (sel == 2) {
				this->ShowAllProdInfo();
			}
			else if(sel == 3){
				//delete[]ProdList; 
				/*
					���ʿ� ProdList[]�� ���� �������� �ʾҴµ� �� �޸𸮸� �����Ϸ� �Ͽ����� ���� ����.
					���� ���� ������ ���� ��ü���̴�. 
					��ü �迭�� Stack�� ����Ǿ� �ְ� �����ͷ� (�� ������ ��ġ��) ������ ��ü���� ����Ű�� �ִ�.

					Q. ��ü �迭�� ���� �����ϰ�, ��ü �迭�� ��� ��ü �鵵 new�� �ؼ� ���� �����ϴ� ���� �����ұ�?

					Q. Ȥ�� �ݴ�� ��ü �迭�� ���� �����ϰ�, ��ü �迭�� new�� ���� �ʰ� �Ǹ� �迭 ���ҵ��� ���ÿ� ����Ǵ� ���ϱ�?
				*/
				for (int i = 0; i < ProdNum; i++) {
					delete ProdList[i];
				}
				break;
			}
			else {
				cout << "Wrong Select !!" << '\n';
			}
			cout << '\n';
		}
	}
	
	void AddProduct(Product* prod) {
		ProdList[ProdNum++] = prod;
	}

	void ShowAllProdInfo() const {
		for (int i = 0; i < ProdNum; i++) {
			ProdList[i]->ShowInfo();
			cout << '\n';
		}
	}
};
int main() {
	ProductHandler ph;

	ph.ShowMenu();

	return 0;
}