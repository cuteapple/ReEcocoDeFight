#include "MapItemDefine.h"
#include "StageMap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	namespace MapA{
		namespace Map1{
			//Width = 16
			//Height = 20
			const int innermap[] = {
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, IceFloor(1), IceFloor(3), unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(25), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(26), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1), Brick(1)
			};
			const Point caterpillarPosition[] = {
				{ 160, 448 }, { 331, 448 }, { 450, 445 }, { 241, 352 }, { 385, 352 },
				{ 471, 256 }, { 291, 256 }, { 385, 160 }, { 187, 160 }, { 106, 256 }
			};

			/*  caterpillars position (Ecoco Record)
			pos : {x=160 y=448 }
			pos : {x=331 y=448 }
			pos : {x=450 y=448 }
			pos : {x=241 y=352 }
			pos : {x=385 y=352 }
			pos : {x=471 y=256 }
			pos : {x=291 y=256 }
			pos : {x=385 y=160 }
			pos : {x=187 y=160 }
			pos : {x=106 y=256 }
			*/
			const StageMap map = {
				20, 21,//Width And Height
				innermap,// Map File
				{ 37 + 64 + 32, 544 }, // Ecoco Start Location
				{ sizeof(caterpillarPosition) / sizeof(Point), caterpillarPosition },// CaterPillars
				{ 0, nullptr }//WaterMelons
			};
		}
	}
}