<<<<<<< HEAD
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
////enum roma
////{
////	I = 1,
////	V = 5,
////	X = 10,
////	L = 50,
////	C = 100,
////	D = 500,
////	M = 1000
////};
//map<char, int> roma;
//
//string ArabiaToRoma(int n)
//{
//	string res2;
//	//int pos = 0;
//	int m, cm, d, cd, c, xc, l, xl, x, ix, v, iv, i;
//	int pos = 0;
//	if (n > 1000)
//	{
//		m = n / 1000;
//		n -= m * 1000;
//		res2.insert(res2.end(), m, 'M');
//		pos += m;
//	}
//
//	if (n / 900 == 1)  //연속해서 사용할 수 없으므로, 몫이 1이어야 한다.
//	{
//		n -= 900;
//		res2.insert(pos, "CM");
//		pos += 2;
//	}
//
//	if (n / 500 == 1)  //한번만 사용할 수 있으므로, 몫이 1이어야 한다.
//	{
//		n -= 500;
//		res2.insert(pos, 1, 'D');
//		pos += 1;
//	}
//
//	if (n / 400 == 1) //연속해서 사용할 수 없으므로, 몫이 1이어야 한다.s
//	{
//		n -= 400;
//		res2.insert(pos, "CD");
//		pos += 2;
//	}
//
//	if (n > 100)
//	{
//		c = n / 100;
//		n -= c * 100;
//		res2.insert(pos, c, 'C');
//		pos += c;
//	}
//
//	if (n / 90 == 1)
//	{
//		n -= 90;
//		res2.insert(pos,"XC");
//		pos += 2;
//	}
//	if (n / 50 == 1)
//	{
//		n -= 50;
//		res2.insert(pos, 1, 'L');
//		pos += 1;
//	}
//	if (n / 40 == 1)
//	{
//		n -= 40;
//		res2.insert(pos, "XL");
//		pos += 2;
//	}
//
//	if (n > 10)
//	{
//		x = n / 100;
//		n -= x * 100;
//		res2.insert(pos, x, 'X');
//		pos += x;
//	}
//
//	if (n / 9 == 1)
//	{
//		n -= 9;
//		res2.insert(pos, "IX");
//		pos += 2;
//	}
//	if (n / 5 == 1)
//	{
//		n -= 5;
//		res2.insert(pos, 1, 'V');
//		pos += 1;
//	}
//	if (n / 4 == 1)
//	{
//		n -= 4;
//		res2.insert(pos, "IV");
//		pos += 2;
//	}
//
//	while (n--) {
//		res2.insert(pos, 1, 'I');
//		pos += 1;
//	}
//
//	return res2;
//}
//
//int main()
//{
//	string rn1, rn2;
//	int an1 = 0, an2 = 0;
//	int res1 = 0;
//	string res2;
//
//	getline(cin, rn1);
//	getline(cin, rn2);
//
//	roma.insert({ 'I',1 });
//	roma['V'] = 5;
//	roma.insert({ 'X', 10 });
//	roma['L'] = 50;
//	roma.insert({ 'C', 100 });
//	roma['D'] = 500;
//	roma.insert({ 'M', 1000 });
//
//	char c1, c2;
//	for (int i = 0; i < rn1.size(); i++)
//	{
//		if (roma[rn1[i]] < roma[rn1[i + 1]])
//		{
//			an1 += roma[rn1[i + 1]] - roma[rn1[i]];  // 이렇게 할 필요 없이, 작은 값이 왼쪽에 온 경우 빼주면 된다. 그러면 이후 큰 값이 올때 더해주면
//			i++;                                     // 그말이 그말이다.
//		}
//		else
//		{
//			an1 += roma[rn1[i]];
//		}
//	}
//
//	for (int i = 0; i < rn2.size(); i++)             // 두번 돌리지 말고, 2줄 for문 한다 ^^;;
//	{
//		if (roma[rn2[i]] < roma[rn2[i + 1]])
//		{
//			an2 += roma[rn2[i + 1]] - roma[rn2[i]];
//			i++;
//		}
//		else
//		{
//			an2 += roma[rn2[i]];
//		}
//	}
//	res1 = an1 + an2;
//
//	res2 = ArabiaToRoma(res1);
//	cout << res1 << '\n' << res2;
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int hash[91]; //A~Z : 65~90
	hash['I'] = 1;
	hash['V'] = 5;
	hash['X'] = 10;
	hash['L'] = 50;
	hash['C'] = 100;
	hash['D'] = 500;
	hash['M'] = 1000;

	int res = 0;
	for (int i = 0; i < 2; i++) {
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j + 1] != NULL && hash[s[j]] < hash[s[j + 1]])
				res += -hash[s[j]];
			else
				res += hash[s[j]];
		}
	}
	cout << res << endl;

	string minus9xx[3] = { "IX", "XC", "CM" }; // 9, 90, 900
	string minus4xx[3] = { "IV", "XL", "CD" }; // 4, 40, 400
	char hash1xx[4] = { 'I', 'X', 'C', 'M' };  // 1, 10, 100, 1000
	char hash5xx[3] = { 'V', 'L', 'D' };       // 5, 50, 500

	for (int i = 1000, j = 3; i; i /= 10, j--) {
		if (res / i == 9) 
			cout << minus9xx[j];

		else if (res / i >= 5) {
			cout << hash5xx[j]; // V, L, D는 한 번만 사용할 수 있다.
			
			for (int k = 5; k < res / i; k++) {
				cout << hash1xx[j]; //따라서, 조건을 통과한다면, 남은 것은 hash1xx로 채워준다.
			}
		}
		else if (res / i == 4) 
			cout << minus4xx[j];

		else {
			for (int k = 0; k < res / i; k++) {
				cout << hash1xx[j];
			}
		}
		res %= i; //최상위 위치 기수 제거
	}

	return 0;
}
=======
#include <iostream>
#include <string>
#include <map>
using namespace std;
//enum roma
//{
//	I = 1,
//	V = 5,
//	X = 10,
//	L = 50,
//	C = 100,
//	D = 500,
//	M = 1000
//};
map<char, int> roma;

string ArabiaToRoma(int n)
{
	string res2;
	if (n > 1000)
	{
		int mok = n / 1000;
		n -= mok * 1000;
		
	}

}

int main()
{
	string rn1, rn2;
	int an1 = 0, an2 = 0;
	int res = 0;
	string res2;

	getline(cin, rn1);
	getline(cin, rn2);

	roma.insert({'I',1});
	roma['V'] = 5;
	roma.insert({ 'X', 10 });
	roma['L'] = 50;
	roma.insert({ 'C', 100 });
	roma['D'] = 500;
	roma.insert({ 'M', 1000 });

	char c1, c2;
	for (int i = 0; i < rn1.size(); i++)
	{
		if (roma[rn1[i]] < roma[rn1[i + 1]] )
		{
			an1 += roma[rn1[i + 1]] - roma[rn1[i]];
			i++;
		}
		else
		{
			an1 += roma[rn1[i]];
		}
	}

	for (int i = 0; i < rn2.size(); i++)
	{
		if (roma[rn2[i]] < roma[rn2[i + 1]])
		{
			an2 += roma[rn2[i + 1]] - roma[rn2[i]];
			i++;
		}
		else
		{
			an2 += roma[rn2[i]];
		}
	}
	res = an1 + an2;

	res2 = ArabiaToRoma(res);
	cout << res;
	return 0;
}
>>>>>>> 2dcfaec8b6e3382cc121875f17c0a9b99ceee482
