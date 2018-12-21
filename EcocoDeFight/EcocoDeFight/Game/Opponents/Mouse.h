#ifndef ECOCO_DE_FIGHT_CATERPILLAR_H
#define ECOCO_DE_FIGHT_CATERPILLAR_H

#include "Mob.h"
#include "Point.h"
#include "MovableCharact.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	class Mouse :public Mob
	{
	public:
		Mouse();
		Mouse(const Mouse&) = delete;
		Mouse(Mouse&&);
		Mouse& operator =(const Mouse&) = delete;
		Mouse& operator =(Mouse&&);
		~Mouse();

		void Initialize(const Point& position, const MovableCharact::BlockDirectionCheck&);
		bool IsAlive()const;
		void Update();
		void Paint();
		void Reset();
		const Point& GetPosition()const;
		void SetPosition(const Point&);
	private:
		struct AnimationIDs;
		struct MouseData;
		MouseData* data;
		void SetIceState(bool);
		bool IsIced()const; 
		bool IsFaceingLeft()const;
	};
};

#endif