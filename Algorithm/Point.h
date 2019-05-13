#ifndef POINT_H
#define POINT_H
class Point {
private: 
	int x;
	int y;
public:
	//bool InitMembers(int xpos, int ypos);
	Point(const int &xpos, const int &ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif
