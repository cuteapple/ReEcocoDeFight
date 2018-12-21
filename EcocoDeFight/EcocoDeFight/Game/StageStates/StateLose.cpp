#include "stdafx.h"
#include "StateLose.h"
#include "StateStart.h"
#include "Input.h"
#include "Background.h"
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	namespace StageState{
		struct Lose::Data{ int delay;  bool end; };

		Lose::Lose(){
			Background::Change(Background::BackgroundType::EcocoLose);
			data = new Data;
			data->end = false;
			data->delay = 30;
		}
		Lose::~Lose(){
			delete data;
		}
		void Lose::Update(){
			if (data->delay > 0)--data->delay;
			else if (Input::IsActiving(Input::InputType::z))data->end = true;
		}
		void Lose::Paint(){
			Background::Paint();
		}
		bool Lose::IsEnd(){
			return data->end;
		}
		IStageState* Lose::NextStage(){
			return new Start();
		}
	}
}