#ifndef ECOCO_DE_FIGHT_STAGEA_H
#define ECOCO_DE_FIGHT_STAGEA_H
#include "IStage.h"
#include "StageAx.h"
#include "StageIn.h"
namespace EcocoDeFight{
	using namespace std;
	class StageA :public IStage{
	public:
		StageA();
		~StageA();
		void Initialize();
		void Update();
		void Paint();
		bool IsFinish();
	private:
		void NextLevel();
		const int maxStageIndex = 0;
		int currentStageIndex = 0;
		StageAx* currentStage;
		StageIn stageIn;
		bool end;
	};
}
#endif