#include "stdafx.h"
#include "Penguin.h"
#include "Enumeration.h"
#include "PenguinState.h"
#include "Ice.h"
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	struct Penguin::State
	{
		State(Penguin* p) : Attack(p), AttackBack(p), Tracing(p){}
		void Initialize(){
			Attack.Initialize();
			AttackBack.Initialize();
			Tracing.Initialize();
		}
		PenguinState_Attack Attack;
		PenguinState_AttackBack AttackBack;
		PenguinState_Tracing Tracing;
	};

	Penguin::Penguin() :stateCurrent(nullptr), placeGetter(nullptr), ice(nullptr), place(0, 0){
		states = new State(this);
	}

	Penguin::~Penguin(){ delete states; }
	void Penguin::Initialize(function<Point(void)> getter){
		placeGetter = getter;
		states->Initialize();
		stateCurrent = &states->Tracing;
		this->Reset();
	}
	void Penguin::Attack(Direction direction){
		if (stateCurrent != static_cast<PenguinState*>(&states->Tracing))return;
		if (IsHoldingIce()){
			ice->Fly(direction, placeGetter().y+5);
			ice = nullptr;
		}
		else // Not Holding Ice, Do A Direct Attack
		{
			states->Attack.Start(direction, placeGetter().y);
			stateCurrent->Stop();
			stateCurrent = &states->Attack;
		}
	}
	void Penguin::Reset(){
		stateCurrent->Stop();
		states->Tracing.Start(placeGetter, 200);
		this->stateCurrent = &states->Tracing;
		this->ice = nullptr;
	}
	void Penguin::Paint(){ stateCurrent->Paint(); }
	void Penguin::Update(){
		if (stateCurrent == nullptr)return;
		stateCurrent->Update();
		if (!stateCurrent->IsRunning()){
			if (stateCurrent == static_cast<PenguinState*>(&states->Attack)){
				states->AttackBack.Start(placeGetter().x);
				stateCurrent = &states->AttackBack;
			}
			else if (stateCurrent == static_cast<PenguinState*>(&states->AttackBack)){
				states->Tracing.Start(placeGetter, 200);
				stateCurrent = &states->Tracing;
			}
			else /*if (stateCurrent == static_cast<PenguinState*>(&states->Tracing))*/{
				ATLASSERT("NOTIMPLEMENT" == "!!!" && "Maybe New State Added?");
			}
		}
	}


	bool Penguin::HoldIce(Ice* ice){
		if (IsHoldingIce())return false;
		this->ice = ice;
		ice->PickUp([this](){return place; });
		return true;
	}
	bool Penguin::IsHoldingIce()const{ return ice != nullptr; }
	const Point& Penguin::GetPlace()const{ return place; }
	void Penguin::SetPlace(const Point& p){ place = p; }
}