#include "stdafx.h"
#include "StageA.h"
#include "GameMap.h"
#include "Point.h"
#include "Maps.h"
#include "ScoreBoard.h"

using namespace EcocoDeFightBase;
using namespace std;

namespace EcocoDeFight{

	StageA::StageA() :maxStageIndex(GameACount - 1), currentStageIndex(0), currentStage(nullptr){}
	StageA::~StageA(){ delete currentStage; }
	void StageA::Initialize(){
		ScoreBoard::ResetScore();
		// maps and map
		GameMap::LoadBitmaps();
		stageIn.Initialize();
		currentStageIndex = 0;
		end = false;
		NextLevel();
	}

	void StageA::NextLevel(){
		if (currentStageIndex > maxStageIndex){ end = true; return; }
		delete currentStage;
		currentStage = new StageAx();
		currentStage->Initialize(currentStageIndex++);
		stageIn.Play(currentStageIndex);
	}

	void StageA::Update(){
		if (!stageIn.IsEnd()){
			stageIn.Update();
		}
		else{
			currentStage->Update();
			if (currentStage->IsEnd()){
				NextLevel();
			}
			if (currentStage->IsFail()){
				ScoreBoard::FailOnce();
				stageIn.Play(currentStageIndex);
				if (!ScoreBoard::Tired())currentStage->RetryLevel();
				else end = true;
			}
		}
	}

	void StageA::Paint(){
		currentStage->Paint();
		stageIn.Paint();
		ScoreBoard::Draw();
	}

	bool StageA::IsFinish(){
		return end && !ScoreBoard::Tired();
	}
}