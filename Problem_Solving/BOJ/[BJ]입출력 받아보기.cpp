/*
getline(cin,s): ���� �� �Է� �ޱ�, s�� Ÿ���� string
endl: �ٹٲ� ��� + ��Ʈ�� flush ���. �ǵ����̸� '\n'�� ����. 
cin, cout�� printf, scanf���ٴ� ��������, main�Լ� ������ ios_base::sync_with_stdio(false):�� ���ָ� �� ��������. ��, cin,cout�� printf,scanf ���� �� �� ����.

auto: �����Ϸ��� Ÿ���� �߷��ؼ� Ÿ���� �����Ѵ�. ������ Ÿ���� ��Ȯ�ϰ� �� �� �־�� �Ѵ�. 
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

	// ���� �Ѽ�: �͸��Լ�
	cout << [](int x, int y) {
		return x + y
	};

		auto f = [&x, y]() {
			x += 10;
		}
	return 0;
}
