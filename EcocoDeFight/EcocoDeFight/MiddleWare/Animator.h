#ifndef ECOCO_DE_FIGHT_ANIMATOR_H
#define ECOCO_DE_FIGHT_ANIMATOR_H

#include "Point.h"
#include "Animation.h"

namespace EcocoDeFightBase{
	class Animator
	{
	public:
		typedef int AnimationID;
		Animator();
		Animator(const Animator&);
		Animator(Animator&&);
		~Animator();
		AnimationID AddAnimation(const Animation&);
		AnimationID AddAnimation(Animation&&);
		Animator& operator =(const Animator&);
		Animator& operator =(Animator&&);
		void ChangeAnimation(AnimationID id);
		void Update();
		void PaintAt(Point);
	private:
		struct AnimatorData;
		AnimatorData* data;
	};
}

#endif