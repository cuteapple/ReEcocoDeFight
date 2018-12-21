#include <stdafx.h>
#include <functional>
#include <cstring>

#include "Bitmap.h"
#include "Map.h"
#include "Point.h"
#include "Camera.h"

using namespace std;

namespace EcocoDeFightBase{

	static inline bool MoreThan(const int i, const unsigned int u){ return i > 0 && static_cast<unsigned int>(i) > u; }

	Map::Map(){}

	Map::~Map(){ if (iscopy)delete this->map; }

	void Map::LoadMap(const MapItemType* map, unsigned int mapWidth, unsigned int mapHeight, bool copyMap){
		//create a copy of new map if requested
		if (copyMap){
			int length = mapWidth*mapHeight;
			int* newmap = new int[length];
			for (int i = 0; i < length; ++i){
				newmap[i] = map[i];
			}
			map = newmap;
		}

		if (iscopy)delete this->map;
		this->map = map;
		iscopy = copyMap;

		this->mapWidth = mapWidth;
		this->mapHeight = mapHeight;

	}

	Map::MapItemType Map::GetMapItemWorld(const Point& worldPlace)const{
		Point mapPlace = WorldCoordToMapCoord(worldPlace);
		return GetMapItem(mapPlace);
	}

	Map::MapItemType Map::GetMapItem(const Point& mapPlace)const{
		return map[mapPlace.y*mapWidth + mapPlace.x];
	}

	void Map::InitializeWorld(function<Bitmap&(MapItemType)> getbmp, unsigned int blockWidth, unsigned int blockHeight, unsigned int screenWidth, unsigned int screenHeight){
		mapItemTobmp = getbmp;
		this->blockWidth = blockWidth;
		this->blockHeight = blockHeight;
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
	}

	void Map::Paint(){
		if (!mapItemTobmp)return;//Paint Not Initialized

		//screanWidth/Height and blockWidth/Height can be changed at different time
		//so it is needed to calculate screanBlockCountX/screanBlockCountY in Paint() (and other corresponded)
		unsigned int screanBlockCountX = screenWidth / blockWidth + 1;
		unsigned int screanBlockCountY = screenHeight / blockHeight + 1;

		Point cameraPointAtMap = WorldCoordToMapCoord(Camera::GetCameraPosition());
		Point paint_upperLeft(cameraPointAtMap);
		Point paint_LowerRight(cameraPointAtMap.x + screanBlockCountX + 1, cameraPointAtMap.y + screanBlockCountY + 1);

		if (paint_upperLeft.x < 0)paint_upperLeft.x = 0;
		if (paint_upperLeft.y < 0)paint_upperLeft.y = 0;
		if (MoreThan(paint_LowerRight.x, mapWidth - 1))
			paint_LowerRight.x = mapWidth - 1;
		if (MoreThan(paint_LowerRight.y, mapHeight - 1))
			paint_LowerRight.y = mapHeight - 1;

		for (int x = paint_upperLeft.x; x <= paint_LowerRight.x; ++x){
			for (int y = paint_upperLeft.y; y <= paint_LowerRight.y; ++y){
				mapItemTobmp(GetMapItem(Point(x, y))).PaintAt(Point(x*blockWidth, y*blockHeight));
			}
		}
	}

	Point Map::WorldCoordToMapCoord(const Point& point)const{
		return Point(point.x / blockWidth, point.y / blockHeight);
	}
}