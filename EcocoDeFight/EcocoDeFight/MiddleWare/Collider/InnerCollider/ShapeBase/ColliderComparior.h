#ifndef ECOCO_DE_FIGHT_COLLIDER_COMPARIOR_H
#define ECOCO_DE_FIGHT_COLLIDER_COMPARIOR_H
#include "Point.h"
#include "ColliderShapeBase.h"
#include "RectangleColliderShapeBase.h"
#include "CircleColliderShapeBase.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		class ColliderOverlapChecker{
		public:
			static bool IsOverLapped(const ColliderShapeBase& c1, const ColliderShapeBase& c2);
		private:
			template <typename SomeCheckedCollider>
			static bool IsOverLapped_HalfCheck(const SomeCheckedCollider& c1, const ColliderShapeBase& c2);

			static bool IsOverLapped_FullCheck(const RectangleColliderShapeBase&, const RectangleColliderShapeBase&);
			static bool IsOverLapped_FullCheck(const RectangleColliderShapeBase&, const CircleColliderShapeBase&);
			static bool IsOverLapped_FullCheck(const CircleColliderShapeBase&, const RectangleColliderShapeBase&);
			static bool IsOverLapped_FullCheck(const CircleColliderShapeBase&, const CircleColliderShapeBase&);
			//If Two Range Is Overlapped
			static bool IsOverLappedRange(int beginA, int endA, int beginB, int endB);
		};
	}
}
#endif