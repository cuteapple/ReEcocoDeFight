#include "stdafx.h"
#include "Caterpillar.h"
#include "Point.h"
#include "GameMap.h"
#include "CommonFunctions.h"
#include "EcoPicEx.h"
#include "Animator.h"
#include "Enumeration.h"
#include "Ice.h"
#include "Enumeration.h"
#include <cstdlib>
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	static const int inverseDelayTime = 12;
	const Point Caterpillar::HurtOffset(6, 32);

	struct Caterpillar::AnimationIDs
	{
		Animator::AnimationID moveLeft;
		Animator::AnimationID moveRight;
		Animator::AnimationID failLeft;
		Animator::AnimationID failRight;
	};

	struct Caterpillar::CaterpillarData{
		~CaterpillarData(){ delete collider; delete ice; }
		Point InitialPosition;
		RectangleCollider* collider = nullptr;
		MovableCharact charact;
		Caterpillar::AnimationIDs animationIDs;
		Animator animator;
		Ice* ice = nullptr;
		Direction facing;
		bool alive;
		int inverseDelay;
	};

	Caterpillar::Caterpillar(){ data = new CaterpillarData; }
	Caterpillar::Caterpillar(Caterpillar&& c){ data = c.data; c.data = nullptr; }
	Caterpillar& Caterpillar::operator =(Caterpillar&& c){ delete data; data = c.data; c.data = nullptr; return *this; }
	Caterpillar::~Caterpillar(){ delete data; }

	void Caterpillar::Initialize(const Point& position, const MovableCharact::BlockDirectionCheck& check){
		//Initialize Charact
		MovableCharact::MovableCharactData md;
		md.offsetX = HurtOffset.x;
		md.offsetY = HurtOffset.y;
		md.width = HurtWidth;
		md.height = HurtHeight;
		data->charact.Initialize(position, check, md);
		data->charact.MoveDown(100);//Keep On Land
		data->InitialPosition = data->charact.GetPlace();

		//Initialize Animations
		Color bgColor(0, 248, 0);
		AnimationIDs& animationIDs = data->animationIDs;
		Animator& animator = data->animator;
		//move left
		unsigned int moveLeftIDs[] = { IDB_CATERPILLAR_MOVELEFT_1, IDB_CATERPILLAR_MOVELEFT_2, IDB_CATERPILLAR_MOVELEFT_3, IDB_CATERPILLAR_MOVELEFT_2 };
		animationIDs.moveLeft = animator.AddAnimation(InitializeAnimation(moveLeftIDs, sizeof(moveLeftIDs) / sizeof(unsigned int), bgColor, 0, 3));
		//move right
		unsigned int moveRightIDs[] = { IDB_CATERPILLAR_MOVERIGHT_1, IDB_CATERPILLAR_MOVERIGHT_2, IDB_CATERPILLAR_MOVERIGHT_3, IDB_CATERPILLAR_MOVERIGHT_2 };
		animationIDs.moveRight = animator.AddAnimation(InitializeAnimation(moveRightIDs, sizeof(moveRightIDs) / sizeof(unsigned int), bgColor, 0, 3));
		//fail left
		unsigned int failLeftIDs[] = { IDB_CATERPILLAR_FAIL_L };
		animationIDs.failLeft = animator.AddAnimation(InitializeAnimation(failLeftIDs, sizeof(failLeftIDs) / sizeof(unsigned int), bgColor, 0, 2));
		//fail right
		unsigned int failRightIDs[] = { IDB_CATERPILLAR_FAIL_R };
		animationIDs.failRight = animator.AddAnimation(InitializeAnimation(failRightIDs, sizeof(failRightIDs) / sizeof(unsigned int), bgColor, 0, 2));


		//Initialize Collider
		RectangleCollider::Parameters cparam;
		cparam.upperLeft = HurtOffset;
		cparam.lowerRight = HurtOffset + Point{ HurtWidth, HurtHeight };
		data->collider = new RectangleCollider(static_cast<int>(CollideGroups::Enemy), cparam);
		data->collider->SetPosition(this->GetPosition());

		//Initialize Ice
		//freeze left
		unsigned int iceLeftIDs[] = { IDB_CATERPILLAR_ICE_L };
		Animation iceLeftAnimation = InitializeAnimation(iceLeftIDs, sizeof(iceLeftIDs) / sizeof(unsigned int), bgColor, 0, 2);
		//freeze right
		unsigned int iceRightIDs[] = { IDB_CATERPILLAR_ICE_R };
		Animation iceRightAnimation = InitializeAnimation(iceRightIDs, sizeof(iceRightIDs) / sizeof(unsigned int), bgColor, 0, 2);
		cparam.upperLeft.y -= 5;//use this collider's cparam and a bit higher
		data->ice = new Ice(iceLeftAnimation, iceRightAnimation, cparam, data->charact, Point(32, 48), 32);
		data->ice->Disable();

		//Initialize State
		srand(clock());
		if (rand() % 2 == 0){
			animator.ChangeAnimation(animationIDs.moveLeft);
			data->facing = Direction::Left;
		}
		else
		{
			animator.ChangeAnimation(animationIDs.moveRight);
			data->facing = Direction::Right;
		}
		data->alive = true;
		data->inverseDelay = 0;
	}
	void Caterpillar::Update(){
		if (!data->alive)return;
		if (IsIced())//Iced
		{
			Ice& ice = *(data->ice);
			ice.Update();
			if (!ice.IsAlive())data->alive = false;
		}
		else
		{
			auto& charact = data->charact;
			Collider& collider = *(data->collider);
			//Inverse Delay
			if (data->inverseDelay > 0){ --data->inverseDelay; }
			//Inversing
			else if (data->inverseDelay == 0){
				--data->inverseDelay;
				Inverse(data->facing);
				if (IsFaceingLeft()){ data->animator.ChangeAnimation(data->animationIDs.moveLeft); }
				else                { data->animator.ChangeAnimation(data->animationIDs.moveRight); }
			}
			//Moving
			else {
				bool success;
				if (IsFaceingLeft()){ success = charact.MoveLeft(Speed); }
				else                { success = charact.MoveRight(Speed); }
				if (!success || !data->charact.IsDownFullTouched()){
					data->inverseDelay = inverseDelayTime;
				}
				data->animator.Update();
				collider.SetPosition(this->GetPosition());
			}
			if (collider.IsCollideWith(static_cast<int>(CollideGroups::FlyingIce)))	data->alive = false;
			else if (collider.IsCollideWith(static_cast<int>(CollideGroups::Penguin)))SetIceState(true);
		}
	}

	void Caterpillar::SetIceState(bool b){
		if (b == IsIced())return;//No Things To Change
		if (b){
			data->ice->Enable(data->facing);
			data->ice->SetPosition(GetPosition());
			data->collider->Disable();
		}
		else {
			data->ice->Disable();
			data->collider->Enable();
		}
	}
	bool Caterpillar::IsIced()const{ return data->ice->IsEnabled(); }

	void Caterpillar::Paint(){
		if (!IsAlive())return;
		if (IsIced())data->ice->Paint();
		else data->animator.PaintAt(data->charact.GetPlace());
	}
	void Caterpillar::Reset(){
		data->alive = true;
		data->ice->Disable();
		data->charact.SetPlace(data->InitialPosition);
		data->animator.ChangeAnimation(IsFaceingLeft() ? data->animationIDs.moveLeft : data->animationIDs.moveRight);
		data->collider->Enable();
	}
	const Point& Caterpillar::GetPosition()const{ return data->charact.GetPlace(); }
	void Caterpillar::SetPosition(const Point& p){ data->charact.SetPlace(p); data->collider->SetPosition(p); }
	bool Caterpillar::IsAlive()const{ return data->alive; }
	bool Caterpillar::IsFaceingLeft()const{ return data->facing == Direction::Left; }
};