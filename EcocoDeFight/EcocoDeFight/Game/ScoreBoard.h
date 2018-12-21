#ifndef ECOCO_DE_FIGHT_SCOREBOARD_H
#define ECOCO_DE_FIGHT_SCOREBOARD_H

namespace EcocoDeFight{
	// May Be Better Not Static , But I Seems To Have No Time 2015.06.08
	class ScoreBoard{
	public:
		ScoreBoard() = delete;
		static void Initialize();
		static void ResetScore();
		//return : Not Tired
		static bool FailOnce();
		static bool Tired();
		static void Draw();
		static void Release();
	private:
		struct Score;
		static Score* score;
		struct Data;
		static Data* data;
	};
}

#endif