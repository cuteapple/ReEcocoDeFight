#include "stdafx.h"
#include "ControllableCharact.h"
#include <functional>
#include <cstdlib>
using namespace std;

namespace EcocoDeFightBase{

	void ControllableCharact::Initialize(const Point& pt, const ControllableCharactData& conData, const ControllableCharactFunctions& conFunc){
		cdata = static_cast<ControllableCharactDataI>(conData);
		cfunction = static_cast<ControllableCharactFunctionsI>(conFunc);
		charact.Initialize(pt, static_cast<MovableCharact::BlockDirectionCheck>(conFunc), static_cast<MovableCharact::MovableCharactData>(conData));
	}
	void ControllableCharact::Update(){
		bool jump = cfunction.isJump();
		bool moveL = cfunction.isMoveLeft();
		bool moveR = cfunction.isMoveRight();
		bool noAction = !(jump || moveL || moveR);
		bool air = !Landed();
		//bool takebreak = charact.IsDownTouched();
		//Grounded State
		if (!air){
			if (jump){ this->currentVelocityY = -static_cast<int>(cdata.velocityJump); jumpCheck = cdata.jumpStayFrame; jumpCount = 1; }
			if (moveR){ this->currentVelocityX += cdata.accelerateRight; }
			if (moveL){
				this->currentVelocityX -= cdata.accelerateLeft;
			}
			if (noAction){//Decrease And Check Stop
				this->currentVelocityX = static_cast<int>(this->currentVelocityX* cdata.decreaseScalerX);
				if (static_cast<unsigned int>(abs(this->currentVelocityX)) < cdata.StopVelocity)currentVelocityX = 0;
			}
		}
		//Not Grounded
		else{
			if (jumpCount > 0){
				++jumpCount;
				if (jumpCount <= jumpCheck){
					this->currentVelocityY = -static_cast<int>(cdata.velocityJump);
					if (jump && jumpCount == jumpCheck)jumpCheck = cdata.jumpHStayFrame;
				}
				else{
					jumpCount = 0;
				}
			}
			if (moveR){ this->currentVelocityX += cdata.accelerateAirRight; }
			if (moveL){ this->currentVelocityX -= cdata.accelerateAirLeft; }
			this->currentVelocityY += cdata.gravity;
		}
		//Adjust Velocity
		if (static_cast<unsigned int>(abs(this->currentVelocityX)) > cdata.maxXSpeed){
			if (this->currentVelocityX > 0)this->currentVelocityX = cdata.maxXSpeed;
			else if (this->currentVelocityX < 0)this->currentVelocityX = -static_cast<int>(cdata.maxXSpeed);
		}
		if (static_cast<unsigned int>(abs(this->currentVelocityY)) > cdata.maxYSpeed){
			if (this->currentVelocityY > 0)this->currentVelocityY = cdata.maxYSpeed;
			else if (this->currentVelocityY < 0)this->currentVelocityY = -static_cast<int>(cdata.maxYSpeed);
		}
		//Move
		bool Xsuccess;
		bool Ysuccess;
		if (MovingRight()){ Xsuccess = charact.MoveRight(this->currentVelocityX); }
		else if (MovingLeft()){ Xsuccess = charact.MoveLeft(-this->currentVelocityX); }
		if (MovingUp()){ Ysuccess = charact.MoveUp(-this->currentVelocityY); }
		else if (MovingDown()){ Ysuccess = charact.MoveDown(this->currentVelocityY); }
		if (!Xsuccess)this->currentVelocityX = 0;
		if (!Ysuccess)this->currentVelocityY = 0;
	}
	void ControllableCharact::Stop(){ currentVelocityX = 0; currentVelocityY = 0; jumpCheck = 0; jumpCount = 0; }
	const Point& ControllableCharact::GetPlace()const{ return charact.GetPlace(); }
	void ControllableCharact::SetPlace(const Point& pt){ charact.SetPlace(pt); }
	bool ControllableCharact::MovingLeft()const{ return this->currentVelocityX < 0; }
	bool ControllableCharact::MovingRight()const{ return this->currentVelocityX > 0; }
	bool ControllableCharact::MovingUp()const{ return this->currentVelocityY < 0; }
	bool ControllableCharact::MovingDown()const{ return this->currentVelocityY > 0; }
	bool ControllableCharact::Landed()const{ return charact.IsDownTouched() && !MovingUp(); }
}