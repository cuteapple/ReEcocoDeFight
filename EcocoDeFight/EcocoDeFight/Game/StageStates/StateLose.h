#ifndef ECOCO_DE_FIGHT_STAGESTATE_LOSE
#define ECOCO_DE_FIGHT_STAGESTATE_LOSE
#include "IStageState.h"
namespace EcocoDeFight{
	namespace StageState{
		class Lose :public IStageState
		{
		public:
			Lose();
			Lose(const Lose&) = delete;
			Lose(Lose&&) = delete;
			Lose& operator=(const Lose&) = delete;
			Lose& operator=(Lose&&) = delete;
			~Lose();
			void Update();
			void Paint();
			bool IsEnd();
			IStageState* NextStage();
		private:
			struct Data;
			Data* data;
		};
	}
}
#endif