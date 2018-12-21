#include "stdafx.h"
#include "StageAx.h"
#include "IStage.h"
#include "GameMap.h"
#include "Map.h"
#include "Camera.h"
#include "Collider.h"
#include "Caterpillar.h"
#include "Watermelon.h"
#include "Point.h"
#include "Maps.h"
#include "Enviroment.h"
using namespace EcocoDeFightBase;
using namespace std;

namespace EcocoDeFight{

	StageAx::StageAx() = default;

	StageAx::~StageAx(){ for (Mob* m : mobs)delete m; }

	void StageAx::Initialize(int StageIndex){
		fail = false;

		map.LoadMap(GameA[StageIndex].map, GameA[StageIndex].width, GameA[StageIndex].height);
		map.InitializeWorld(GameMap::GetBitmap, 32, 32, 640, 480);
		MovableCharact::BlockDirectionCheck check;
		check.isBlockDownUp = [](Point pt){return false; };
		check.isBlockLeftRight = [this](Point pt){return GameMap::IsBrick(map.GetMapItemWorld(pt)); };
		check.isBlockRightLeft = [this](Point pt){return GameMap::IsBrick(map.GetMapItemWorld(pt)); };
		check.isBlockUpDown = [this](Point pt){
			int item = map.GetMapItemWorld(pt);
			return (GameMap::IsFloor(item) && (pt.y % 32 == 0)) || (GameMap::IsBrick(item) && item != map.GetMapItemWorld(pt - Point(0, 1))); };
		// ecoco
		ecoco.Initialize(check);
		ecoco.SetPosition(GameA[StageIndex].startPlace);

		//Catepillar
		for (int i = 0; i < GameA[StageIndex].Caterpilars.count; ++i){
			Caterpillar* mob = new Caterpillar();
			mob->Initialize(GameA[StageIndex].Caterpilars.appearPlace[i], check);
			mobs.insert(static_cast<Mob*>(mob));
		}

		//Watermelon
		for (int i = 0; i < GameA[StageIndex].WaterMelons.count; ++i){
			Watermelon* melon = new Watermelon();
			melon->Initialize(GameA[StageIndex].WaterMelons.appearPlace[i], check);
			mobs.insert(static_cast<Mob*>(melon));
		}


		// camera
		Camera::SetCameraBoundary(Point(0, 0), Point(GameA[StageIndex].width * 32 - Enviroment::ScreenWidth, GameA[StageIndex].height * 32 - Enviroment::ScreenHeight));
		Camera::SetCameraPosition(ecoco.GetPosition());
		Camera::SetTargetCameraScreenPoint(Point(Enviroment::ScreenWidth / 2, Enviroment::ScreenHeight / 2));
		Camera::SetTargetMaxOffset(50);
		Camera::StartTrace([this](){return ecoco.GetPosition() + Point(32, 32); });
		Camera::UpdateCamera();
	}

	void StageAx::Update(){
		if (!ecoco.IsAlive())return;
		for (Mob* mob : mobs){ mob->Update(); }
		//Remove All DyingMob
		for (set<Mob*>::iterator it = mobs.begin(); it != mobs.end();){
			if (!(*it)->IsAlive()){
				delete *it;
				it = mobs.erase(it);
			}
			else ++it;
		}
		if (Input::IsActiving(Input::InputType::c)){
			volatile Point pos = ecoco.GetPosition();
			volatile int i = 1;
		}
		ecoco.Update();
		Camera::UpdateCamera();
	}

	void StageAx::Paint(){
		if (!ecoco.IsAlive())return;
		for (Mob* mob : mobs){ mob->Paint(); }
		map.Paint();
		ecoco.Paint();
	}

	void StageAx::RetryLevel(){
		ecoco.Reset();
		for (Mob* mob : mobs){ mob->Reset(); }
		Camera::UpdateCamera();
	}

	bool StageAx::IsEnd(){
		return mobs.size() == 0;
	}

	bool StageAx::IsFail(){
		return !ecoco.IsAlive();
	}
}