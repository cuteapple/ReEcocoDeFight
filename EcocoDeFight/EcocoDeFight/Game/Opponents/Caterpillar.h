#ifndef ECOCO_DE_FIGHT_CATERPILLAR_H
#define ECOCO_DE_FIGHT_CATERPILLAR_H

#include "Mob.h"
#include "Point.h"
#include "MovableCharact.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	class Caterpillar :public Mob
	{
	public:
		Caterpillar();
		Caterpillar(const Caterpillar&) = delete;
		Caterpillar(Caterpillar&&);
		Caterpillar& operator =(const Caterpillar&) = delete;
		Caterpillar& operator =(Caterpillar&&);
		~Caterpillar();

		void Initialize(const Point& position, const MovableCharact::BlockDirectionCheck&);
		bool IsAlive()const;
		void Update();
		void Paint();
		void Reset();
		const Point& GetPosition()const;
		void SetPosition(const Point&);
	private:
		struct AnimationIDs;
		struct CaterpillarData;
		CaterpillarData* data;
		void SetIceState(bool);
		bool IsIced()const;
		bool IsFaceingLeft()const;
		const static int HurtWidth = 52;
		const static int HurtHeight = 32;
		const static Point HurtOffset;
		const static int Speed = 2;
	};
};

#endif