#ifndef ECOCO_DE_FIGHT_ICE_H
#define ECOCO_DE_FIGHT_ICE_H
#include "Mob.h"
#include "Point.h"
#include "Collider.h"
#include "Animation.h"
#include "MovableCharact.h"
#include "Enumeration.h"
#include <functional>
#include <list>
#include <set>
namespace EcocoDeFight{
	using namespace EcocoDeFightBase;
	using namespace std;

	class Ice :public IcedMob
	{
	public:
		Ice(const Animation& animationL, const Animation& animationR, const RectangleCollider::Parameters& colliderParams, const MovableCharact& iceCharact, const Point& center, int height);
		Ice(const Animation& animationL, const Animation& animationR, const CircleCollider::Parameters& colliderParams, const MovableCharact& iceCharact, const Point& center, int height);
		Ice(const Ice&) = delete;
		Ice& operator=(const Ice&) = delete;
		~Ice();

		//place : the collider that overlapped with this collider
		static Ice* GetIce(const Collider& place);

		void PickUp(std::function<EcocoDeFightBase::Point()> tracingFunction);
		void Fly(Direction direction, int targetY);
		void Update();
		void Paint();

		void Enable(Direction direction);
		void Disable();
		bool IsEnabled()const;
		bool IsAlive()const;

		const Point& GetPosition()const;
		void SetPosition(const Point& place);
	private:
		static const int Speed = 20;
		static const int PenguinHeight = 32;
		static const int PenguinWidh = 32;
		int height;
		std::function<Point()> tracing;

		Collider* collider;
		Animation animationL;
		Animation animationR;
		Animation* currentAnimation;
		MovableCharact charact;
		Point center;

		bool enabled;
		int speed;
		int offsetY;
		enum class State{ Flying, Stand, Tracing, Break }state;

		static std::set<Ice*> AllIce;
	};
}
#endif