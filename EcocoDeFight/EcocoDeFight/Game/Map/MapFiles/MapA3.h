#include "MapItemDefine.h"
#include "StageMap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	namespace MapA{
		namespace Map3{
			//Width = 24
			//Height = 16+7
			const int innermap[] = {
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(3), unknown, IceFloor(1), IceFloor(3), unknown, IceFloor(1), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(3), unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, IceFloor(1), IceFloor(3), unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(3), unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(1),
				Brick(25), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(26)
			};
			/*
			EcocoReprot :  {x=49 y=640 }
			EcocoReprot :  {x=462 y=448 }
			EcocoReprot :  {x=535 y=320 }
			EcocoReprot :  {x=77 y=224 }
			EcocoReprot :  {x=10 y=384 }
			EcocoReprot :  {x=347 y=86 }
			EcocoReprot :  {x=582 y=224 }
			EcocoReprot :  {x=623 y=544 }
			EcocoReprot :  {x=488 y=640 }
			EcocoReprot :  {x=275 y=544 }
			*/
			const Point WaterMelonPosition[] = {
				{ 49, 640 }, { 462, 448 }, { 535, 320 }, { 77, 224 }, { 32, 384 }, { 347, 86 }, { 582, 224 }, { 623, 544 }, { 488, 640 }
			};
			const StageMap map = {
				24, 16 + 7,//Width And Height
				innermap,// Map File
				{ 275, 544 }, // Ecoco Start Location
				{ 0, nullptr },// CaterPillars
				{ sizeof(WaterMelonPosition) / sizeof(Point), WaterMelonPosition }//WaterMelons
			};
		}
	}
}