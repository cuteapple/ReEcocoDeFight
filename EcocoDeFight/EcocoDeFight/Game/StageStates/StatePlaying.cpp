#include "stdafx.h"
#include "StageA.h"
#include "IStage.h"
#include "ScoreBoard.h"
#include "StatePlaying.h"
#include "StateWin.h"
#include "StateLose.h"
#include "BGMPlayer.h"
#include "Background.h"
#include <utility>
using std::move;

namespace EcocoDeFight{
	namespace StageState{
		struct Playing::Data{ StageA* stage; };

		Playing::Playing(){
			BGMPlayer::Play(BGMPlayer::BGM::PLAYING);
			Background::Change(Background::BackgroundType::StageIce);
			ScoreBoard::ResetScore();
			data = new Data;
			StageA*  stage = new StageA();
			stage->Initialize();
			data->stage = stage;
		}
		Playing::~Playing(){
			BGMPlayer::Stop(BGMPlayer::BGM::PLAYING);
			delete data->stage;
			delete data;
		}
		void Playing::Update(){
			data->stage->Update();
		}
		void Playing::Paint(){
			Background::Paint();
			data->stage->Paint();
		}
		bool Playing::IsEnd(){
			return ScoreBoard::Tired() || data->stage->IsFinish();
		}
		IStageState* Playing::NextStage(){
			if (ScoreBoard::Tired()) return new Lose();
			else return new Win();
		}
	}
}