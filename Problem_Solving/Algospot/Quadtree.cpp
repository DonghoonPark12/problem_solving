#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int tc; 
	string img;
	cin >> tc; 
	if (tc < 0 || tc > 50)
		exit(-1);
	for (int t = 0; t < tc; t++) {
		cin >> img;
		if (img.size() > 1000)
			exit(-1);
		string::iterator it = img.begin();
		cout << reverse(it) << '\n';
	}
	return 0;
}