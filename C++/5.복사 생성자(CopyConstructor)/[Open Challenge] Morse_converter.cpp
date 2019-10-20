#include <iostream>
#include <string>
using namespace std;
class Morse {
	string alphabet[26];
	string digit[10];
	string slash, question, comman, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string &morse);
	bool morse2Text(string morse, string& text);
};

Morse::Morse() {
	alphabet[0] = ".-";

	alphabet[31] = "-...-";
	digit[0] = "-----";

	digit[9] = "----.";
	slash = "-..-.";

	equal = "-...-";
}
void Morse::text2Morse(string text, string &morse) {
	cout << text << '\n';
	int i = 0;
	while (text[i] != '\n') {
		cout << int(text[i]) - int('A');

		i++;
	}
}
bool Morse::morse2Text(string morse, string &text) {

}

int main() {
	string str, mrs, str2;
	cout << "�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� �ٲߴϴ�.\n";
	getline(cin, str);
	
	Morse m;
	m.text2Morse(str, mrs);
	cout << mrs << '\n';
	cout << "�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� �ٲߴϴ�.\n";
	m.morse2Text(mrs, str2);
	cout << str2<<'\n';
	
	return 0;
}
