#include "stdafx.h"
#include "Input.h"
namespace EcocoDeFightBase{

	void Input::Active(InputType input){ states[currentState].states[input] = true; }
	void Input::Release(InputType input){ states[currentState].states[input] = false; }
	void Input::NextFrame(){
		lastState = currentState;
		currentState = 1 - currentState;
		states[currentState] = states[lastState];
	}

	bool Input::IsActiving(InputType type){ return states[currentState].states[type] && !states[lastState].states[type]; }
	bool Input::IsReleasing(InputType type){ return !states[currentState].states[type] && states[lastState].states[type]; }
	bool Input::IsActive(InputType type){ return states[currentState].states[type]; }
	bool Input::IsRelease(InputType type){ return !states[currentState].states[type]; }

	Input::InputState Input::states[2];
	int Input::currentState = 0;
	int Input::lastState = 1;
}