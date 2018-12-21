#ifndef ECOCO_DE_FIGHT_STAGESTATE_WIN
#define ECOCO_DE_FIGHT_STAGESTATE_WIN
#include "IStageState.h"
namespace EcocoDeFight{
	namespace StageState{
		class Win :public IStageState
		{
		public:
			Win();
			Win(const Win&) = delete;
			Win(Win&&) = delete;
			Win& operator=(const Win&) = delete;
			Win& operator=(Win&&) = delete;
			~Win();
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