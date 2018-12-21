#include "stdafx.h"
#include "ColliderBase.h"
#include <map>
#include <set>
#include "ColliderTemplate.h"
namespace EcocoDeFightBase{
	namespace InnerCollider{
		std::map<int, std::set<Collider*>> ColliderContainer::AllColliders;
	}
}