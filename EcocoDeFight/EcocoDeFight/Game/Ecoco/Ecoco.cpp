#include "stdafx.h"
#include "Ecoco.h"
#include "EcoPicEx.h"
#include "ControllableCharact.h"
#include "Enumeration.h"
#include "CommonFunctions.h"
#include "Ice.h"
#include <utility>
using std::move;
using namespace EcocoDeFightBase;

namespace EcocoDeFight{
	const Point Ecoco::UpperLeft(24, 6);
	const Point Ecoco::MoveUpperLeft(24, 36);
	const Point Ecoco::LowerRight(44, 64);
	const Color Ecoco::Bgcolor(0, 248, 0);

	struct Ecoco::AnimationIDs
	{
		Animator::AnimationID jumpL;
		Animator::AnimationID fallL;
		Animator::AnimationID walkL;
		Animator::AnimationID standL;
		Animator::AnimationID failL;
		Animator::AnimationID winStage;
		Animator::AnimationID failR;
		Animator::AnimationID jumpR;
		Animator::AnimationID fallR;
		Animator::AnimationID walkR;
		Animator::AnimationID standR;
		Animator::AnimationID attackL;
		Animator::AnimationID attackR;
	};

	struct Ecoco::EcocoData{
		EcocoData() :collider(static_cast<int>(CollideGroups::Charact), { Ecoco::UpperLeft, Ecoco::LowerRight }){}
		Direction facing;
		Animator::AnimationID lastStateID;
		Ecoco::AnimationIDs animationIDs;
		Animator animator;
		ControllableCharact charact;
		RectangleCollider collider;
		Penguin penguin;
		Point initialPosition;
		bool alive;
	};


	Ecoco::Ecoco(){ data = new EcocoData(); }
	Ecoco::Ecoco(Ecoco&& moving){
		this->data = moving.data;
		moving.data = nullptr;
	}
	Ecoco& Ecoco::operator=(Ecoco&& moving){
		delete this->data;
		this->data = moving.data;
		moving.data = nullptr;
		return *this;
	}
	Ecoco::~Ecoco(){ delete data; }
	void Ecoco::Initialize(const MovableCharact::BlockDirectionCheck& check){
		InitializeEcocoAnimator();
		InitializeEcocoCharact(check);
		data->penguin.Initialize([this](){return (this->data->charact.GetPlace() + Point(16, 32)); });
		data->penguin.SetPlace(this->GetPosition());
	}

	void Ecoco::Reset(){
		data->penguin.Reset();
		this->data->alive = true;
		this->SetPosition(data->initialPosition);
		data->charact.Stop();
	}

	void Ecoco::Paint(){
		data->animator.PaintAt(GetPosition());
		data->penguin.Paint();
	}

	const Point& Ecoco::GetPosition()const{ return data->charact.GetPlace(); }
	void Ecoco::SetPosition(const Point& p){ data->charact.SetPlace(p); data->initialPosition = p; data->collider.SetPosition(p); data->penguin.SetPlace(p + Point(0, 32)); }

	bool Ecoco::IsAlive()const{ return data->alive; }


	void Ecoco::Update(){
		if (!IsAlive())return;

		ControllableCharact& charact = data->charact;
		Ecoco::AnimationIDs& animationIDs = data->animationIDs;
		Direction& facing = data->facing;

		charact.Update();
		bool landed = charact.Landed();
		Animator::AnimationID currentID = -1;
		if (landed){
			if (Input::IsActive(Input::InputType::left)){
				facing = Direction::Left;
				currentID = animationIDs.walkL;
			}
			else if (Input::IsActive(Input::InputType::right)){
				facing = Direction::Right;
				currentID = animationIDs.walkR;
			}
			//No Direction Key Input
			else{
				if (facing == Direction::Right){ currentID = animationIDs.standR; }
				else                           { currentID = animationIDs.standL; }
			}
		}
		else // Flying
		{
			if (Input::IsActive(Input::InputType::left))      facing = Direction::Left;
			else if (Input::IsActive(Input::InputType::right))facing = Direction::Right;

			if (charact.MovingUp()){
				currentID = facing == Direction::Right ? animationIDs.jumpR : animationIDs.jumpL;
			}
			else //falling
			{
				currentID = facing == Direction::Right ? animationIDs.fallR : animationIDs.fallL;
			}
		}

		if (data->lastStateID != currentID){
			data->lastStateID = currentID;
			data->animator.ChangeAnimation(currentID);
		}

		data->animator.Update();

		data->collider.SetPosition(GetPosition());
		if (data->collider.IsCollideWith(static_cast<int>(CollideGroups::Enemy))){ data->alive = false; return; }
		Ice* ice = Ice::GetIce(data->collider);
		if (ice != nullptr){ data->penguin.HoldIce(ice); }
		if (Input::IsActiving(Input::InputType::x))data->penguin.Attack(data->facing);
		data->penguin.Update();
	}

	void Ecoco::InitializeEcocoAnimator(){
		AnimationIDs& animationIDs = data->animationIDs;
		Animator& animator = data->animator;

		unsigned int winStageBitmapIDs[] = { IDB_ECOCO_FINISH_0, IDB_ECOCO_FINISH_1, IDB_ECOCO_FINISH_2, IDB_ECOCO_FINISH_3 };
		animationIDs.winStage = animator.AddAnimation(InitializeAnimation(winStageBitmapIDs, sizeof(winStageBitmapIDs) / sizeof(unsigned int), Bgcolor, 2, 3));

		unsigned int failLBitmapIDs[] = {
			IDB_ECOCO_FAIL_0, IDB_ECOCO_FAIL_1, IDB_ECOCO_FAIL_2, IDB_ECOCO_FAIL_3,
			IDB_ECOCO_FAIL_4, IDB_ECOCO_FAIL_5, IDB_ECOCO_FAIL_6, IDB_ECOCO_FAIL_7,
			IDB_ECOCO_FAIL_8, IDB_ECOCO_FAIL_9, IDB_ECOCO_FAIL_10, IDB_ECOCO_FAIL_11 };
		animationIDs.failL = animator.AddAnimation(InitializeAnimation(failLBitmapIDs, sizeof(failLBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int failRBitmapIDs[] = {
			IDB_ECOCO_FAIL_0, IDB_ECOCO_FAIL_11, IDB_ECOCO_FAIL_10, IDB_ECOCO_FAIL_9,
			IDB_ECOCO_FAIL_8, IDB_ECOCO_FAIL_7, IDB_ECOCO_FAIL_6, IDB_ECOCO_FAIL_5,
			IDB_ECOCO_FAIL_4, IDB_ECOCO_FAIL_3, IDB_ECOCO_FAIL_2, IDB_ECOCO_FAIL_1 };
		animationIDs.failR = animator.AddAnimation(InitializeAnimation(failRBitmapIDs, sizeof(failRBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int moveLeftBitmapIDs[] = {
			IDB_ECOCO_MOVELEFT_2, IDB_ECOCO_MOVELEFT_3, IDB_ECOCO_MOVELEFT_4, IDB_ECOCO_MOVELEFT_3, IDB_ECOCO_MOVELEFT_2,
			IDB_ECOCO_MOVELEFT_1, IDB_ECOCO_MOVELEFT_0, IDB_ECOCO_MOVELEFT_1
		};
		animationIDs.walkL = animator.AddAnimation(InitializeAnimation(moveLeftBitmapIDs, sizeof(moveLeftBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 2));

		unsigned int moveRightBitmapIDs[] = {
			IDB_ECOCO_MOVERIGHT_2, IDB_ECOCO_MOVERIGHT_3, IDB_ECOCO_MOVERIGHT_4, IDB_ECOCO_MOVERIGHT_3, IDB_ECOCO_MOVERIGHT_2,
			IDB_ECOCO_MOVERIGHT_1, IDB_ECOCO_MOVERIGHT_0, IDB_ECOCO_MOVERIGHT_1
		};
		animationIDs.walkR = animator.AddAnimation(InitializeAnimation(moveRightBitmapIDs, sizeof(moveRightBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 2));

		unsigned int jumpLBitmapIDs[] = {
			IDB_ECOCO_JUMPL_0, IDB_ECOCO_JUMPL_1, IDB_ECOCO_JUMPL_2
		};
		animationIDs.jumpL = animator.AddAnimation(InitializeAnimation(jumpLBitmapIDs, sizeof(jumpLBitmapIDs) / sizeof(unsigned int), Bgcolor, 2, 1));

		unsigned int fallLBitmapIDs[] = {
			IDB_ECOCO_FALL_L
		};
		animationIDs.fallL = animator.AddAnimation(InitializeAnimation(fallLBitmapIDs, sizeof(fallLBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int jumpRBitmapIDs[] = {
			IDB_ECOCO_JUMPR_0, IDB_ECOCO_JUMPR_1, IDB_ECOCO_JUMPR_2
		};
		animationIDs.jumpR = animator.AddAnimation(InitializeAnimation(jumpRBitmapIDs, sizeof(jumpRBitmapIDs) / sizeof(unsigned int), Bgcolor, 2, 1));

		unsigned int fallRBitmapIDs[] = {
			IDB_ECOCO_FALL_R
		};
		animationIDs.fallR = animator.AddAnimation(InitializeAnimation(fallRBitmapIDs, sizeof(fallRBitmapIDs) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int standLBitmaps[] = {
			IDB_ECOCO_STANDL
		};
		animationIDs.standL = animator.AddAnimation(InitializeAnimation(standLBitmaps, sizeof(standLBitmaps) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int standRBitmaps[] = {
			IDB_ECOCO_STANDR
		};
		animationIDs.standR = animator.AddAnimation(InitializeAnimation(standRBitmaps, sizeof(standRBitmaps) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int attackRBitmaps[] = {
			IDB_ECOCO_ATTACKR_0, IDB_ECOCO_ATTACKR_1, IDB_ECOCO_ATTACKR_2
		};
		animationIDs.attackR = animator.AddAnimation(InitializeAnimation(attackRBitmaps, sizeof(attackRBitmaps) / sizeof(unsigned int), Bgcolor, 0, 1));

		unsigned int attackLBitmaps[] = {
			IDB_ECOCO_ATTACKL_0, IDB_ECOCO_ATTACKL_1, IDB_ECOCO_ATTACKL_2
		};
		animationIDs.attackL = animator.AddAnimation(InitializeAnimation(attackLBitmaps, sizeof(attackLBitmaps) / sizeof(unsigned int), Bgcolor, 0, 1));

		animator.ChangeAnimation(animationIDs.standR);
		data->lastStateID = animationIDs.standR;
		data->facing = Direction::Right;
	}

	void Ecoco::InitializeEcocoCharact(MovableCharact::BlockDirectionCheck check){
		ControllableCharact::ControllableCharactData cdata;
		cdata = GetBasicControllableCharactData(MoveUpperLeft, LowerRight);
		ControllableCharact::ControllableCharactFunctions cfunction;
		auto mfunction = (MovableCharact::BlockDirectionCheck*)&cfunction;
		(*mfunction) = check;
		cfunction.isJump = [](){return (Input::IsActive(Input::InputType::z) || Input::IsActive(Input::InputType::c)); };
		cfunction.isMoveLeft = [](){return Input::IsActive(Input::InputType::left); };
		cfunction.isMoveRight = [](){return Input::IsActive(Input::InputType::right); };
		data->charact.Initialize({ 20, 20 }, cdata, cfunction);
	}
}