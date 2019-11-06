//Initial Template for C++
#include <iostream>
using namespace std;
//Position this line where user code will be pasted.
void reverse_dig(int &a, int &b);
void swap(int &a, int &b);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;

		reverse_dig(a, b);
		swap(a, b);
		cout << a << " " << b << endl;
	}
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
void reverse_dig(int &a, int &b)
{
	//int tmp_a = 0;
	//while (a != 0) {
	//	if (a % 10 != 0) { //test_case error -> 51096 , a%10으로 판단하면 안된다. 
	//		tmp_a *= 10;//처음에 곱하고 
	//		tmp_a += a % 10;//더한다. 
	//		a = a / 10;
	//	}
	//	else {
	//		a = a / 10;
	//	}
	//}
	//int tmp_b = 0;
	//while (b != 0) {
	//	if (b % 10 != 0) {
	//		tmp_b *= 10;
	//		tmp_b += b % 10;
	//		b = b / 10;
	//	}
	//	else {
	//		b = b / 10;
	//	}
	//}
	//a = tmp_a; b = tmp_b;//Add your code here.
	
	int tmp_a = 0, tmp_b = 0;
	while (a > 0 || b > 0) { //a,b 중 하나라도 살아 있다면.
		if (a > 0) {
			tmp_a = tmp_a * 10 + a % 10;
			a /= 10;
		}
		if (b > 0) {
			tmp_b = tmp_b * 10 + b % 10;
			b /= 10;
		}
	}
	a = tmp_a; b = tmp_b;
}
void swap(int &a, int &b)
{
	//Add your code here.
	int tmp = a;
	a = b;
	b = tmp;
}