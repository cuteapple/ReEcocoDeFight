#include "stdafx.h"
#include "PenguinState_Tracing.h"
#include <functional>
#include "Penguin.h"
#include "Point.h"
#include "EcoPicEx.h"
#include "CommonFunctions.h"
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	bool PenguinState_Tracing::IsRunning()const{ return static_cast<bool>(ecocoPlace);/*why need cast*/ }
	void PenguinState_Tracing::Initialize(){
		const Color bgColor(0, 184, 0);

		unsigned int idFlyL[] = { IDB_PENGUIN_FLYL_1, IDB_PENGUIN_FLYL_2, IDB_PENGUIN_FLYL_3, IDB_PENGUIN_FLYL_2 };
		animationIDs.FlyL = animator.AddAnimation(InitializeAnimation(idFlyL, sizeof(idFlyL) / sizeof(unsigned int), bgColor));

		unsigned int idFlyR[] = { IDB_PENGUIN_FLYR_1, IDB_PENGUIN_FLYR_2, IDB_PENGUIN_FLYR_3, IDB_PENGUIN_FLYR_2 };
		animationIDs.FlyR = animator.AddAnimation(InitializeAnimation(idFlyR, sizeof(idFlyR) / sizeof(unsigned int), bgColor));

		unsigned int idWalkL[] = { IDB_PENGUIN_WALKL_1, IDB_PENGUIN_WALKL_2, IDB_PENGUIN_WALKL_3, IDB_PENGUIN_WALKL_4, IDB_PENGUIN_WALKL_5, IDB_PENGUIN_WALKL_6 };
		animationIDs.WalkL = animator.AddAnimation(InitializeAnimation(idWalkL, sizeof(idWalkL) / sizeof(unsigned int), bgColor));

		unsigned int idWalkR[] = { IDB_PENGUIN_WALKR_1, IDB_PENGUIN_WALKR_2, IDB_PENGUIN_WALKR_3, IDB_PENGUIN_WALKR_4, IDB_PENGUIN_WALKR_5, IDB_PENGUIN_WALKR_6 };
		animationIDs.WalkR = animator.AddAnimation(InitializeAnimation(idWalkR, sizeof(idWalkR) / sizeof(unsigned int), bgColor));

		unsigned int idStandL[] = { IDB_PENGUIN_STANDL };
		animationIDs.StandL = animator.AddAnimation(InitializeAnimation(idStandL, sizeof(idStandL) / sizeof(unsigned int), bgColor));

		unsigned int idStandR[] = { IDB_PENGUIN_STANDR };
		animationIDs.StandR = animator.AddAnimation(InitializeAnimation(idStandR, sizeof(idStandR) / sizeof(unsigned int), bgColor));

		animationIDs.lastID = animationIDs.StandL;
		animator.ChangeAnimation(animationIDs.StandL);
	}
	void PenguinState_Tracing::Start(function<Point()> ecocoPlace, int d){ this->distance = d; this->ecocoPlace = ecocoPlace; }
	void PenguinState_Tracing::Update(){
		animator.Update();
		//penguin->SetPlace(ecocoPlace()); 
		Point ptpenguin = penguin->GetPlace();
		Point ptecoco = ecocoPlace();
		Animator::AnimationID currentID=animationIDs.lastID;
		if (abs(ptpenguin.x - ptecoco.x) > 10){
			if (ptpenguin.x > ptecoco.x){
				if (ptpenguin.x - ptecoco.x > distance){ ptpenguin.x -= velocityX; currentID = animationIDs.FlyL; }
				else { ptpenguin.x -= (ptpenguin.x - ptecoco.x) / 3;	currentID = animationIDs.FlyL; }
			}
			else if (ptpenguin.x < ptecoco.x){
				if (ptecoco.x - ptpenguin.x > distance){ ptpenguin.x += velocityX; currentID = animationIDs.FlyR; }
				else { ptpenguin.x += (ptecoco.x - ptpenguin.x) / 3; currentID = animationIDs.FlyR; }
			}
		}
		else
		{
			if (animationIDs.lastID == animationIDs.FlyL || animationIDs.lastID == animationIDs.StandL || animationIDs.lastID == animationIDs.WalkL){
				currentID = animationIDs.StandL;
			}
			else currentID = animationIDs.StandR;
		}
		ptpenguin.y = (ptecoco.y + ptpenguin.y) / 2;
		penguin->SetPlace(ptpenguin);
		if (animationIDs.lastID != currentID){
			animationIDs.lastID = currentID;
			animator.ChangeAnimation(currentID);
		}
	}
	void PenguinState_Tracing::Paint(){ animator.PaintAt(penguin->GetPlace() + Point(-10, -8)); }
	void PenguinState_Tracing::Stop(){ ecocoPlace = nullptr; }
}