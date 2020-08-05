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
