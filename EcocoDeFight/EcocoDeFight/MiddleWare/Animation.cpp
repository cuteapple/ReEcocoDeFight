#include "stdafx.h"

#include "cassert"
#include "Animation.h"
#include <vector>
using std::vector;

namespace EcocoDeFightBase{
	struct Animation::AnimationData{
		vector<Bitmap> bitmap;
		int delaycount = 5;
		int delaycounter = 5;
		int bitmapcounter = 0;
		int backtoBmpNumber = 0;
	};

	//Update And Paint Function
	void Animation::Update(){
		assert(data->bitmap.size() != 0);
		if (data->delaycounter == 0){
			data->bitmapcounter = (data->bitmapcounter + 1);
			if (data->bitmapcounter == data->bitmap.size()){
				data->bitmapcounter = data->backtoBmpNumber;
			}

			data->delaycounter = data->delaycount;
		}
		--(data->delaycounter);
	}
	void Animation::Reset(){
		data->delaycounter = data->delaycount;
		data->bitmapcounter = 0;
	}
	void Animation::PaintAt(Point place){
		data->bitmap[data->bitmapcounter].PaintAt(place);
	}

	//Modify Function
	void Animation::AddBitmap(Bitmap& bitmap){ data->bitmap.push_back(bitmap); }
	void Animation::AddBitmap(Bitmap&& bitmap){ data->bitmap.push_back(std::move(bitmap)); }
	void Animation::SetDelayFrameCount(int delay){ data->delaycount = delay; }
	void Animation::SetBackToBmpNumber(unsigned int number){ data->backtoBmpNumber = number%data->bitmap.size(); }
	unsigned int Animation::GetBitmapCount()const{ return data->bitmap.size(); }

	//constructor / destructor / assignment operator
	Animation::Animation(){ data = new AnimationData; }
	Animation::~Animation(){ delete data; }
	Animation::Animation(const Animation& o) :Animation(){
		*(this->data) = *(o.data);
	}
	Animation::Animation(Animation&& o){
		this->data = o.data;
		o.data = NULL;
	}
	Animation& Animation::operator = (const Animation& o){
		//if (this == &o)return *this; //only speed up self assignment
		*(this->data) = *(o.data);
		return *this;
	}
	Animation& Animation::operator = (Animation&& o){
		delete this->data;
		this->data = o.data;
		o.data = NULL;
		return *this;
	}
}