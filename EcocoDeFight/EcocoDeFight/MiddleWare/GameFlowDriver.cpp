//this file is the "main" of Ecoco de fight base
//this file is drived by game_framework
//this file dive the EcocoDeFight::GameFlow

#include "stdafx.h"
#include "GameFlow.h"
#include "GameFlowDriver.h"
#include "Input.h"
using namespace EcocoDeFight;

namespace EcocoDeFightBase{
	static GameFlow flow;
	static Input input;
	void GameFlowDriver::Initialize(){
		flow.Initialize();
	}
	void GameFlowDriver::Update(){
		flow.Update();
		Input::NextFrame();
	}
	void GameFlowDriver::Paint(){ flow.Paint(); }
	void GameFlowDriver::MouseEvent(MouseButton b, ButtonEvent e, Point p){
		Input::InputType type;
		switch (b)
		{
			case MouseButton::Left:
				type = Input::InputType::lbutton;
				break;
			case MouseButton::Right:
				type = Input::InputType::rbutton;
				break;
		}
		switch (e)
		{
			case EcocoDeFightBase::GameFlowDriver::ButtonEvent::Down:
				Input::Active(type);
				break;
			case EcocoDeFightBase::GameFlowDriver::ButtonEvent::Up:
				Input::Release(type);
				break;
		}
	}
	GameFlowDriver::~GameFlowDriver(){
		flow.Release();
	}
	void GameFlowDriver::KeyBoardEvent(KeyCode c, ButtonEvent b){
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_ESC = 27;

		Input::InputType type;
		switch (c){
			case 'z':case'Z':
				type = Input::InputType::z;
				break;
			case 'x':case'X':
				type = Input::InputType::x;
				break;
			case 'c':case'C':
				type = Input::InputType::c;
				break;
			case 'v':case'V':
				type = Input::InputType::v;
				break;
			case KEY_LEFT:
				type = Input::InputType::left;
				break;
			case KEY_UP:
				type = Input::InputType::up;
				break;
			case KEY_RIGHT:
				type = Input::InputType::right;
				break;
			case KEY_DOWN:
				type = Input::InputType::down;
				break;
			case KEY_ESC:
				type = Input::InputType::esc;
				break;
			default:
				return;//not used input
		}

		switch (b)
		{
			case EcocoDeFightBase::GameFlowDriver::ButtonEvent::Down:
				input.Active(type);
				break;
			case EcocoDeFightBase::GameFlowDriver::ButtonEvent::Up:
				input.Release(type);
				break;
		}
	}
}