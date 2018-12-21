#include "MapItemDefine.h"
#include "StageMap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	namespace MapA{
		namespace Map4{
			//Width = 24
			//Height = 23+5
			const int innermap[] = {
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(3), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(25), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(26)
			};
			const Point waterMelons[] = { { 66, 736 }, { 37, 576 }, { 130, 288 }, { 561, 288 }, { 621, 736 }, { 684, 576 } };
			/*
			EcocoReprot : { 66,736 }
			EcocoReprot : { 37,576 }
			EcocoReprot : { 130,288 }
			EcocoReprot : { 561,288 }
			EcocoReprot : { 621,736 }
			EcocoReprot : { 684,576 }
			*/
			const Point caterPillars[] = {
				{ 260, 672 }, { 454, 672 }, { 339, 568 }, { 180, 480 }, { 530, 480 },
				{ 658, 288 }, { 578, 288 }, { 39, 288 }, { 128, 288 }, { 346, 192 } };
			/*
			EcocoReprot : { 260,672 }
			EcocoReprot : { 454,672 }
			EcocoReprot : { 339,568 }
			EcocoReprot : { 180,480 }
			EcocoReprot : { 530,480 }
			EcocoReprot : { 658,288 }
			EcocoReprot : { 578,288 }
			EcocoReprot : { 39,288 }
			EcocoReprot : { 128,288 }
			EcocoReprot : { 346,192 }
			*/
			const StageMap map = {
				24, 23 + 5,//Width And Height
				innermap,// Map File
				{ 67, 800 }, // Ecoco Start Location
				//{ 0, nullptr },// CaterPillars
				{ sizeof(caterPillars) / sizeof(Point), caterPillars },
				//{ 0, nullptr },// WaterMelons
				{ sizeof(waterMelons) / sizeof(Point), waterMelons }//WaterMelons
			};
		}
	}
}
