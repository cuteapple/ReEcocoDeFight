#ifndef ECOCO_DE_FIGHT_CONTROLLABLECHARACT_H
#define ECOCO_DE_FIGHT_CONTROLLABLECHARACT_H

#include "Point.h"
#include "MovableCharact.h"
#include <functional>

namespace EcocoDeFightBase{
	using std::function;

	class ControllableCharact
	{
	private:
		struct ControllableCharactDataI{
			unsigned int accelerateRight;
			unsigned int accelerateLeft;
			unsigned int accelerateAirRight;
			unsigned int accelerateAirLeft;
			unsigned int velocityJump;
			unsigned int jumpStayFrame;
			unsigned int jumpHStayFrame;
			unsigned int gravity;
			unsigned int maxXSpeed;
			unsigned int maxYSpeed;
			double decreaseScalerX;
			unsigned int StopVelocity;
		};
		struct ControllableCharactFunctionsI
		{
			function<bool()> isMoveLeft;
			function<bool()> isMoveRight;
			function<bool()> isJump;
		};

	public:
		struct ControllableCharactData :ControllableCharactDataI, MovableCharact::MovableCharactData{};
		struct ControllableCharactFunctions :ControllableCharactFunctionsI, MovableCharact::BlockDirectionCheck{};
		void Initialize(const Point&, const ControllableCharactData&, const ControllableCharactFunctions&);
		void Update();
		void Stop();
		const Point& GetPlace()const;
		void SetPlace(const Point&);
		bool MovingLeft()const;
		bool MovingRight()const;
		bool MovingUp()const;
		bool MovingDown()const;
		bool Landed()const;
	private:
		ControllableCharactDataI cdata;
		ControllableCharactFunctionsI cfunction;
		int currentVelocityX = 0;
		int currentVelocityY = 0;
		int jumpCheck = 0;
		int jumpCount = 0;
		MovableCharact charact;
	};
}

#endif