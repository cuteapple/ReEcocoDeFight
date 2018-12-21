#ifndef ECOCO_DE_FIGHT_COMMONFUNCTIONS_H
#define ECOCO_DE_FIGHT_COMMONFUNCTIONS_H
#include "Animation.h"
#include "ControllableCharact.h"
#include "Color.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	Animation InitializeAnimation(const unsigned int* bitmapIDs, int count, Color BgColor, int BackToCount = 0, int keepFrame = 5);
	ControllableCharact::ControllableCharactData GetBasicControllableCharactData(const Point& upperLeft, const Point& lowerRight);
}
#endif