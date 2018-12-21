#ifndef ECOCO_DE_FIGHT_BASE_COLLIDER_INTERFACE_H
#define ECOCO_DE_FIGHT_BASE_COLLIDER_INTERFACE_H
#include "ShapeBase\ColliderShapeBase.h"
#include "Point.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		class Collider
		{
		public:
			virtual ~Collider(){}
			virtual bool IsCollideWith(int group)const = 0;
			virtual bool IsCollideWith(const Collider& collider)const = 0;
			virtual void SetGroup(int group) = 0;
			virtual void SetPosition(const Point&) = 0;
			virtual void Enable() = 0;
			virtual void Disable() = 0;
		protected:
			template <typename T> friend class ColliderTemplate;
			virtual const ColliderShapeBase& GetShapeBase()const = 0;
		};
	}
}
#endif