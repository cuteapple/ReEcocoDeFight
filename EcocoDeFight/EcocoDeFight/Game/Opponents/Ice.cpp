#include "stdafx.h"
#include "Ice.h"
#include "Enumeration.h"
using namespace std;
using namespace EcocoDeFight;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{

	set<Ice*> Ice::AllIce;
	Ice* Ice::GetIce(const Collider& collider){
		for (Ice* controller : AllIce)
			if (collider.IsCollideWith(*(controller->collider)) && controller->state == State::Stand)
				return controller;
		return nullptr;
	}

	Ice::Ice(const Animation& animationL, const Animation& animationR, const RectangleCollider::Parameters& params, const MovableCharact& iceCharact, const Point& center, int height)
		:animationL(animationL), animationR(animationR), charact(iceCharact), enabled(false), currentAnimation(nullptr), center(center), height(height){
		this->collider = new RectangleCollider(static_cast<int>(CollideGroups::Ice), params);
	}

	Ice::Ice(const Animation& animationL, const Animation& animationR, const CircleCollider::Parameters& params, const MovableCharact& iceCharact, const Point& center, int height)
		: animationL(animationL), animationR(animationR), charact(iceCharact), enabled(false), currentAnimation(nullptr), center(center), height(height){
		this->collider = new CircleCollider(static_cast<int>(CollideGroups::Ice), params);
	}

	void Ice::Enable(Direction dir){
		currentAnimation = dir == Direction::Right ? &animationR : &animationL;
		this->state = State::Stand;
		AllIce.insert(this);
		collider->Enable();
		enabled = true;
	}

	void Ice::Disable(){
		enabled = false;
		collider->Disable();
		AllIce.erase(this);
		currentAnimation = nullptr;
	}

	Ice::~Ice(){
		Disable();
		delete collider;
	}

	bool Ice::IsEnabled()const{ return currentAnimation != nullptr; }
	bool Ice::IsAlive()const{ return state != State::Break; }

	const Point& Ice::GetPosition()const{ return charact.GetPlace(); }
	void Ice::SetPosition(const Point& place){ charact.SetPlace(place); collider->SetPosition(place); }

	void Ice::Paint(){ if (!IsEnabled())return; this->currentAnimation->PaintAt(GetPosition()); }

	void Ice::Fly(Direction direction, int targetY){
		if (this->state != State::Tracing)return;
		this->speed = Ice::Speed*(direction == Direction::Right ? 1 : -1);
		this->offsetY = targetY - GetPosition().y - center.y - height / 2;
		collider->SetGroup(static_cast<int>(CollideGroups::FlyingIce));
		this->state = State::Flying;
	}

	void Ice::PickUp(std::function<EcocoDeFightBase::Point()> traceFunction){
		if (state != State::Stand)return;
		this->tracing = [this, traceFunction](){return traceFunction() - center + Point(Ice::PenguinWidh / 2, -height / 2); };
		this->state = State::Tracing;
		collider->SetGroup(static_cast<int>(CollideGroups::PickedIce));
	}

	void Ice::Update(){
		switch (state)
		{
			case State::Flying:
			{
				bool success;
				int currentOffsetY = static_cast<int>(offsetY*0.6);
				offsetY -= currentOffsetY;
				//X
				if (speed > 0)
					success = charact.MoveRight(speed);
				else
					success = charact.MoveLeft(-speed);
				//Y
				if (currentOffsetY > 0)
					charact.MoveDown(currentOffsetY);
				else
					charact.MoveUp(-currentOffsetY);

				this->collider->SetPosition(charact.GetPlace());
				if (!success) this->state = State::Break;
			}
			break;

			case State::Tracing:
				this->SetPosition(tracing());
				break;

			case State::Stand:
				if (charact.MoveDown(20))
					this->collider->SetPosition(charact.GetPlace());
				if (this->collider->IsCollideWith(static_cast<int>(CollideGroups::FlyingIce)))this->state = State::Break;
		}
	}



}