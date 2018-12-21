#include "MapItemDefine.h"
#include "StageMap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	namespace MapA{
		namespace Map5{
			//Width = 24
			//Height = 13+6
			const int innermap[] = {
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5), Brick(6), unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(3), unknown, Brick(5),
				Brick(6), unknown, IceFloor(1), IceFloor(3), unknown, unknown, IceFloor(1), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), IceFloor(2), Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(6), unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown, Brick(5),
				Brick(25), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(3), Brick(26),
			};
			const Point waterMelons[] = { { 66, 736 }, { 37, 576 }, { 130, 288 }, { 561, 288 }, { 621, 736 }, { 684, 576 } };
			const Point caterPillars[] = {
				{ 260, 672 }, { 454, 672 }, { 339, 568 }, { 180, 480 }, { 530, 480 },
				{ 658, 288 }, { 578, 288 }, { 39, 288 }, { 128, 288 }, { 346, 192 } };
			const StageMap map = {
				24, 13 + 6,//Width And Height
				innermap,// Map File
				{ 608, 512 }, // Ecoco Start Location
				{ 0, nullptr },// CaterPillars
				//{ sizeof(caterPillars) / sizeof(Point), caterPillars },
				{ 0, nullptr }// WaterMelons
				//{ sizeof(waterMelons) / sizeof(Point), waterMelons }//WaterMelons
			};
		}
	}
}
