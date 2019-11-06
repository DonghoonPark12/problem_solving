#include <iostream>
#include <string>
#include <cstdlib>
/*
	https://blockdmask.tistory.com/338
*/
using namespace std;
class Morse {
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string &morse);
	bool morse2Text(string morse, string& text);
};

Morse::Morse() {
	alphabet[0]=".-"; alphabet[1]="-..."; alphabet[2]="-.-."; alphabet[3]="-.."; alphabet[4]="."; alphabet[5]="..-."; alphabet[6]="--."; alphabet[7]="...."; alphabet[8]=".."; alphabet[9]=".---";
	alphabet[10]= "-.-"; alphabet[11]= ".-.."; alphabet[12]= "--"; alphabet[13]= "-."; alphabet[14]= "---"; alphabet[15]= ".--."; alphabet[16]= "--.-"; alphabet[17]=".-."; alphabet[18]="..."; alphabet[19]="-"; 
	alphabet[20] = "..-"; alphabet[21] = "...-"; alphabet[22]=".--"; alphabet[23]= "-..-"; alphabet[24]= "-.--"; alphabet[25] = "--..";
	
	digit[0] = "-----"; digit[1] = ".----"; digit[2] = "..---"; digit[3] = "...--"; digit[4] = "....-"; digit[5] = "....."; digit[6] = "-...."; digit[7] = "--..."; digit[8] = "----.."; digit[9] = "----." ;
	
	/*
	string alphamorse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	string digitmorse[10] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
	for (int i = 0; i<26; i++) alphabet[i] = alphamorse[i];
	for (int i = 0; i<10; i++) digit[i] = digitmorse[i];
	*/

	slash = "-..-.";
	question = "..--..";
	comma = "--..--";
	period = ".-.-.-";
	plus = ".-.-.";
	equal = "-...-";
}
void Morse::text2Morse(string text, string &morse) {
	int i = 0; char c;
	while (text[i] != '\n') {
		c = text[i];
		if (c >= 'A' && c <= 'Z') c = tolower(c);

		if (c >= 'a' && c <= 'z') morse += alphabet[c - 'a']; 
		else if (c >= '0' && c <= '9') morse += digit[c - '0'];
		else if (c == '/') morse += slash;
		else if (c == '?') morse += question;
		else if (c == ',') morse += comma;
		else if (c == '.') morse += period;
		else if (c == '+') morse += plus;
		else if (c == '=') morse += equal;
		else
			morse += "  ";
		morse += " ";
		i++;
	}
}
bool Morse::morse2Text(string morse, string &text) {
	string alpah[26] = { "a","b","c","d","e","f", "g","h","i", "j","k","l", "m","n","o", "p","q","r", "s","t","u", "v","w","x", "y","z" };
	string di[10] = { "0","1","2", "3","4","5", "6","7","8", "9" };
	string text2 = "";
	for (int j = 0; j < morse.size(); ) {
		int pos = morse.find(" ", j); //��ĭ�� ã�´�. morse���� ��ġ�ϴ°� �ִٸ� ù��° ����(first occurrence of the sequence)(index)��ȯ. 
		bool flag = false;            //j�� ��� ��ġ ���� ã������ ����(at or after position j).
		string s = morse.substr(j, pos - j); //�� ��ȣ ����
		for (int i = 0; i < 26; ++i) {
			if (s == alphabet[i]) { //string Ŭ���� operator== �� ������ �����ε� �Ǿ� ����.
				text2.append(alpah[i]);
				flag = true;
				break;
			}
		}
		if (!flag) {
			for (int i = 0; i < 10; ++i) {
				if (s == digit[i]) {
					text2.append(di[i]);
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			if (s == slash) text2 += "/";
			else if (s == question) text2 += "?";
			else if (s == comma) text2 += ",";
			else if (s == period) text2 += ".";
			else if (s == plus) text2 += "+";
			else if (s == equal) text2 += "=";
		}
		if (morse[pos] == ' ' && morse[pos + 1] == ' ' && morse[pos + 2] == ' ') { //morse ��ȣ�� "   "�� ���� ���
			text2 += " ";
			pos += 2;
		}
		j = pos + 1;//j�� " "�� ã�� ��ġ �ٷ� ���� ��ġ ���� ����
	}
	if (text2 + '\n' == text) return true; //string Ŭ������ ==������ �����ε� �Ǿ� ����.
	else return false;
	
}

int main() {
	string str, mrs, str2;
	cout << "�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� �ٲߴϴ�.\n";
	getline(cin, str);
	str += '\n';
	Morse m;
	m.text2Morse(str, mrs);
	cout << mrs << '\n';
	cout << "�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� �ٲߴϴ�.\n";
	if(m.morse2Text(mrs, str)) cout << str <<'\n';
	else cout << "Error!" << '\n';
	
	return 0;
}
