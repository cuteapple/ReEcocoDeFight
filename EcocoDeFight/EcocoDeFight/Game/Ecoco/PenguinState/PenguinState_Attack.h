#ifndef ECOCO_DE_FIGHT_PENGUINSTATE_ATTACK_H
#define ECOCO_DE_FIGHT_PENGUINSTATE_ATTACK_H
#include "PenguinState_Base.h"
#include "Collider.h"
#include "Bitmap.h"
#include "Enumeration.h"
namespace EcocoDeFight{
	class Penguin;
	using namespace EcocoDeFightBase;
	class PenguinState_Attack :public PenguinState{
	public:
		PenguinState_Attack(Penguin* p);
		~PenguinState_Attack() = default;
		void Initialize();
		void Start(Direction dir, int targetY);
		bool IsRunning()const;
		void Update();
		void Stop();
		void Paint();
	private:
		const static int velocity = 40;
		const static int duration = 5;
		bool finalState = true;
		bool active = false;
		int currentFrame = duration;
		int currentSpeed;
		int currentTargetY;
		Bitmap BmpAttackL;
		Bitmap BmpAttackR;
		RectangleCollider collider;
	};
}
#endif