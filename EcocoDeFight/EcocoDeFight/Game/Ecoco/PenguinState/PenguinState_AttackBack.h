#ifndef ECOCO_DE_FIGHT_PENGUINSTATE_ATTACKBACK_H
#define ECOCO_DE_FIGHT_PENGUINSTATE_ATTACKBACK_H
#include "PenguinState_Base.h"
#include "Bitmap.h"
#include "Point.h"
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	class PenguinState_AttackBack :public PenguinState{
	public:
		//using PenguinState::PenguinState;
		PenguinState_AttackBack(Penguin* p) :PenguinState(p){}
		void Initialize();
		bool IsRunning()const;
		void Start(int targetX);
		void Update();
		void Stop();
		void Paint();
	private:
		const static int duration1 = 3;
		const static int duration2 = 3;
		const static int duration = duration1 + duration2;
		const static int velocityY = 20;
		int currentFrame;
		Point currentSpeed;
		Bitmap BmpLeft;
		Bitmap BmpRight;
	};
}
#endif