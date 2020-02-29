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
		cout << "--- 상품ID : " << id << '\n';
		cout << "상품설명 : " << ProdInfo << '\n';
		cout << "생산자 : " << Producer << '\n';
		cout << "가격 : " << Price << '\n';
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
		cout << "책제목 : " << Title << '\n';
		cout << "저자 : " << Author << '\n';
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
		cout << "언어 : " << Laguage <<'\n';
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
		cout << "앨범제목 : " << Title << '\n';
		cout << "가수이름 : " << Singer << '\n';
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
		cout << "***** 상품 관리 프로그램을 작동합니다 *****" << '\n';
		while (1) {
			cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? "; cin >> sel;
			if (sel == 1) {
				cout << "상품 종류 책(1), 음반CD(2), 회화책(3) ? "; cin >> sel2; cin.ignore();
				if (sel2 == _BOOK) {
					int id = this->ProdNum;
					cout << "상품설명>>"; string ProdInfo;   getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "생산자>>";   string Producer;   getline(cin, Producer); //tmp.Producer = str;
					cout << "가격>>";     int Price;         cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "책제목>>";   string Title;    getline(cin, Title);
					cout << "저자>>";     string Author;   getline(cin, Author);     //tmp.author = str;
					cout << "ISBN>>";     string ISBN;     getline(cin, ISBN);       //tmp.ISBN = str;
					this->AddProduct(new Book(id, ProdInfo, Producer, Price, Title, Author, ISBN));
				}
				else if (sel2 == _MUSICCD) {
					int id = this->ProdNum;
					cout << "상품설명>>"; string ProdInfo; getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "생산자>>";   string Producer; getline(cin, Producer); //tmp.Producer = str;
					cout << "가격>>";     int Price;       cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "앨범제목>>"; string Title;    getline(cin, Title);    //tmp.Title = str;
					cout << "가수>>";     string Singer;   getline(cin, Singer);   //tmp.Singer = str;
					this->AddProduct(new CompactDisc(id, ProdInfo, Producer, Price, Title, Singer));
				}
				else if (sel2 == _CONVBOOK) {
					//ConversationBook tmp;
					int id = this->ProdNum;
					cout << "상품설명>>"; string ProdInfo; getline(cin, ProdInfo); //tmp.ProdInfo = str;
					cout << "생산자>>";   string Producer; getline(cin, Producer); //tmp.Producer = str;
					cout << "가격>>";     int Price;       cin >> Price; cin.ignore(); //tmp.Price = price;

					cout << "책제목>>";   string Title;    getline(cin, Title);
					cout << "저자>>";     string Author;   getline(cin, Author);     //tmp.author = str;
					cout << "언어>>";     string Lauguage; getline(cin, Lauguage);   //tmp.language = str;
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
					애초에 ProdList[]를 힙에 선언하지 않았는데 힙 메모리를 해재하려 하였으니 에러 났다.
					내가 힙에 선언한 것은 객체들이다. 
					객체 배열은 Stack에 저장되어 있고 포인터로 (힙 영역에 위치한) 각각의 객체들을 가리키고 있다.

					Q. 객체 배열도 힙에 선언하고, 객체 배열에 담긴 객체 들도 new로 해서 힙에 저장하는 것이 가능할까?

					Q. 혹은 반대로 객체 배열은 힙에 선언하고, 객체 배열은 new로 담지 않게 되면 배열 원소들은 스택에 저장되는 것일까?
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