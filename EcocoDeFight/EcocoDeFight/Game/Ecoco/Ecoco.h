#ifndef ECOCO_DE_FIGHT_ECOCO_H
#define ECOCO_DE_FIGHT_ECOCO_H
#include "Input.h"
#include "Map.h"
#include "Animator.h"
#include "ControllableCharact.h"
#include "Point.h"
#include "Color.h"
#include "Collider.h"
#include "Penguin.h"

namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	class Ecoco
	{
	public:
		Ecoco();
		Ecoco(const Ecoco&) = delete;
		Ecoco(Ecoco&&);
		Ecoco& operator=(const Ecoco&) = delete;
		Ecoco& operator=(Ecoco&&);
		~Ecoco();
		void Initialize(const MovableCharact::BlockDirectionCheck& check);
		void Update();
		void Paint();
		bool IsAlive()const;
		const Point& GetPosition()const;
		void SetPosition(const Point& p);
		void Reset();
	private:
		const static Point UpperLeft;
		const static Point LowerRight;
		const static Color Bgcolor;
		const static Point MoveUpperLeft;

		struct AnimationIDs;
		struct EcocoData;
		EcocoData* data;

		void InitializeEcocoAnimator();
		void InitializeEcocoCharact(MovableCharact::BlockDirectionCheck check);
		void CheckCollision();
	};
}
#endif