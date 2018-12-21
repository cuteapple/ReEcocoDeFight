#ifndef ECOCO_DE_FIGHT_BASE_SOUND_H
#define ECOCO_DE_FIGHT_BASE_SOUND_H
namespace EcocoDeFightBase{
	//No Time,So A Little Wired
	class Sound{
	public:
		Sound() = delete;
		typedef int AudioID;
		static void Initizlize();
		static AudioID Load(const char* path);
		static void Play(AudioID);
		static void Stop(AudioID);
		static void Release();
	private:
		struct Data;
		static Data* data;
	};
}
#endif