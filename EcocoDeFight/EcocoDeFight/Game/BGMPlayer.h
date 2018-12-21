#ifndef ECOCO_DE_FIGHT_BGMPLAYER_H
#define ECOCO_DE_FIGHT_BGMPLAYER_H
namespace EcocoDeFight{
	class BGMPlayer{
	public:
		enum class BGM{ TITLE, PLAYING };
		static void Initialize();
		static void Release();
		static void Play(BGM);
		static void Stop(BGM);
	private:
		struct Data;
		static Data* data;
	};
}
#endif