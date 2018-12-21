#ifndef ECOCO_DE_FIGHT_INPUT_H
#define ECOCO_DE_FIGHT_INPUT_H

namespace EcocoDeFightBase{
	class Input
	{
	public:
		enum InputType{ begin = -1, 
			z, x, c, v, esc, up, down, left, right, //KeyBoard
			lbutton, rbutton,  // Mouse
			length };
		struct InputState{
			bool states[length] ;
		};


		static bool IsActiving(InputType type);
		static bool IsReleasing(InputType type);
		static bool IsActive(InputType type);
		static bool IsRelease(InputType type);
	private:
		friend class GameFlowDriver;
		static void Active(InputType input);
		static void Release(InputType input);
		static void NextFrame();

		static InputState states[2];
		static int currentState;
		static int lastState;
	};
}
#endif