#include "stdafx.h"
#include "PenguinState_Attack.h"
#include "EcoPicEx.h"
#include "Enumeration.h"
#include "Penguin.h"
#include "Color.h"
#include <functional>
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	/*
		const static int velocity = 20;
		const static int duration = 10;
		bool finalState = false;
		int currentFrame;
		int currentSpeed;
		int targetY;
		*/

	PenguinState_Attack::PenguinState_Attack(Penguin* p) : PenguinState(p), collider(static_cast<int>(CollideGroups::Penguin), { { 0, 0 }, { 32, 32 } }, false){}
	void PenguinState_Attack::Initialize(){
		const Color bgColor(0, 184, 0);
		BmpAttackL.Load(IDB_PENGUIN_ATTACKL, bgColor);
		BmpAttackR.Load(IDB_PENGUIN_ATTACKR, bgColor);
		this->Stop();
	}
	void PenguinState_Attack::Start(Direction dir, int targetY){
		active = true;
		finalState = false;
		collider.Enable();
		currentFrame = 0;
		currentSpeed = dir == Direction::Right ? velocity : -velocity;
		currentTargetY = targetY;
	}
	bool PenguinState_Attack::IsRunning()const{ return active; }
	void PenguinState_Attack::Update(){
		if (!active)return;
		if (finalState){ Stop();  return; }

		Point pori = penguin->GetPlace();
		int deltaY = (currentTargetY - pori.y) / 2;
		pori += Point{ currentSpeed, deltaY };
		penguin->SetPlace(pori);
		collider.SetPosition(penguin->GetPlace());
		++currentFrame;

		//Late Change State So Ememy Can Detect Penguin
		if (collider.IsCollideWith(static_cast<int>(CollideGroups::Enemy)) || currentFrame >= duration) finalState = true;
	}
	void PenguinState_Attack::Stop(){
		finalState = true;
		active = false;
		collider.Disable();
	}
	void PenguinState_Attack::Paint(){
		if (currentSpeed > 0)BmpAttackR.PaintAt(penguin->GetPlace() + Point(-16, -8));
		else BmpAttackL.PaintAt(penguin->GetPlace() + Point(-16, -8));
	}
}