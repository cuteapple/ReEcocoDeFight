#include "stdafx.h"

#include "Animator.h"
#include <vector>
using std::vector;

namespace EcocoDeFightBase{
	struct Animator::AnimatorData{
		vector < Animation > animations;
		AnimationID current_animation = 0;
	};

	//initialize Animator
	int Animator::AddAnimation(const Animation& o){
		data->animations.push_back(o);
		return data->animations.size() - 1;
	}

	int Animator::AddAnimation(Animation&& o){
		data->animations.push_back(std::move(o));
		return data->animations.size() - 1;
	}

	//use Animator
	void Animator::ChangeAnimation(AnimationID id){
		data->current_animation = id;
		data->animations[id].Reset();
	}

	void Animator::Update(){
		data->animations[data->current_animation].Update();
	}

	void Animator::PaintAt(Point point){
		data->animations[data->current_animation].PaintAt(point);
	}

	//Animator constructor.destructor,assignment
	Animator::Animator(){
		data = new AnimatorData;
	}

	Animator::~Animator(){
		delete data;
	}

	Animator::Animator(const Animator& o) :Animator(){
		*(this->data) = *(o.data);
	}

	Animator::Animator(Animator&& o){
		this->data = o.data; o.data = NULL;
	}

	Animator& Animator::operator=(const Animator& o){
		*(this->data) = *(o.data);
		return *this;
	}

	Animator& Animator::operator=(Animator&& o){
		delete this->data;
		this->data = o.data;
		o.data = NULL;
		return *this;
	}
}