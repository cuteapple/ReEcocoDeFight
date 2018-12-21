#include "stdafx.h"
#include "StateWin.h"
#include "StateStart.h"
#include "Input.h"
#include "Background.h"
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	namespace StageState{
		struct Win::Data{ int delay;  bool end; };

		Win::Win(){
			Background::Change(Background::BackgroundType::EcocoWin);
			data = new Data;
			data->end = false;
			data->delay = 30;
		}
		Win::~Win(){
			delete data;
		}
		void Win::Update(){
			if (data->delay > 0)--data->delay;
			else if (Input::IsActiving(Input::InputType::z))data->end = true;
		}
		void Win::Paint(){
			Background::Paint();
		}
		bool Win::IsEnd(){
			return data->end;
		}
		IStageState* Win::NextStage(){
			return new Start();
		}
	}
}