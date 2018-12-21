#include "stdafx.h"
#include "Sound.h"
//game - framework
#include "audio.h"
//end game - framework
using namespace game_framework;
namespace EcocoDeFightBase{
	Sound::Data* Sound::data = nullptr;
	//Not Used Now
	struct Sound::Data{ int index = 1; };
	void Sound::Initizlize(){ if (data == nullptr) data = new Data;/* CAudio::Instance()->Open(); game_frameword has "stangely" already open it*/ }
	Sound::AudioID Sound::Load(const char* path){ CAudio::Instance()->Load(data->index, const_cast<char*>(path)); return data->index++; }
	void Sound::Play(AudioID id){ CAudio::Instance()->Play(static_cast<int>(id)); }
	void Sound::Stop(AudioID id){ CAudio::Instance()->Stop(static_cast<int>(id)); }
	void Sound::Release(){/* CAudio::Instance()->Close(); Same Reaseon As Open*/ delete data; data = nullptr; }
}