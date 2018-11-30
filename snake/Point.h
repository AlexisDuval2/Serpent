
#ifndef POINT_H
#define POINT_H

class Point
{
private:
	size_t mX;
	size_t mY;

public:
	Point(size_t x, size_t y);

	// get
	size_t x();
	size_t y();

	// set
	void setX(size_t x);
	void setY(size_t y);
};

#endif //POINT_H

