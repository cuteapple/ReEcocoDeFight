#include "stdafx.h"
#include "StateStart.h"
#include "StatePlaying.h"
#include "Input.h"
#include "Background.h"
#include "BGMPlayer.h"
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	namespace StageState{
		struct Start::Data{ int delay; bool end; };

		Start::Start(){
			Background::Change(Background::BackgroundType::EcocoStart);
			BGMPlayer::Play(BGMPlayer::BGM::TITLE);
			data = new Data;
			data->end = false;
			data->delay = 30;
		}
		Start::~Start(){
			BGMPlayer::Stop(BGMPlayer::BGM::TITLE);
			delete data;
		}
		void Start::Update(){
			if (data->delay > 0)--data->delay;
			else if (Input::IsActiving(Input::InputType::z))data->end = true;
		}
		void Start::Paint(){
			Background::Paint();
		}
		bool Start::IsEnd(){
			return data->end;
		}
		IStageState* Start::NextStage(){
			return new Playing();
		}
	}
}