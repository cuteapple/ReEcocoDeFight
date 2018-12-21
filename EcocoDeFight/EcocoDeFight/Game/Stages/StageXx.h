#ifndef ECOCO_DE_FIGHT_STAGEXX_H
#define ECOCO_DE_FIGHT_STAGEXX_H
#include "IStage.h"
namespace EcocoDeFight{
	class StageXx : public IStage
	{
	public:
		virtual bool IsEnd() = 0;
		virtual void RetryLevel() = 0;
		virtual ~StageXx(){}
	};
}
#endif