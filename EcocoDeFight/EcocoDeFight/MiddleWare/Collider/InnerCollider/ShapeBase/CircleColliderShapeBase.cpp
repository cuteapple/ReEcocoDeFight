#include "stdafx.h"
#include "CircleColliderShapeBase.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		void CircleColliderShapeBase::Set(const Parameters& params){ this->params = params; }

		const CircleColliderShapeBase::Parameters& CircleColliderShapeBase::GetParameters()const{ return params; }

		void CircleColliderShapeBase::Move(const Point& point){
			params.center += point;
		}

		ColliderShapeBase::ColliderType CircleColliderShapeBase::GetType()const{ return Type; }
		const ColliderShapeBase::ColliderType CircleColliderShapeBase::Type = ColliderType::Circle;
	}
}