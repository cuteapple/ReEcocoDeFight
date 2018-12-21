#include "stdafx.h"
#include "ScoreBoard.h"
#include "Bitmap.h"
#include "EcoPicEx.h"
#include "Enviroment.h"
#include "Cheat.h"
using namespace std;
using namespace EcocoDeFightBase;

namespace EcocoDeFight{
	static const int Gap = 2;

	struct ScoreBoard::Score{
		int ecoco;
	};
	struct ScoreBoard::Data{
		Bitmap ecocoIcon;
		Bitmap digits[10];
	};


	ScoreBoard::Score* ScoreBoard::score;
	ScoreBoard::Data* ScoreBoard::data;

	static const int POW10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	//place : 1 based digit number
	//value : value to get digit
	inline static int GetDigit(int place, int value){ return value%POW10[place] - value%POW10[place - 1]; }

	void ScoreBoard::Initialize(){
		//ResetScore();

		static bool initialized = false;
		if (initialized)return;
		initialized = true;

		score = new Score;
		data = new Data;

		Color bgColor(0, 120, 0);

		for (int i = 0; i < 10; ++i){
			data->digits[i].Load(IDB_TEXT_SMALL_0 + i, bgColor);
		}
		data->ecocoIcon.Load(IDB_ICON_PENGUIN, bgColor);
		ResetScore();
	}
	void ScoreBoard::ResetScore(){
		score->ecoco = 4;
	}
	bool ScoreBoard::FailOnce(){
#ifdef CHEAT_ENABLED
		if (!EcocoDeFightCheat::Cheat::IsEnergyDecrease)return !Tired();
#endif
		if (score->ecoco > 0){
			--score->ecoco;
			return true;
		}
		else{
			return false;
		}
	}
	bool ScoreBoard::Tired(){
		return !(score->ecoco > 0);
	}
	void ScoreBoard::Draw(){
		Point energyP(Gap, Enviroment::ScreenHeight - TEXT_SMALL_HEIGHT - Gap);
		data->ecocoIcon.PaintAt(energyP, false);
		energyP.x += TEXT_SMALL_WIDTH + TEXT_SMALL_WIDTH / 2;
		data->digits[GetDigit(2, score->ecoco)].PaintAt(energyP, false);
		energyP.x += TEXT_SMALL_WIDTH;
		data->digits[GetDigit(1, score->ecoco)].PaintAt(energyP, false);
	}
	void ScoreBoard::Release(){
		delete data;
		delete score;
	}
}