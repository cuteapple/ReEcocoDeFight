#ifndef ECOCO_DE_FIGHT_PENGUIN_H
#define ECOCO_DE_FIGHT_PENGUIN_H

#include "Point.h"
#include "Collider.h"
#include "Enumeration.h"

#include <functional>
#include <memory>

namespace EcocoDeFight{
	using namespace std;
	using namespace EcocoDeFightBase;
	class Ice;
	class PenguinState;
	class Penguin{
	public:
		Penguin();
		~Penguin();
		void Initialize(std::function<Point()> placeGetter);
		void Attack(Direction direction);
		void Update();
		void Paint();
		bool HoldIce(Ice*);
		bool IsHoldingIce()const;
		const Point& GetPlace()const;
		void SetPlace(const Point&);
		void Reset();
	private:
		std::function<Point()> placeGetter;
		Ice* ice;
		PenguinState* stateCurrent;
		struct State;
		State* states;
		Point place;
	};
}
#endif