#include "stdafx.h"
#undef min
#undef max
#include "Mouse.h"
#include "Point.h"
#include "CommonFunctions.h"
#include "EcoPicEx.h"
#include "Animator.h"
#include "Enumeration.h"
#include "Ice.h"
#include <cstdlib>
#include <ctime>
using namespace EcocoDeFightBase;
namespace EcocoDeFight{

	static const Point UpperLeft = Point(20, 10);
	static const Point LowerRight = Point(44, 64);
	static const Point MoveUpperLeft = Point(20, 36);
	static const int SpeedX = 10;
	static const int SpeedJump = 20;
	static const int Gravity = 2;
	static const int ChangingDelay = 6;
	static const int ChangingProb = 10;//Land Only
	static const int ChangeInverseProb = 6;
	static const int ChangeJumpProb = 4;

	struct Mouse::AnimationIDs
	{
		Animator::AnimationID moveL;
		Animator::AnimationID moveR;
		Animator::AnimationID fallL;
		Animator::AnimationID fallR;
		Animator::AnimationID JumpL;
		Animator::AnimationID JumpR;
		Animator::AnimationID standL;
		Animator::AnimationID standR;
		Animator::AnimationID failL;
		Animator::AnimationID failR;
	};

	struct Mouse::MouseData{
		~MouseData(){ delete collider; delete ice; }
		Point InitialPosition;
		MovableCharact charact;
		Mouse::AnimationIDs animationIDs;
		Animator animator;
		Ice* ice = nullptr;
		RectangleCollider* collider = nullptr;
		bool alive;
		Direction facing;
		int speedY;
		enum class State{ Moving, Jumping }state;
		//enum class ChangingReason{ Back, Jump }reason;
		int ChangeingCountdown;
		void UpdataAnimation(){
			if (ChangeingCountdown > 0){ animator.ChangeAnimation(facing == Direction::Left ? animationIDs.standL : animationIDs.standR); }
			else if (state == State::Moving){ animator.ChangeAnimation(facing == Direction::Left ? animationIDs.moveL : animationIDs.moveR); }
			else if (state == State::Jumping){
				if (speedY > 0)animator.ChangeAnimation(facing == Direction::Left ? animationIDs.JumpL : animationIDs.JumpR);
				else animator.ChangeAnimation(facing == Direction::Left ? animationIDs.fallL : animationIDs.failR);
			}
		}
	};

	Mouse::Mouse(){ data = new MouseData; }
	Mouse::Mouse(Mouse&& c){ data = c.data; c.data = nullptr; }
	Mouse& Mouse::operator =(Mouse&& c){ delete data; data = c.data; c.data = nullptr; return *this; }
	Mouse::~Mouse(){ delete data; }

	void Mouse::Initialize(const Point& position, const MovableCharact::BlockDirectionCheck& check){
		//Initialize Charact
		MovableCharact::MovableCharactData mdata;
		mdata.offsetX = UpperLeft.x;
		mdata.offsetY = UpperLeft.y;
		mdata.width = LowerRight.x - UpperLeft.x;
		mdata.height = LowerRight.y - UpperLeft.y;
		data->charact.Initialize(position, check, mdata);
		data->InitialPosition = data->charact.GetPlace();

		//Initialize Animations
		Color bgColor(0, 248, 0);
		AnimationIDs& animationIDs = data->animationIDs;
		Animator& animator = data->animator;
		unsigned int failLeftIDs[] = { IDB_MOUSE_FAILL };
		animationIDs.failL = animator.AddAnimation(InitializeAnimation(failLeftIDs, sizeof(failLeftIDs) / sizeof(int), bgColor));
		unsigned int failRightIDs[] = { IDB_MOUSE_FAILR };
		animationIDs.failR = animator.AddAnimation(InitializeAnimation(failRightIDs, sizeof(failRightIDs) / sizeof(int), bgColor));
		unsigned int fallLIDs[] = { IDB_MOUSE_JUMPL };
		animationIDs.fallL = animator.AddAnimation(InitializeAnimation(fallLIDs, sizeof(fallLIDs) / sizeof(int), bgColor));
		unsigned int fallRIDs[] = { IDB_MOUSE_JUMPR };
		animationIDs.fallR = animator.AddAnimation(InitializeAnimation(fallRIDs, sizeof(fallRIDs) / sizeof(int), bgColor));
		animationIDs.JumpL = animationIDs.fallL;
		animationIDs.JumpR = animationIDs.fallR;
		unsigned int moveLeftIDs[] = { IDB_MOUSE_MOVEL_2, IDB_MOUSE_MOVEL_1, IDB_MOUSE_MOVEL_2, IDB_MOUSE_MOVEL_3 };
		animationIDs.moveL = animator.AddAnimation(InitializeAnimation(moveLeftIDs, sizeof(moveLeftIDs) / sizeof(int), bgColor, 0, 2));
		unsigned int moveRightIDs[] = { IDB_MOUSE_MOVER_2, IDB_MOUSE_MOVER_1, IDB_MOUSE_MOVER_2, IDB_MOUSE_MOVER_3 };
		animationIDs.moveL = animator.AddAnimation(InitializeAnimation(moveRightIDs, sizeof(moveRightIDs) / sizeof(int), bgColor, 0, 2));
		unsigned int standLeftIDs[] = { IDB_MOUSE_STANDL };
		animationIDs.standL = animator.AddAnimation(InitializeAnimation(standLeftIDs, sizeof(standLeftIDs) / sizeof(int), bgColor));
		unsigned int standRightIDs[] = { IDB_MOUSE_STANDR };
		animationIDs.standR = animator.AddAnimation(InitializeAnimation(standRightIDs, sizeof(standRightIDs) / sizeof(int), bgColor));
		//ATLASSERT("NEED IMPLEMENTATION" == "!!!!!!!");

		//Initialize Collider		
		RectangleCollider::Parameters cparam;
		cparam.upperLeft = UpperLeft;
		cparam.lowerRight = LowerRight;
		data->collider = new RectangleCollider(static_cast<int>(CollideGroups::Enemy), cparam);
		data->collider->SetPosition(this->GetPosition());

		//Initialize Ice
		//freeze left
		unsigned int iceLeftIDs[] = { IDB_MOUSE_ICEL };
		Animation iceLeftAnimation = InitializeAnimation(iceLeftIDs, sizeof(iceLeftIDs) / sizeof(unsigned int), bgColor, 0, 2);
		//freeze right
		unsigned int iceRightIDs[] = { IDB_MOUSE_ICER };
		Animation iceRightAnimation = InitializeAnimation(iceRightIDs, sizeof(iceRightIDs) / sizeof(unsigned int), bgColor, 0, 2);

		MovableCharact colliderCharact;
		data->ice = new Ice(iceLeftAnimation, iceRightAnimation, cparam, data->charact, { 32, 32 }, 64);
		data->ice->Disable();
		srand(clock());
		//Initialize State
		//...
		//...
		//...
		//"%%$%*)&)(@#$^)*%!@_&";
		data->facing = Direction::Right;
		if (rand() % 2 == 0)Inverse(data->facing);
		data->ChangeingCountdown = 0;
		data->speedY = 0;
		data->state = MouseData::State::Jumping;
		data->alive = true;
	}
	void Mouse::Update(){
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
			//Changing Delay
			if (data->ChangeingCountdown > 0){ --data->ChangeingCountdown; }
			//Changing
			else if (data->ChangeingCountdown == 0){
				--data->ChangeingCountdown;
				bool canJump = false;
				const Point currentPoint = data->charact.GetPlace();
				for (int i = 0; i < 2; ++i){
					data->charact.SetPlace(currentPoint + Point(0, 32 * i));
					if (data->charact.IsDownTouched()){ canJump = true; break; }
				}
				data->charact.SetPlace(currentPoint);
				//ATLASSERT("Jump" == "JUMP!!!");
				if (canJump && (rand() % ChangeInverseProb + ChangeJumpProb) < ChangeJumpProb){
					data->speedY = SpeedJump;
					data->state = MouseData::State::Jumping;
				}
				else
				{
					Inverse(data->facing);
				}

				//if (IsFaceingLeft()){ data->animator.ChangeAnimation(data->animationIDs.moveL); }
				//else                { data->animator.ChangeAnimation(data->animationIDs.moveR); }
				data->UpdataAnimation();
			}
			//Moving
			else switch (data->state)
			{
				case MouseData::State::Moving:
				{
					bool success;
					if (IsFaceingLeft()){ success = charact.MoveLeft(SpeedX); }
					else                { success = charact.MoveRight(SpeedX); }
					if (!success){ Inverse(data->facing); }

					bool falling = charact.IsDownTouched();
					if (falling){ data->state = MouseData::State::Jumping; data->UpdataAnimation(); }
					else { if (rand() % ChangingProb)data->ChangeingCountdown = ChangingDelay; }
				}break;

				case MouseData::State::Jumping:{
					bool Landing;
					data->speedY += Gravity;
					if (data->speedY > 0){
						if (data->speedY > SpeedJump)data->speedY = SpeedJump;
						Landing = !data->charact.MoveDown(data->speedY);
					}
					else {
						if (data->speedY < -SpeedJump)data->speedY = -SpeedJump;
						Landing = !data->charact.MoveUp(-data->speedY);
					}
					if (Landing){
						data->state = MouseData::State::Moving;
						data->UpdataAnimation();
					}
				}break;
			}

			data->animator.Update();
			collider.SetPosition(this->GetPosition());
			if (collider.IsCollideWith(static_cast<int>(CollideGroups::FlyingIce)))	data->alive = false;
			else if (collider.IsCollideWith(static_cast<int>(CollideGroups::Penguin)))SetIceState(true);
		}//End If Not Ice
	}

	void Mouse::SetIceState(bool b){
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

	bool Mouse::IsIced()const{ return data->ice->IsEnabled(); }

	void Mouse::Paint(){
		if (!IsAlive())return;
		if (IsIced())data->ice->Paint();
		else data->animator.PaintAt(data->charact.GetPlace());
	}
	void Mouse::Reset(){
		data->alive = true;
		data->ice->Disable();
		data->charact.SetPlace(data->InitialPosition);
		data->collider->Enable();
	}
	const Point& Mouse::GetPosition()const{ return data->charact.GetPlace(); }
	void Mouse::SetPosition(const Point& p){ data->charact.SetPlace(p); data->collider->SetPosition(p); }
	bool Mouse::IsAlive()const{ return data->alive; }
	bool Mouse::IsFaceingLeft()const{ return data->facing == Direction::Left; }
};