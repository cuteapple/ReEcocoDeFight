#ifndef ECOCO_DE_FIGHT_CIRCLECOLLIDER_SHAPE_BASE_H
#define ECOCO_DE_FIGHT_CIRCLECOLLIDER_SHAPE_BASE_H

#include "Point.h"
#include "ColliderShapeBase.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		class CircleColliderShapeBase :public ColliderShapeBase
		{
		public:
			struct Parameters{
				Point center;
				unsigned int radius;
			};
			void Set(const Parameters& params);
			void Move(const Point& point);
			const Parameters& GetParameters()const;
			ColliderType GetType()const;
			const static ColliderShapeBase::ColliderType Type;
		private:
			Parameters params;
		};
	}
};
#endif