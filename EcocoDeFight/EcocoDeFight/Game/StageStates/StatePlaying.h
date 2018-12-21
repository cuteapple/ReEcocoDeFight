#ifndef ECOCO_DE_FIGHT_STAGESTATE_PLAYING
#define ECOCO_DE_FIGHT_STAGESTATE_PLAYING
#include "IStageState.h"
namespace EcocoDeFight{
	namespace StageState{
		class Playing :public IStageState
		{
		public:
			Playing();
			Playing(const Playing&) = delete;
			Playing(Playing&&) = delete;
			Playing& operator=(const Playing&) = delete;
			Playing& operator=(Playing&&) = delete;
			~Playing();
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