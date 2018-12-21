#ifndef ECOCO_DE_FIGHT_PENGUINSTATE_TRACING_H
#define ECOCO_DE_FIGHT_PENGUINSTATE_TRACING_H
#include "PenguinState_Base.h"
#include "Animator.h"
#include "Bitmap.h"
#include "Point.h"
#include "MovableCharact.h"
#include <functional>
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	using namespace std;
	class PenguinState_Tracing :public PenguinState{
	public:
		//using PenguinState::PenguinState;
		PenguinState_Tracing(Penguin* p) :PenguinState(p){}
		bool IsRunning()const;
		void Initialize();
		void Start(function<Point()> ecocoPlace, int distance);
		void Update();
		void Paint();
		void Stop();
	private:
		const static int velocityX = 10;
		const static int velocityY = 20;
		int distance;
		function<Point()> ecocoPlace;
		struct {
			Animator::AnimationID FlyL;
			Animator::AnimationID FlyR;
			Animator::AnimationID WalkL;
			Animator::AnimationID WalkR;
			Animator::AnimationID StandL;
			Animator::AnimationID StandR;
			Animator::AnimationID Stand;
			Animator::AnimationID lastID;
		}animationIDs;
		Animator animator;
		MovableCharact charact;
	};
}
#endif