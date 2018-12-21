#ifndef ECOCO_DE_FIGHT_GAMEFLOWDRIVER_H
#define ECOCO_DE_FIGHT_GAMEFLOWDRIVER_H

#include "Point.h"

namespace EcocoDeFightBase{
	class GameFlowDriver
	{
	public:
		enum class ButtonEvent{ Down, Up };
		enum class MouseButton{ Left, Right };
		typedef unsigned int KeyCode;
		~GameFlowDriver();
		void Initialize();
		void Update();
		void Paint();
		void MouseEvent(MouseButton, ButtonEvent, Point);
		void KeyBoardEvent(KeyCode, ButtonEvent);
	};
}
#endif