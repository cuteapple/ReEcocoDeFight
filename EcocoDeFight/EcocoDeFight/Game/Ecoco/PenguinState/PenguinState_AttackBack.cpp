#include "stdafx.h"
#include "PenguinState_AttackBack.h"
#include "EcoPicEx.h"
#include "Penguin.h"
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	/*
	const static int duration = 10 + 10;
	const static int velocityY = 1;
	int currentFrame;
	Point currentSpeed;
	Bitmap bitmap;
	*/
	void PenguinState_AttackBack::Initialize(){
		const Color bgColor(0, 184, 0);
		BmpLeft.Load(IDB_PENGUIN_ATTACK_BACKL, bgColor);
		BmpRight.Load(IDB_PENGUIN_ATTACK_BACKR, bgColor);
	}
	bool PenguinState_AttackBack::IsRunning()const{ return currentFrame < duration; }
	void PenguinState_AttackBack::Start(int targetX){
		currentSpeed = Point((targetX - penguin->GetPlace().x) / duration, -velocityY);
		currentFrame = 0;
	}
	void PenguinState_AttackBack::Update(){
		if (!IsRunning())return;
		if (currentFrame == duration1)currentSpeed.y = -currentSpeed.y;
		penguin->SetPlace(penguin->GetPlace() + currentSpeed);
		++currentFrame;
	}
	void PenguinState_AttackBack::Stop(){
		currentFrame = duration;
	}
	void PenguinState_AttackBack::Paint(){
		if (currentSpeed.x>0)BmpLeft.PaintAt(penguin->GetPlace() + Point(-16, -8));
		else BmpRight.PaintAt(penguin->GetPlace() + Point(-16, -8));
	}
}