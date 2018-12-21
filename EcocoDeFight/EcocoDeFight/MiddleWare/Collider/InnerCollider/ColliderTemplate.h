#ifndef ECOCO_DE_FIGHT_COLLIDER_H
#define ECOCO_DE_FIGHT_COLLIDER_H
#include "ColliderBase.h"
#include "ShapeBase\ColliderShapeBase.h"
#include "ShapeBase\ColliderComparior.h"
#include "Point.h"
#include <map>
#include <set>
namespace EcocoDeFightBase{
	namespace InnerCollider{
		class ColliderContainer{
		protected:
			static std::map<int, std::set<Collider*>> AllColliders;
		};

		template <typename ColliderShape>
		class ColliderTemplate :public Collider, public ColliderContainer
		{
		public:
			using Parameters = typename ColliderShape::Parameters;
			ColliderTemplate(int group, const Parameters& param, bool enable = true) :lastPosition(0, 0){
				base.Set(param);
				this->group = group;
				if (enable)Enable();
			}
			~ColliderTemplate(){ AllColliders[group].erase(this); }
			bool IsCollideWith(int group)const{
				auto groupColliders = AllColliders.find(group);
				if (groupColliders == AllColliders.end())return false;
				for (Collider* collider : groupColliders->second){
					if (IsCollideWith(*collider) && collider != this)return true;
				}
				return false;
			}
			inline bool IsCollideWith(const Collider& collider)const{
				return ColliderOverlapChecker::IsOverLapped(this->base, collider.GetShapeBase());
			}
			void SetGroup(int newgroup){
				AllColliders[this->group].erase(this);
				AllColliders[newgroup].insert(this);
				this->group = newgroup;
			}
			void SetPosition(const Point& position){
				//Point offset = position - lastPosition;
				//base.Move(offset);//why inline cause error (position change!!!)
				base.Move(position - lastPosition);
				lastPosition = position;
			}
			void Enable(){ AllColliders[this->group].insert(this); }
			void Disable(){ AllColliders[this->group].erase(this); }
		private:
			Point lastPosition;
			inline const ColliderShapeBase& GetShapeBase()const{ return base; }
			int group;
			ColliderShape base;
		};
	}
}
#endif