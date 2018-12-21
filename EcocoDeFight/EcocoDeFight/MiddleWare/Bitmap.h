#ifndef ECOCO_DE_FIGHT_BITMAP_H
#define ECOCO_DE_FIGHT_BITMAP_H

#include "Point.h"
#include "Color.h"

namespace EcocoDeFightBase{

	class Bitmap
	{
	public:
		enum class AnchorType{ TOPLEFT, MIDDLEBUTTON };
		Bitmap();
		Bitmap(const Bitmap&);
		Bitmap(Bitmap&&);
		~Bitmap();
		Bitmap& operator =(const Bitmap&);
		Bitmap& operator =(Bitmap&&);

		//Load a bitmap
		void Load(UINT ID, AnchorType type = AnchorType::TOPLEFT);

		//Load a bitmap with one color hide
		void Load(UINT ID, Color bgColor, AnchorType type = AnchorType::TOPLEFT);

		//Paint this Bitmap at point 
		void PaintAt(const Point& point, bool useCameraPosition = true);

	private:
		struct BitmapData;
		BitmapData* data;
	};
}
#endif