#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
/*
	STL ���� - https://baactree.tistory.com/29

*/
typedef pair<int, string> pis;

void print(set<int> &s, set<int>::iterator it) {
	if (it == s.end()) {
		cout << "end\n";
	}
	else {
		cout << *it << '\n';
	}
}

int main() {
	/*---------------------------- vector --------------------------*/
	
	vector<pis> v;

	v.push_back(pis(3, "Dok2"));
	v.push_back(pis(6, "DMask"));
	v.push_back(pis(1, "Tiger JK"));
	v.push_back(pis(2, "Banana"));
	v.push_back(pis(2, "Apple"));

	cout << "===== Before Sort =====" << endl;

	vector<pis>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << "[" << iter->first << "," << iter->second << "]" << endl;
	}
	cout << endl;

	sort(v.begin(), v.end());
	cout << "===== After Sort =====" << endl;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << "[" << iter->first << "," << iter->second << "]" << endl;
	}

	// vec7�� vec1�� �� ���� ���Һ��� ������ ���ұ��� �����Ͽ� ����.
	vector<int> vec7 = vector<int>(vec1.begin() + 2, vec1.end());


	//vector<int> v1;
	//vector<int> v2(10); //int v2[10];
	//vector<int> v3(15, 1); //���̰� 15, �ʱⰪ 1
	//vector<int> v4 = { 1, 2, 3, 4, 5 };

	//vector<pair<int, int>> v5;
	//vector<pair<int, int>> v6 = { {1, 2}, {3, 4} };
	//vector<vector<int>> v7;

	//int n = 10, m = 20;
	//vector<vector<int>> v8(n, vector<int>(m)); // int v8[n][m]

	//vector<int> a = { 1, 2, 3, 4, 5 };

	//a.push_back(6);
	//a.push_back(7);
	//a.pop_back();
	//a.pop_back();
	//a.pop_back();

	//a.clear(); //[ ]

	//a.resize(5); //[0, 0, 0, 0, 0]

	//a.clear(); //[ ]

	//a.push_back(1);
	//a.push_back(2); //[1, 2]
	//a.resize(5); //[1, 2, 0, 0, 0]
	//a.resize(3); //[1, 2, 0]

	//vector<int> a = { 1, 2, 3, 4 };
	//cout << "size = " << a.size() << '\n'; //4

	//a.push_back(5);
	//cout << "size = " << a.size() << '\n'; //5
	//cout << "empty = " << a.empty() << '\n'; //0

	//a.clear();
	//cout << "size = " << a.size() << '\n'; //0
	//cout << "empty = " << a.empty() << '\n'; //1

	//vector<int> a = { 1, 2, 3 };
	//cout << "front = " << a.front() << '\n'; //1
	//cout << "a[1] = " << a[1] << '\n'; //2
	//cout << "back = " << a.back() << '\n'; //3

	//a.push_back(4);

	//for (int i = 0; i<a.size(); i++) {
	//	cout << a[i] << ' ';
	//}
	//cout << '\n'; //1 2 3 4

	//for (int &x : a) {
	//	cout << x << ' ';
	//}
	//cout << '\n'; //1 2 3 4

	//for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
	//	cout << *it << ' ';
	//}

	//for (auto it = a.begin(); it != a.end(); ++it) {
	//	cout << "a[" << (it - a.begin()) << "]= " << *it << '\n';
	//}
	/*---------------------------------------------------------------*/

	/*------------------------------ pair ----------------------------*/
	pair<int, int> p1;
	cout << p1.first << ' ' << p1.second << '\n';

	p1 = make_pair(10, 20);
	cout << p1.first << ' ' << p1.second << '\n';

	p1 = pair<int, int>(30, 40);
	cout << p1.first << ' ' << p1.second << '\n';

	pair<int, int> p2(50, 60);
	cout << p2.first << ' ' << p2.second << '\n';

	pair<pair<int, int>, pair<int, int>> p = make_pair(make_pair(10, 20), make_pair(30, 40)); //pair�� ���Ҹ� pair�� �� ��� 

	cout << p.first.first << ' ' << p.first.second << '\n';
	cout << p.second.first << ' ' << p.second.second << '\n';

	/*---------------------------------------------------------------*/

	tuple<int, int, int> t1 = make_tuple(1, 2, 3);
	cout << get<0>(t1) << ' ';//get< > ���̿� ������ ���� �� ����. 
	cout << get<1>(t1) << ' ';
	cout << get<2>(t1) << '\n';

	auto t = make_tuple(10, 20, 30);

	int x = get<0>(t);
	int y = get<1>(t);
	int z = get<2>(t);

	cout << x << ' ' << y << ' ' << z << '\n';

	x = y = z = 0;
	tie(x, y, z) = t;

	cout << x << ' ' << y << ' ' << z << '\n';

	//int a, b;
	//tie(a, b, ignore) = make_tuple(10, 20, 30);

	//cout << a << ' ' << b << '\n';



	//set<int> s;
	//s.insert(1); s.insert(3); s.insert(2);

	//cout << "s.size() = " << s.size() << '\n'; //3

	//pair<set<int>::iterator, bool> result = s.insert(4);
	//cout << "result iterator = " << *result.first << '\n'; //4
	//cout << "result bool = " << result.second << '\n'; //1

	//auto result2 = s.insert(3);
	//cout << "result2 iterator = " << *result2.first << '\n'; //3
	//cout << "result2 bool = " << result2.second << '\n'; //0

	//set<int> s = { 1,2,3,4,5 };
	//s.erase(s.begin());
	//cout << "s.size() = " << s.size() << '\n'; //4

	//auto it = s.begin();
	//++it;
	//cout << "*it = " << *it << '\n'; //3
	//it = s.erase(it);
	//cout << "*it = " << *it << '\n'; //4
	//cout << "s.size() = " << s.size() << '\n'; //3

	//set<int> s = { 5,2,4,1,3,7,6 }; //�������� �ڵ� ���� �ȴ�.
	//for (auto it = s.begin(); it != s.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << '\n';

	//for (auto x : s) {
	//	cout << x << ' ';
	//}
	//cout << '\n';

	//set<int> s = { 7, 5, 3, 1 }; //1 3 5 7
	//auto it = s.find(1); // it�� set<int>::iterator
	//print(s, it); //������ 1

	//it = s.find(2);
	//print(s, it); // ������ end

	//it = s.find(3);
	//print(s, it);

	//it = s.find(4);
	//print(s, it);

	//set<int> s = { 7, 1, 5, 3 };

	//for (int i = 1; i <= 9; i++) {
	//	cout << "s.count(" << i << ") =" << s.count(i) << '\n';
	//}

	//map<int, int> d1;
	//map<int, int> d2 = { { 1,2 },{ 3,4 },{ 5,6 } };

	//cout << "d1.size() = " << d1.size() << '\n'; //0
	//cout << "d2.size() = " << d2.size() << '\n'; //3


	//d1[10] = 20;
	//cout << "d1[10] = " << d1[10] << '\n'; //20
	//cout << "d2[1] = " << d2[1] << '\n'; //2
	//cout << "d2[2] = " << d2[2] << '\n'; //0 ��??
	//cout << "d2[3] = " << d2[3] << '\n'; //4
	//cout << "d2[4] = " << d2[4] << '\n'; //0
	//cout << "d2[5] = " << d2[5] << '\n'; //6

	//map<int, int> d1;
	//map<int, int> d2;

	//for (int i = 1; i <= 9; i += 2) {
	//	d1[i] = i*i;
	//	d2[i] = i*i;
	//}

	//cout << "d1.size() = " << d1.size() << '\n';
	//cout << "d2.size() = " << d2.size() << '\n';

	//for (int i = 1; i <= 10; i++) {
	//	if (d1[i]) { //�� ����� �þ�� ����..?
	//		cout << i << ' ';
	//	}
	//}

	//cout << '\n';
	//for (int i = 1; i<10; i++) {
	//	if (d2.count(i)) { //d2[i]�� ���� ��
	//		cout << i << ' ';
	//	}
	//}

	//cout << '\n';
	//cout << "d1.size() = " << d1.size() << '\n'; //10 
	//cout << "d2.size() = " << d2.size() << '\n'; //5 

	//map<int, int> d = { { 1,2 },{ 3,4 },{ 5,6 } };

	//for (auto it = d.begin(); it != d.end(); ++it) {
	//	cout << (it->first) << ' ' << (it->second) << '\n';
	//}

	//for (auto p : d) { //p�� ��??
	//	cout << p.first << ' ' << p.second << '\n';
	//}

	/*------------------------------ set ----------------------------*/
	// ���� ���� ���� Ʈ���̴�.
	// ���� ����, ����, Ž�� �� ������ O(logn)�� �����Ѵ�. 
	set<int> s;
	pair<set<int>::iterator, bool> pr;
	pr = s.insert(50);
	s.insert(40);
	s.insert(80);

	if (true == pr.second)
		cout << *pr.first << "Success!" << endl;
	else
		cout << *pr.first << "Failure!" << endl;
	return 0;
	/*---------------------------------------------------------------*/

	/*------------------------------ map ----------------------------*/
	// int �ڷ����� key�� int �ڷ����� �����ͷ� �����ϴ� ��ųʸ� �ڷᱸ�� ����
	map<int, int> m;
	m.insert(make_pair(4, 5));
	m[5] = 6;

	//key�� ������ ���Ҹ� pair<key �ڷ���, data �ڷ���> ���·� ������
	printf("%d\n", m.find(4)->second);
	
	// key�� ������ ������ ������ ������.
	printf("%d\n", m.count(4));

	//�ش� �ּ��� ���� ����
	m.erase(++m.begin());
	//��� ���� ����
	m.clear();

	/*---------------------------------------------------------------*/
}