#ifndef ECOCO_DE_FIGHT_ANIMATION_H
#define ECOCO_DE_FIGHT_ANIMATION_H

#include "Bitmap.h"
#include "Point.h"

namespace EcocoDeFightBase{
	class Animation{
	public:
		Animation();
		~Animation();
		Animation(const Animation&);
		Animation(Animation&&);
		Animation& operator = (const Animation&);
		Animation& operator = (Animation&&);
		void Update();
		void Reset();
		void PaintAt(Point place);
		void AddBitmap(Bitmap& bitmap);
		void AddBitmap(Bitmap&& bitmap);
		void SetDelayFrameCount(int delay);

		//Set The Bitmap Number Back To When Arrive End
		void SetBackToBmpNumber(unsigned int number);

		//Get Current Bitmap Count
		unsigned int GetBitmapCount()const;
	private:
		struct AnimationData;
		AnimationData* data;
	};
}

#endif