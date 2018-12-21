#ifndef ECOCO_DE_FIGHT_POINT_H
#define ECOCO_DE_FIGHT_POINT_H

namespace EcocoDeFightBase{
	struct Point{
		int x;
		int y;
		Point operator +(const Point& another)const;
		Point operator -()const;
		Point operator -(const Point& offset)const;
		Point& operator +=(const Point& offset);
		Point& operator -=(const Point& offset);
		Point(int x = 0, int y = 0) :x(x), y(y){}
		//return x*x + y*y
		unsigned int AbsSquare()const;
		static unsigned int DistanceSquare(const Point&, const Point&);
	};
};

#endif