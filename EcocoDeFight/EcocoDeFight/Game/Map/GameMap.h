#ifndef ECOCO_DE_FIGHT_GAMEMAP_H
#define ECOCO_DE_FIGHT_GAMEMAP_H

#include "Bitmap.h"
#include "StageMap.h"
#include <vector>
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	using namespace std;

	class GameMap
	{
	public:
		static void LoadBitmaps();
		static Bitmap& GetBitmap(int mapitem);
		static bool IsBrick(int mapitem);
		static bool IsFloor(int mapitem);
		static bool IsAir(int mapitem);
	private:
		static vector<Bitmap> mapItems;
	};
}
#endif