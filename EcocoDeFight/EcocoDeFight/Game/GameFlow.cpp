//this file is the "main" of Ecoco de fight
//this file is drived by GameFlowDriver.cpp
#include "stdafx.h"
#include "GameFlow.h"
//Game File
#include "StageStates\StageState.h"
#include "ScoreBoard.h"
#include "BackGround.h"
#include "BGMPlayer.h"
#include "Cheat.h"
//Game Base File
#include "Enviroment.h"
#include "Input.h"

using namespace EcocoDeFightBase;

namespace EcocoDeFight{
	IStageState* state;
	void GameFlow::Initialize(){
		ScoreBoard::Initialize();
		Background::Initizlize();
		BGMPlayer::Initialize();
		state = new StageState::Start();
	}
	void GameFlow::Update(){
		state->Update();
		if (state->IsEnd()){
			IStageState* nstate = state->NextStage();
			delete state;
			state = nstate;
		}
		if (Input::IsActive(Input::InputType::esc))Enviroment::CloseWindow();
#ifdef CHEAT_ENABLED
		if (Input::IsActive(Input::InputType::lbutton))EcocoDeFightCheat::Cheat::IsEnergyDecrease = false;
		if (Input::IsActive(Input::InputType::rbutton))EcocoDeFightCheat::Cheat::IsEnergyDecrease = true;
#endif
	}
	void GameFlow::Paint(){
		state->Paint();
	}
	void GameFlow::Release(){
		delete state;
		BGMPlayer::Release();
		Background::Release();
		ScoreBoard::Release();
	}
}