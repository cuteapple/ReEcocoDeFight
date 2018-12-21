#ifndef ECOCO_DE_FIGHT_COLLIDER_SHAPE_BASE_H
#define ECOCO_DE_FIGHT_COLLIDER_SHAPE_BASE_H
#include "Point.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		class ColliderShapeBase
		{
		public:
			enum class ColliderType{ Rectangle = 0, Circle = 1 };
			virtual ColliderType GetType()const = 0;
			virtual void Move(const Point&) = 0;
			virtual ~ColliderShapeBase(){};
		};
	}
}

#endif