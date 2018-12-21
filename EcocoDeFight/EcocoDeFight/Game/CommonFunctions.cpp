#include "stdafx.h"
#include "CommonFunctions.h"
#include "Animation.h"
#include "Color.h"
#include <utility>
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	Animation InitializeAnimation(const unsigned int* bitmapIDs, int count, Color BgColor, int BackToCount, int keepFrame){
		Animation animation;
		for (int i = 0; i < count; ++i){
			Bitmap bmp;
			bmp.Load(bitmapIDs[i], BgColor);
			animation.AddBitmap(move(bmp));
		}
		animation.SetBackToBmpNumber(BackToCount);
		animation.SetDelayFrameCount(keepFrame);
		return animation;
	}
	ControllableCharact::ControllableCharactData GetBasicControllableCharactData(const Point& upperLeft, const Point& lowerRight){
		static ControllableCharact::ControllableCharactData cdata;
		static bool initialized = false;
		if (!initialized){
			//Initialize Common Parameters
			initialized = true;
			cdata.accelerateLeft = 2;
			cdata.accelerateRight = 2;
			cdata.accelerateAirLeft = 1;
			cdata.accelerateAirRight = 1;
			cdata.decreaseScalerX = 0.3;
			cdata.gravity = 2;
			cdata.maxXSpeed = 10;
			cdata.maxYSpeed = 20;
			cdata.StopVelocity = 1;
			cdata.velocityJump = 15;
			cdata.jumpStayFrame = 4;
			cdata.jumpHStayFrame = 7;
		}
		cdata.offsetX = upperLeft.x;
		cdata.offsetY = upperLeft.y;
		cdata.height = lowerRight.y - upperLeft.y;
		cdata.width = lowerRight.x - upperLeft.x;
		return cdata;
	}
}