#include "stdafx.h"
#include "Watermelon.h"
#include "Point.h"
#include "CommonFunctions.h"
#include "EcoPicEx.h"
#include "Collider.h"
#include "MovableCharact.h"
#include "Animator.h"
#include "Enumeration.h"
#include "Ice.h"
#include <cstdlib>
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	static const int inverseProb = 6;
	static const int Speeds[] = { 3, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0 };

	//Pick Speed (0.5 prob. be negtive)
	static int PickSpeed(){
		if (rand() % 2){
			return -Speeds[rand() % (sizeof(Speeds) / sizeof(int))];
		}
		else
		{
			return Speeds[rand() % (sizeof(Speeds) / sizeof(int))];
		}
	}
	//Pick Speed (1/inverseProb prob. be inverse direction)
	static int PickSpeed(int currentSpeed){
		bool neg = currentSpeed < 0;
		if (rand() % inverseProb == 0)neg = !neg;
		if (neg){
			return -Speeds[rand() % (sizeof(Speeds) / sizeof(int))];
		}
		else
		{
			return Speeds[rand() % (sizeof(Speeds) / sizeof(int))];
		}
	}
	struct Watermelon::AnimationIDs
	{
		Animator::AnimationID normal;
		Animator::AnimationID jump;
		Animator::AnimationID fail;
	};

	struct Watermelon::WaterMelonData
	{
		WaterMelonData() :
			collider(static_cast<int>(CollideGroups::Enemy), { Watermelon::Center, Watermelon::Radius })
			, ice(nullptr), InitialPosition(0, 0), alive(true){}
		~WaterMelonData(){ delete(ice); }
		Point InitialPosition;
		CircleCollider collider;
		MovableCharact charact;
		AnimationIDs animationIDs;
		Animator animator;
		Ice* ice;

		State state;
		bool alive;
		int speedY;
		int speedX;
		int landingCount;
		int maxLandingCount;
	};
	const Point Watermelon::Center(32, 32);

	Watermelon::Watermelon(){ data = new WaterMelonData; }
	Watermelon::Watermelon(Watermelon&& c){ data = c.data; c.data = nullptr; }
	Watermelon& Watermelon::operator =(Watermelon&& c){ delete data; data = c.data; c.data = nullptr; return *this; }
	Watermelon::~Watermelon(){ delete data; }

	void Watermelon::Initialize(const Point& position, const MovableCharact::BlockDirectionCheck& check){
		//Initialize Charact
		MovableCharact::MovableCharactData md;
		md.offsetX = 16;
		md.offsetY = 32;
		md.width = Watermelon::Radius;
		md.height = Watermelon::Radius;
		MovableCharact::BlockDirectionCheck c = check;
		data->charact.Initialize(position, c, md);
		data->InitialPosition = position;

		//Initialize Animations
		Color bgColor(0, 248, 0);
		AnimationIDs& animationIDs = data->animationIDs;
		Animator& animator = data->animator;
		//normal
		unsigned int normalIDs[] = { IDB_WATERMELON_JUMP_1 };
		animationIDs.normal = animator.AddAnimation(InitializeAnimation(normalIDs, sizeof(normalIDs) / sizeof(unsigned int), bgColor, 0, 1000));
		//jump
		unsigned int jumpIDs[] = { IDB_WATERMELON_JUMP_2, IDB_WATERMELON_JUMP_3, IDB_WATERMELON_JUMP_2 };
		animationIDs.jump = animator.AddAnimation(InitializeAnimation(jumpIDs, sizeof(jumpIDs) / sizeof(unsigned int), bgColor, 4, 1));
		data->maxLandingCount = sizeof(jumpIDs) / sizeof(unsigned int);
		//fail
		unsigned int failIDs[] = { IDB_WATERMELON_FAIL_1, IDB_WATERMELON_FAIL_2 };
		animationIDs.fail = animator.AddAnimation(InitializeAnimation(failIDs, sizeof(failIDs) / sizeof(unsigned int), bgColor, 1, 2));

		//Initialize Collider
		data->collider.SetPosition(position);

		//Initialize Ice
		Animation pice;
		Bitmap bmpice;
		bmpice.Load(IDB_WATERMELON_ICE, bgColor);
		pice.AddBitmap(bmpice);
		data->ice = new Ice(pice, pice, CircleCollider::Parameters{ Watermelon::Center, Watermelon::Radius }, data->charact, Watermelon::Center, Watermelon::Radius * 2);
		data->ice->Disable();

		//State Data
		data->speedX = PickSpeed();
		data->state = State::Air;
		data->alive = true;
		data->speedY = 0;
	}

	void Watermelon::Update(){
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
			switch (data->state)
			{
				case Watermelon::State::Air:
					if (IsFaceingLeft()){ if (!charact.MoveLeft(SpeedX))data->speedX = -data->speedX; }
					else                { if (!charact.MoveRight(SpeedX))data->speedX = -data->speedX; }
					data->speedY += Accelerate;
					if (data->speedY){
						if (data->speedY > 0){
							if (data->speedY > Watermelon::SpeedJump)data->speedY = Watermelon::SpeedJump;
							if (!charact.MoveDown(data->speedY)){
								data->state = Watermelon::State::Landing;
								data->landingCount = 0;
								data->animator.ChangeAnimation(data->animationIDs.jump);
							}
						}
						else { //if (data->speedY < 0)
							if (data->speedY < -Watermelon::SpeedJump)data->speedY = -Watermelon::SpeedJump;
							charact.MoveUp(-data->speedY);
						}
					}
					break;
				case Watermelon::State::Landing:
					++data->landingCount;
					if (data->landingCount == data->maxLandingCount){
						data->speedX = PickSpeed(data->speedX);
						data->state = Watermelon::State::Air;
						data->animator.ChangeAnimation(data->animationIDs.normal);
						data->speedY = -Watermelon::SpeedJump;
					}
					break;
			}
			data->animator.Update();
			Collider& collider = data->collider;
			collider.SetPosition(this->GetPosition());
			if (collider.IsCollideWith(static_cast<int>(CollideGroups::FlyingIce)))	data->alive = false;
			else if (collider.IsCollideWith(static_cast<int>(CollideGroups::Penguin)))SetIceState(true);
		}
	}

	void Watermelon::Paint(){
		if (!IsAlive())return;
		if (IsIced())data->ice->Paint();
		else data->animator.PaintAt(data->charact.GetPlace());
	}

	void Watermelon::Reset(){
		data->alive = true;
		data->ice->Disable();
		data->charact.SetPlace(data->InitialPosition);
		data->animator.ChangeAnimation(data->animationIDs.normal);
		data->collider.Enable();
	}

	void Watermelon::SetIceState(bool b){
		if (b == IsIced())return;//No Things To Change
		if (b){
			data->ice->Enable(IsFaceingLeft() ? Direction::Left : Direction::Right);
			data->ice->SetPosition(GetPosition());
			data->collider.Disable();
		}
		else {
			data->ice->Disable();
			data->collider.Enable();
		}
	}

	const Point& Watermelon::GetPosition()const{ return data->charact.GetPlace(); }
	void Watermelon::SetPosition(const Point& p){ data->charact.SetPlace(p); }
	bool Watermelon::IsIced()const{ return data->ice->IsEnabled(); }
	bool Watermelon::IsAlive()const{ return data->alive; }
	bool Watermelon::IsFaceingLeft()const{ return data->speedX < 0; }
};