#include "stdafx.h"

#include "Point.h"

namespace EcocoDeFightBase{
	Point Point::operator+(const Point& point)const{
		return Point(point.x + this->x, point.y + this->y);
	}
	Point Point::operator-()const{
		return Point(-(this->x), -(this->y));
	}
	Point Point::operator-(const Point& offset)const{
		return Point(this->x - offset.x, this->y - offset.y);
	}

	Point& Point::operator +=(const Point& offset){ this->x += offset.x; this->y += offset.y; return *this; }

	Point& Point::operator -=(const Point& offset){ this->x -= offset.x; this->y -= offset.y; return *this; }

	unsigned int Point::AbsSquare()const{ return (unsigned int)(x*x) + (unsigned int)(y*y); }

	unsigned int Point::DistanceSquare(const Point& a, const Point& b){ return (a - b).AbsSquare(); }
}