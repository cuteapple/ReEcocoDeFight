#ifndef ECOCO_DE_FIGHT_STAGEMAP_H
#define ECOCO_DE_FIGHT_STAGEMAP_H
#include <vector>
#include "Point.h"
#include "Enumeration.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	using namespace std;

	struct MapObjectsStoreType
	{
		int count;
		const Point* appearPlace;
	};

	struct StageMap
	{
		int width;
		int height;
		const int* map;
		//Always Have Main Charact, So Not Inside MapObjectsStoreType
		Point startPlace;
		MapObjectsStoreType Caterpilars;
		MapObjectsStoreType WaterMelons;
	};
};
#endif