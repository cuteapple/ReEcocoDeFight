#include "stdafx.h"
#include "RectangleColliderShapeBase.h"

namespace EcocoDeFightBase{
	namespace InnerCollider{
		void RectangleColliderShapeBase::Set(const Parameters& params){ this->params = params; }

		const RectangleColliderShapeBase::Parameters& RectangleColliderShapeBase::GetParameters()const{ return params; }

		void RectangleColliderShapeBase::Move(const Point& point){
			params.upperLeft += point;
			params.lowerRight += point;
		}

		RectangleColliderShapeBase::ColliderType RectangleColliderShapeBase::GetType()const{ return Type; }
		const ColliderShapeBase::ColliderType RectangleColliderShapeBase::Type = ColliderType::Rectangle;
	}
}