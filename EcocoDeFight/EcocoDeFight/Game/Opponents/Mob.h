#ifndef ECOCO_DE_FIGHT_IMOB_H
#define ECOCO_DE_FIGHT_IMOB_H
#include "Point.h"
namespace EcocoDeFight{
	using EcocoDeFightBase::Point;
	class Mob{
	public:
		virtual ~Mob(){}
		virtual bool IsAlive()const = 0;
		virtual void Update() = 0;
		virtual void Paint() = 0;
		virtual void Reset() = 0;
		virtual const Point& GetPosition()const = 0;
		virtual void SetPosition(const Point&) = 0;
	};
	class IcedMob :public Mob{
	public:
		void Reset(){}
	};
};
#endif