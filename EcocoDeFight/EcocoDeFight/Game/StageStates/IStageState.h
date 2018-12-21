#ifndef ECOCO_DE_FIGHT_ISTATE_H
#define ECOCO_DE_FIGHT_ISTATE_H
#include "IStage.h"
namespace EcocoDeFight{
	class IStageState :public IStage
	{
	public:
		virtual ~IStageState() {};
		virtual bool IsEnd() = 0;
		virtual IStageState* NextStage() = 0;
	};
}
#endif