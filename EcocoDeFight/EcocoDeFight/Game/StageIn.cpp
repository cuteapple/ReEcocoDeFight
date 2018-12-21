#include "stdafx.h"
#include "StageIn.h"
#include "Bitmap.h"
#include "EcoPicEx.h"
#include "Color.h"
#include "Enviroment.h"
using namespace std;
using namespace EcocoDeFightBase;

namespace EcocoDeFight{
	static const int StageTextWidth = TEXT_STAGE_WIDTH + 2 * TEXT_DIGIT_WIDTH;

	static const int StageTextX = (Enviroment::ScreenWidth - StageTextWidth) / 2;
	//static const int StageTextUpY = 0 - TEXT_HEIGHT;

	static const int StageTextEndY = Enviroment::ScreenHeight + TEXT_HEIGHT;

	static const int StageTextVelocity = -18;
	static const int StageTextIdealMiddleY = (Enviroment::ScreenHeight - TEXT_HEIGHT) / 2;
	static const int StageTextPauseStartFrame = (StageTextIdealMiddleY - StageTextEndY) / StageTextVelocity + 2;
	static const int StageTextPauseEndFrame = StageTextPauseStartFrame + 16;

	struct StageIn::StageInBitmaps
	{
		Bitmap Number[10];
		Bitmap Stage;
		Bitmap UsingBitmap;
		Bitmap* digit[2];

		Point position;
		bool active = false;
		int frame;
	};
	StageIn::StageIn() :data(make_unique<StageIn::StageInBitmaps>()){}
	StageIn::~StageIn() = default;
	void StageIn::Initialize(){
		Color bgColor(0, 248, 0);
		data->Number[0].Load(IDB_TEXT_0, bgColor);
		data->Number[1].Load(IDB_TEXT_1, bgColor);
		data->Number[2].Load(IDB_TEXT_2, bgColor);
		data->Number[3].Load(IDB_TEXT_3, bgColor);
		data->Number[4].Load(IDB_TEXT_4, bgColor);
		data->Number[5].Load(IDB_TEXT_5, bgColor);
		data->Number[6].Load(IDB_TEXT_6, bgColor);
		data->Number[7].Load(IDB_TEXT_7, bgColor);
		data->Number[8].Load(IDB_TEXT_8, bgColor);
		data->Number[9].Load(IDB_TEXT_9, bgColor);
		data->Stage.Load(IDB_TEXT_STAGE, bgColor);
	}
	void StageIn::Play(int number){
		data->digit[1] = &data->Number[number / 10];
		data->digit[0] = &data->Number[number % 10];
		data->active = true;
		data->frame = 0;
		data->position = Point(StageTextX, StageTextEndY);
	}
	bool StageIn::IsEnd(){ return !data->active; }
	void StageIn::Update(){
		if (!data->active)return;
		++data->frame;
		if (data->frame < StageTextPauseStartFrame){ data->position.y += StageTextVelocity; }
		else if (data->frame < StageTextPauseEndFrame){/*Do No Move*/ }
		else{ data->active = false; }
	}
	void StageIn::Paint(){
		if (!data->active)return;
		data->Stage.PaintAt(data->position, false);
		data->digit[1]->PaintAt(data->position + Point(TEXT_STAGE_WIDTH, 0), false);
		data->digit[0]->PaintAt(data->position + Point(TEXT_STAGE_WIDTH + TEXT_DIGIT_WIDTH, 0), false);
	}
}