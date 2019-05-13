/*
getline(cin,s): 한줄 다 입력 받기, s의 타입은 string
endl: 줄바꿈 출력 + 스트림 flush 기능. 되도록이면 '\n'을 쓴다. 
cin, cout은 printf, scanf보다는 느리지만, main함수 다음에 ios_base::sync_with_stdio(false):를 써주면 더 빨라진다. 단, cin,cout과 printf,scanf 섞어 쓸 수 없다.

auto: 컴파일러가 타입을 추론해서 타입을 결정한다. 변수의 타입을 명확하게 알 수 있어야 한다. 
*/
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	double f = 3.14159265358979;
	cout << setprecision(5) << f << '\n';
	cout << setprecision(8) << f << '\n';
	cout << setprecision(10) << f << '\n';

	cout << fixed << setprecision(5) << f << '\n';
	cout << fixed << setprecision(8) << f << '\n';
	cout << fixed << setprecision(10) << f << '\n';

	auto a = 0, b = 0;
	cin >> a >> b;

	vector<int> a = { 1, 2, 3, 4, 5 };

	for (auto &p : a)
	{
		cout << p.first + p.second << ' ';
	}
	cout << '\n';

	for (auto x : { 1, 2, 3, 4 })
	{
		sum += x;
	}
	cout << "sum = " << sum << '\n';

	// 람다 한수: 익명함수
	cout << [](int x, int y) {
		return x + y
	};

		auto f = [&x, y]() {
			x += 10;
		}
	return 0;
}
