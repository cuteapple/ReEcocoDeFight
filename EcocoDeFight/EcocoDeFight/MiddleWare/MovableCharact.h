#ifndef ECOCO_DE_FIGHT_MOVABLECHARACT_H
#define ECOCO_DE_FIGHT_MOVABLECHARACT_H

#include "Point.h"
#include <functional>

namespace EcocoDeFightBase{
	using std::function;

	//use upper left of CharactData To Calculate
	//assume +x is right and +y is down
	class MovableCharact
	{
	public:
		struct BlockDirectionCheck{
			function<bool(Point)> isBlockLeftRight;
			function<bool(Point)> isBlockRightLeft;
			function<bool(Point)> isBlockUpDown;
			function<bool(Point)> isBlockDownUp;
		};
		struct MovableCharactData
		{
			int offsetX;
			int offsetY;
			int width;
			int height;
		};

		//Initialize
		void Initialize(Point,BlockDirectionCheck, MovableCharactData);

		//move around
		bool MoveLeft(unsigned int distance);
		bool MoveRight(unsigned int distance);
		bool MoveDown(unsigned int distance);
		bool MoveUp(unsigned int distance);

		//Check
		bool IsDownTouched()const;
		bool IsRightTouched()const;
		bool IsLeftTouched()const;
		bool IsUpTouched()const;
		bool IsDownFullTouched()const;
		bool IsRightFullTouched()const;
		bool IsLeftFullTouched()const;
		bool IsUpFullTouched()const;
		const Point& GetPlace()const;
		void SetPlace(const Point& pt);

	private:
		Point place;
		BlockDirectionCheck checkFunctions;
		MovableCharactData cdata;
	};
}

#endif