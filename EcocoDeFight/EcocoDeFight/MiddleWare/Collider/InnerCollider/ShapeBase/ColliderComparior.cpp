#include "stdafx.h"
#include "ColliderShapeBase.h"
#include "RectangleColliderShapeBase.h"
#include "CircleColliderShapeBase.h"
#include "ColliderComparior.h"
#include <utility>
namespace EcocoDeFightBase{
	namespace InnerCollider{

		bool ColliderOverlapChecker::IsOverLapped(const ColliderShapeBase& c1, const ColliderShapeBase& c2){
			switch (c1.GetType())
			{
				case ColliderShapeBase::ColliderType::Rectangle:
					return IsOverLapped_HalfCheck(static_cast<const RectangleColliderShapeBase&>(c1), c2);
				case ColliderShapeBase::ColliderType::Circle:
					return IsOverLapped_HalfCheck(static_cast<const CircleColliderShapeBase&>(c1), c2);
				default:
					return false;
			}
		}

		template <typename SomeCheckedCollider>
		static bool ColliderOverlapChecker::IsOverLapped_HalfCheck(const SomeCheckedCollider& c1, const ColliderShapeBase& c2){
			switch (c2.GetType())
			{
				case ColliderShapeBase::ColliderType::Rectangle:
					return IsOverLapped_FullCheck(c1, static_cast<const RectangleColliderShapeBase&>(c2));
				case ColliderShapeBase::ColliderType::Circle:
					return IsOverLapped_FullCheck(c1, static_cast<const CircleColliderShapeBase&>(c2));
				default:
					return false;
			}
		}

		bool ColliderOverlapChecker::IsOverLapped_FullCheck(const RectangleColliderShapeBase& c1, const RectangleColliderShapeBase& c2){
			auto rect1 = c1.GetParameters();
			auto rect2 = c2.GetParameters();
			return IsOverLappedRange(rect1.upperLeft.x, rect1.lowerRight.x, rect2.upperLeft.x, rect2.lowerRight.x)
				&& IsOverLappedRange(rect1.upperLeft.y, rect1.lowerRight.y, rect2.upperLeft.y, rect2.lowerRight.y);
		}
		bool ColliderOverlapChecker::IsOverLapped_FullCheck(const RectangleColliderShapeBase& rc, const CircleColliderShapeBase& cc){ return IsOverLapped_FullCheck(cc, rc); }
		bool ColliderOverlapChecker::IsOverLapped_FullCheck(const CircleColliderShapeBase & cc, const RectangleColliderShapeBase& rc){
			auto cparam = cc.GetParameters();
			auto rparam = rc.GetParameters();
			// 0  1  2
			// 3  4  5
			// 6  7  8
			static_assert(((int)(true)) == 1, "need reimplement the next statement and make (int)(true) == 1 ");
			int place = (int)(cparam.center.x > rparam.upperLeft.x) + (int)(cparam.center.x > rparam.lowerRight.x) +
				((int)(cparam.center.y > rparam.upperLeft.y) + (int)(cparam.center.y > rparam.lowerRight.y)) * 3;
			unsigned int rr_2 = cparam.radius*cparam.radius;
			switch (place)
			{
				case 0:
					return Point::DistanceSquare(rparam.upperLeft, cparam.center) <= rr_2;
				case 2:
					return Point::DistanceSquare(Point(rparam.lowerRight.x, rparam.upperLeft.y), cparam.center) <= rr_2;
				case 6:
					return Point::DistanceSquare(Point(rparam.upperLeft.x, rparam.lowerRight.y), cparam.center) <= rr_2;
				case 8:
					return Point::DistanceSquare(rparam.lowerRight, cparam.center) <= rr_2;
				case 1:
					return (unsigned int)(rparam.lowerRight.y - cparam.center.y) <= cparam.radius;
				case 3:
					return (unsigned int)(rparam.upperLeft.x - cparam.center.x) <= cparam.radius;
				case 5:
					return (unsigned int)(cparam.center.x - rparam.lowerRight.x) <= cparam.radius;
				case 7:
					return (unsigned int)(cparam.center.y - rparam.upperLeft.y) <= cparam.radius;
				case 4:
					return true;
			}
			return false;
		}
		bool ColliderOverlapChecker::IsOverLapped_FullCheck(const CircleColliderShapeBase& c1, const CircleColliderShapeBase& c2){
			auto param1 = c1.GetParameters();
			auto param2 = c2.GetParameters();
			auto maxDistance = param1.radius + param2.radius;
			return Point::DistanceSquare(param1.center, param2.center) <= maxDistance*maxDistance;
		}

		bool ColliderOverlapChecker::IsOverLappedRange(int beginA, int endA, int beginB, int endB){
			if (endA < beginA)std::swap(beginA, endA);
			if (endB < beginB)std::swap(beginB, endB);

			if (beginA <= beginB){
				return endA >= beginB;
			}
			// endB >= beginA > beginB
			if (beginA <= endB){
				return true;
			}
			// beginA > endB
			return false;
		}
	}
}