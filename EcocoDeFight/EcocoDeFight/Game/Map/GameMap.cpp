#include "stdafx.h"
#include "GameMap.h"
#include "MapItemDefine.h"
#include "Color.h"
#include "Bitmap.h"
#include "Maps.h"

using namespace EcocoDeFightBase;
using namespace std;

namespace EcocoDeFight{
	vector<Bitmap> GameMap::mapItems;

	void GameMap::LoadBitmaps(){
		static int loaded = false;
		if (loaded)return;
		loaded = true;
		Color bgColor(0, 248, 0);
		for (int i = 0; i < MaxBlockNumber - MinBlockNumber + 1; ++i){
			Bitmap bitmap;
			bitmap.Load(i + MinBlockNumber, bgColor);
			mapItems.push_back(std::move(bitmap));
		}
	}
	Bitmap& GameMap::GetBitmap(int itemID){
		return mapItems[itemID - MinBlockNumber];
	}
	bool GameMap::IsBrick(int mapitem){
		return mapitem <= IDB_BLOCK_BRICK_32;
	}
	bool GameMap::IsFloor(int mapitem){
		return mapitem <= IDB_BLOCK_ICEFLOOR_3 && mapitem >= IDB_BLOCK_ICEFLOOR_1;
	}
	bool GameMap::IsAir(int mapitem){
		return mapitem == IDB_BLOCK_AIR;
	}
}