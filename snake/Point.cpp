
#include "Point.h"

Point::Point(size_t x, size_t y)
{
	mX = x;
	mY = y;
}

// get
size_t Point::x()
{
	return mX;
}

size_t Point::y()
{
	return mY;
}

// set
void Point::setX(size_t x)
{
	mX = x;
}

void Point::setY(size_t y)
{
	mY = y;
}


