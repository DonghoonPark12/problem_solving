#include <iostream>
using namespace std;

class Point2 {
private:
	int xpos, ypos;
public:
	Point2(int x, int y)
		:xpos(x), ypos(y)
	{
		//xpos = x;
		//ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
