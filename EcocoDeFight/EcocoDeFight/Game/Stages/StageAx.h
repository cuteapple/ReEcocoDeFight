#ifndef ECOCO_DE_FIGHT_STAGEAX_H
#define ECOCO_DE_FIGHT_STAGEAX_H

#include "Ecoco.h"
#include "StageXx.h"
#include "Mob.h"
#include <list>
#include <set>
namespace EcocoDeFight{
	class StageAx : public StageXx
	{
	public:
		StageAx();
		void Initialize(int stageIndex);
		void Update();
		void Paint();
		bool IsEnd();
		bool IsFail();
		void RetryLevel();
		~StageAx();
	private:
		bool fail;
		Ecoco ecoco;
		Map map;
		set<Mob*> mobs;
	};
}
#endif