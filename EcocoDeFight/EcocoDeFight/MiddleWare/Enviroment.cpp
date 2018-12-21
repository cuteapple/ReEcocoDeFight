#include "stdafx.h"
#include <windows.h>
#include "Enviroment.h"
#include "ddraw.h"// <-- bad include
#include "gamelib.h"// <-- because bad header file
namespace EcocoDeFightBase{
	const int Enviroment::ScreenWidth = SIZE_X;
	const int Enviroment::ScreenHeight = SIZE_Y;
	void Enviroment::CloseWindow(){ ::PostMessage(GetActiveWindow(), WM_CLOSE, 0, 0); }
}