#ifndef ECOCO_DE_FIGHT_PENGUINSTATE_BASE_H
#define ECOCO_DE_FIGHT_PENGUINSTATE_BASE_H
#include "Collider.h"
#include "Point.h"
namespace EcocoDeFight{
	class Penguin;
	class PenguinState{
	public:
		PenguinState(Penguin*p) :penguin(p){}
		virtual bool IsRunning()const = 0;
		virtual void Update() = 0;
		virtual void Paint() = 0;
		virtual void Stop() = 0;
		virtual ~PenguinState() = default;
	protected:
		Penguin* penguin;
	};
}
#endif