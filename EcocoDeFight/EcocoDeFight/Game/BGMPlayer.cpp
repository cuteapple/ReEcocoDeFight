#include "stdafx.h"
#include "Sound.h"
#include "BGMPlayer.h"
#include <map>
using namespace std;
using namespace EcocoDeFightBase;
namespace EcocoDeFight{
	struct BGMPlayer::Data{
		map<BGM, Sound::AudioID> idmap;
		//Sound::AudioID Start;
		//Sound::AudioID Playing;
	};
	BGMPlayer::Data* BGMPlayer::data = nullptr;
	void BGMPlayer::Initialize(){
		if (data != nullptr)return;
		data = new Data;
		Sound::Initizlize();
		//data->Start = Sound::Load("Audio/title.wav");
		//data->Playing = Sound::Load("Audio/chapter.wav");
		data->idmap[BGM::TITLE] = Sound::Load("./Audio/title.wav");
		data->idmap[BGM::PLAYING] = Sound::Load("./Audio/chapter.wav");
	}
	void BGMPlayer::Release(){ delete data; data = nullptr; Sound::Release(); }

	//enum class BGM{ TITLE, PLAYING };
	void BGMPlayer::Play(BGM id){ Sound::Play(data->idmap[id]); }
	void BGMPlayer::Stop(BGM id){ Sound::Stop(data->idmap[id]); }



}