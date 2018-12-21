#include "stdafx.h"
#include "MovableCharact.h"

namespace EcocoDeFightBase{

	//Initialize
	void MovableCharact::Initialize(Point pt, BlockDirectionCheck func, MovableCharactData data){
		checkFunctions = func;
		cdata = data;
		place = pt;
	}

	//move around
	bool MovableCharact::MoveLeft(unsigned int distance){
		for (unsigned int i = 0; i < distance; ++i){
			if (IsLeftTouched())return false;
			--place.x;
		}
		return true;
	}
	bool MovableCharact::MoveRight(unsigned int distance){
		for (unsigned int i = 0; i < distance; ++i){
			if (IsRightTouched())return false;
			++place.x;
		}
		return true;
	}
	bool MovableCharact::MoveDown(unsigned int distance){
		for (unsigned int i = 0; i < distance; ++i){
			if (IsDownTouched())return false;
			++place.y;
		}
		return true;
	}
	bool MovableCharact::MoveUp(unsigned int distance){
		for (unsigned int i = 0; i < distance; ++i){
			if (IsUpTouched())return false;
			--place.y;
		}
		return true;
	}

	//Check
	bool MovableCharact::IsDownTouched()const{
		int yplace = place.y + cdata.offsetY + cdata.height;
		int xini = place.x + cdata.offsetX;
		int xfinal = xini + cdata.width;
		for (int x = xini; x < xfinal; x++)
		{
			if (checkFunctions.isBlockUpDown(Point(x, yplace)))return true;
		}
		return false;
	}
	bool MovableCharact::IsRightTouched()const{
		int xplace = place.x + cdata.width + cdata.offsetX;
		int yini = place.y + cdata.offsetY;
		int yfinal = yini + cdata.height;
		for (int y = yini; y < yfinal; y++)
		{
			if (checkFunctions.isBlockLeftRight(Point(xplace, y)))return true;
		}
		return false;
	}
	bool MovableCharact::IsLeftTouched()const{
		int xplace = place.x + cdata.offsetX - 1;
		int yini = place.y + cdata.offsetY;
		int yfinal = yini + cdata.height;
		for (int y = yini; y < yfinal; y++)
		{
			if (checkFunctions.isBlockRightLeft(Point(xplace, y)))return true;
		}
		return false;
	}
	bool MovableCharact::IsUpTouched()const{
		int yplace = place.y + cdata.offsetY - 1;
		int xini = place.x + cdata.offsetX;
		int xfinal = xini + cdata.width;
		for (int x = xini; x < xfinal; x++)
		{
			if (checkFunctions.isBlockDownUp(Point(x, yplace)))return true;
		}
		return false;
	}
	// full check
	bool MovableCharact::IsDownFullTouched()const{
		int yplace = place.y + cdata.offsetY + cdata.height;
		int xini = place.x + cdata.offsetX;
		int xfinal = xini + cdata.width;
		for (int x = xini; x < xfinal; x++)
		{
			if (!checkFunctions.isBlockUpDown(Point(x, yplace)))return false;
		}
		return true;
	}
	bool MovableCharact::IsRightFullTouched()const{
		int xplace = place.x + cdata.width + cdata.offsetX;
		int yini = place.y + cdata.offsetY;
		int yfinal = yini + cdata.height;
		for (int y = yini; y < yfinal; y++)
		{
			if (checkFunctions.isBlockLeftRight(Point(xplace, y)))return false;
		}
		return true;
	}
	bool MovableCharact::IsLeftFullTouched()const{
		int xplace = place.x + cdata.offsetX - 1;
		int yini = place.y + cdata.offsetY;
		int yfinal = yini + cdata.height;
		for (int y = yini; y < yfinal; y++)
		{
			if (checkFunctions.isBlockRightLeft(Point(xplace, y)))return false;
		}
		return true;
	}
	bool MovableCharact::IsUpFullTouched()const{
		int yplace = place.y + cdata.offsetY - 1;
		int xini = place.x + cdata.offsetX;
		int xfinal = xini + cdata.width;
		for (int x = xini; x < xfinal; x++)
		{
			if (checkFunctions.isBlockDownUp(Point(x, yplace)))return false;
		}
		return true;
	}
	const Point& MovableCharact::GetPlace()const{ return place; }
	void MovableCharact::SetPlace(const Point& pt){ place = pt; }
}