#ifndef ECOCO_DE_FIGHT_STAGE_IN_H
#define ECOCO_DE_FIGHT_STAGE_IN_H
#include <memory>

namespace EcocoDeFight{
	class StageIn{
	public:
		StageIn();
		~StageIn();
		void Initialize();
		void Play(int number);
		bool IsEnd();
		void Update();
		void Paint();
	private:
		struct StageInBitmaps;
		std::unique_ptr<StageInBitmaps> data;
	};
}

#endif