#include "stdafx.h"
#include "Background.h"
#include "Bitmap.h"
#include "Enviroment.h"
#include "EcoPicEx.h"
using namespace EcocoDeFightBase;

namespace EcocoDeFight{
	struct Background::Bitmaps{
		Bitmap EcocoWin;
		Bitmap EcocoLose;
		Bitmap EcocoStart;
		Bitmap IceStage;
		Bitmap* current = nullptr;
	};
	Background::Bitmaps* Background::bitmaps = nullptr;
	void Background::Initizlize(){
		if (bitmaps != nullptr)return;
		bitmaps = new Bitmaps;
		bitmaps->EcocoWin.Load(IDB_CG_ECOCO_WIN);
		bitmaps->EcocoLose.Load(IDB_CG_ECOCO_LOSE);
		bitmaps->EcocoStart.Load(IDB_CG_ECOCO_BEGIN);
		bitmaps->IceStage.Load(IDB_CG_BG_ICE);
	}
	void Background::Release(){ delete bitmaps; bitmaps = nullptr; }
	//enum class BackgroundType{ EcocoWin, EcocoLose, EcocoStart };
	void Background::Change(BackgroundType type){
		switch (type)
		{
			case BackgroundType::EcocoWin:bitmaps->current = &bitmaps->EcocoWin; break;
			case BackgroundType::EcocoLose:bitmaps->current = &bitmaps->EcocoLose; break;
			case BackgroundType::EcocoStart:bitmaps->current = &bitmaps->EcocoStart; break;
			case BackgroundType::StageIce:bitmaps->current = &bitmaps->IceStage; break;
		}
	}

	void Background::Paint(){
		Point offset = Point((Enviroment::ScreenWidth - CG_WIDTH) / 2, (Enviroment::ScreenHeight - CG_HEIGHT) / 2);
		bitmaps->current->PaintAt(offset, false);
	}
}