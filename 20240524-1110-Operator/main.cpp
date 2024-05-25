#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
	int _x, _y;

public:
	Point(int x, int y)
		: _x(x), _y() {}

	int GetX() {
		return _x;
	}

	int GetY() {
		return _y;
	}

	void Info() {
		cout << "x: " << _x << ", y:" << _y << endl;
	}
};

class Line {
private:
	Point _pt1, _pt2;

public:
	Line(int pt1x, int pt1y, int pt2x, int pt2y)
		: _pt1(pt1x, pt1y), _pt2(pt2x, pt2y) {}

	Line(Point pt1, Point pt2)
		: _pt1(pt1), _pt2(pt2) {}

	float GetLength() {
		int xBase = _pt2.GetX() - _pt1.GetX();
		int height = _pt1.GetY() - _pt2.GetY();

		return sqrt(pow(xBase, 2) + pow(height, 2));
	}
};

// 삼각형 클래스 (정삼각형, 직삼각형)
// 사각형 클래스 (정사각형, 직각사각형)
// 원 클래스

// 각각의 도형클래스를 만들고 면적을 출력하세요..



int main() {
	Line line(0, 0, 4, 4);
	cout << "line length = " << line.GetLength() << endl;

	return 0;
}