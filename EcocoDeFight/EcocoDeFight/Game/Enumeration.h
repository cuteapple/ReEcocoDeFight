#ifndef ECOCO_DE_FIGHT_CONSTANT_H
#define ECOCO_DE_FIGHT_CONSTANT_H
namespace EcocoDeFight{
	enum class CollideGroups
	{
		Default,
		Charact,
		Enemy,
		Ice,
		PickedIce,
		FlyingIce,
		Fire,
		Penguin
	};
	enum class Direction
	{
		Right = 0,
		Left = 1
	};
	inline void Inverse(Direction& dir){
		dir = static_cast<Direction>(1 - static_cast<int>(dir));
	}
};
#endif