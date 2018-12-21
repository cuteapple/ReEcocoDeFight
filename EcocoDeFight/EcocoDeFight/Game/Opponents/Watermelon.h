#ifndef ECOCO_DE_FIGHT_WATERMELON_H
#define ECOCO_DE_FIGHT_WATERMELON_H
#include "Point.h"
#include "MovableCharact.h"
#include "Mob.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	class Watermelon :public Mob
	{
	public:
		Watermelon();
		Watermelon(const Watermelon&) = delete;
		Watermelon(Watermelon&&);
		Watermelon& operator =(const Watermelon&) = delete;
		Watermelon& operator =(Watermelon&&);
		~Watermelon();

		void Initialize(const Point& position, const MovableCharact::BlockDirectionCheck&);
		bool IsAlive()const;
		void Update();
		void Paint();
		void Reset();
		const Point& GetPosition()const;
		void SetPosition(const Point&);
	private:

		struct AnimationIDs;
		struct WaterMelonData;
		WaterMelonData* data;
		enum class State{ Air, Landing };

		void SetIceState(bool);
		bool IsIced()const;
		bool IsFaceingLeft()const;

		const static Point Center;//32,32
		const static int Radius = 32;
		const static int SpeedX = 3;
		const static int SpeedJump = 17;
		const static int Accelerate = 1;
	};
};

#endif