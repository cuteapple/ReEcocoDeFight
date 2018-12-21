#ifndef ECOCO_DE_FIGHT_MAP_H
#define ECOCO_DE_FIGHT_MAP_H

#include <functional>
#include "Bitmap.h"
#include "Point.h"

using std::function;
using namespace EcocoDeFightBase;

namespace EcocoDeFightBase{
	class Map
	{
	public:
		//it might be better using template but this is enough now
		typedef int MapItemType;
		Map();
		Map(const Map&) = delete;
		Map& operator = (const Map&) = delete;
		~Map();

		void LoadMap(const MapItemType* map, unsigned int mapWidth, unsigned int mapHeight, bool copyMap = false);
		MapItemType GetMapItem(const Point& mapPlace)const;

		void InitializeWorld(function<Bitmap&(MapItemType)> getbmp, unsigned int blockWidth, unsigned int blockHeight, unsigned int screenWidth, unsigned int screenHeight);
		MapItemType GetMapItemWorld(const Point& worldPlace)const;
		void Paint();
	private:
		Point WorldCoordToMapCoord(const Point&)const;
		//map varibles
		const MapItemType* map = NULL;
		bool iscopy = false;
		unsigned int mapWidth, mapHeight;
		unsigned int blockWidth, blockHeight;
		//Paint variables
		unsigned int screenWidth, screenHeight;
		function<Bitmap(MapItemType)> mapItemTobmp;
	};
}
#endif //ECOCO_DE_FIGHT_MAP_H