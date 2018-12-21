#include "InnerCollider\ColliderBase.h"
#include "InnerCollider\ColliderTemplate.h"
#include "InnerCollider\ShapeBase\RectangleColliderShapeBase.h"
#include "InnerCollider\ShapeBase\CircleColliderShapeBase.h"

namespace EcocoDeFightBase{
	using namespace InnerCollider;
	using RectangleCollider = ColliderTemplate < RectangleColliderShapeBase >;
	using CircleCollider = ColliderTemplate < CircleColliderShapeBase > ;
}
