#include "MapItemDefine.h"
#include "StageMap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	namespace MapA{
		namespace Map2{
			//Width = 16+4
			//Height = 29
			const int innermap[] = {
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(1), Brick(1),
				Brick(1), Brick(1), Brick(25), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(26), Brick(1), Brick(1) };
			const Point caterpillarPosition[] = {
				{ 177, 736 }, { 292, 672 }, { 423, 672 }, { 176, 480 }, { 309, 480 }, { 83, 352 }, { 485, 576 },
				{ 97, 160 }, { 166, 160 }, { 230, 160 }, { 294, 160 }, { 346, 160 }, { 389, 160 }
			};
			/*
			EcocoReprot :  {x=177 y=736 }
			EcocoReprot :  {x=292 y=672 }
			EcocoReprot :  {x=440 y=672 }
			EcocoReprot :  {x=262 y=416 }
			EcocoReprot :  {x=83 y=352 }
			EcocoReprot :  {x=97 y=160 }
			EcocoReprot :  {x=166 y=160 }
			EcocoReprot :  {x=230 y=160 }
			EcocoReprot :  {x=294 y=160 }
			EcocoReprot :  {x=346 y=160 }
			EcocoReprot :  {x=389 y=160 }
			*/
			const StageMap map = {
				20, 29,//Width And Height
				innermap,// Map File
				{ 37 + 64, 26 * 32 }, // Ecoco Start Location
				{ sizeof(caterpillarPosition) / sizeof(Point), caterpillarPosition },// CaterPillars
				{ 0, nullptr }//WaterMelons
			};
		}
	}
}