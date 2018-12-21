#ifndef ECOCO_DE_FIGHT_STAGESTATE_START
#define ECOCO_DE_FIGHT_STAGESTATE_START
#include "IStageState.h"
namespace EcocoDeFight{
	namespace StageState{
		class Start :public IStageState
		{
		public:
			Start();
			Start(const Start&) = delete;
			Start(Start&&) = delete;
			Start& operator=(const Start&) = delete;
			Start& operator=(Start&&) = delete;
			~Start();
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