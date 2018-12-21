#ifndef ECOCO_DE_FIGHT_BACKGROUND_H
#define ECOCO_DE_FIGHT_BACKGROUND_H
namespace EcocoDeFight{
	class Background{
	public:
		static void Initizlize();
		static void Release();
		enum class BackgroundType{ EcocoWin, EcocoLose, EcocoStart ,StageIce};
		static void Change(BackgroundType);
		static void Paint();
	private:
		struct Bitmaps;
		static Bitmaps* bitmaps;
	};
}
#endif