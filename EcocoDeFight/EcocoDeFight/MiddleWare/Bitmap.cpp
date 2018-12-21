
#include "stdafx.h"

#include "Bitmap.h"
#include "Camera.h"

#include <ddraw.h>
#include "gamelib.h"
using game_framework::CMovingBitmap;


namespace EcocoDeFightBase{
	//struct BitmapData
	struct Bitmap::BitmapData{
		CMovingBitmap bitmap;
		Point delta;
	};

	//Initialize
	void Bitmap::Load(UINT ID, AnchorType type){
		data->bitmap.LoadBitmapA(ID);
		switch (type)
		{
			case AnchorType::TOPLEFT:
				//Do Nothing
				break;
			case AnchorType::MIDDLEBUTTON:
				data->delta.x = data->bitmap.Width() / 2;
				data->delta.y = data->bitmap.Height();
				break;
		}
	}

	void Bitmap::Load(UINT ID, Color bgcolor, AnchorType type){
		data->bitmap.LoadBitmapA(ID, RGB(bgcolor.R, bgcolor.G, bgcolor.B));
		switch (type)
		{
			case AnchorType::TOPLEFT:
				//Do Nothing
				break;
			case AnchorType::MIDDLEBUTTON:
				data->delta.x = data->bitmap.Width() / 2;
				data->delta.y = data->bitmap.Height();
				break;
		}
	}

	//operation
	void Bitmap::PaintAt(const Point& point, bool useCameraPosition){
		Point result = point - data->delta;
		if (useCameraPosition)result -= Camera::GetCameraPosition();
		data->bitmap.SetTopLeft(result.x, result.y);
		data->bitmap.ShowBitmap();
	}

	//建構及解構函數
	Bitmap::Bitmap(){ data = new BitmapData; }

	Bitmap::~Bitmap(){ delete data; }

	Bitmap::Bitmap(const Bitmap& o) :Bitmap(){
		this->data->bitmap = o.data->bitmap;
		this->data->delta = o.data->delta;
	}

	Bitmap::Bitmap(Bitmap&& o){
		this->data = o.data;
		o.data = NULL;
	}

	//operator =
	Bitmap& Bitmap::operator=(const Bitmap&o){
		//if (this == &o)return *this; //only speed up self assignment
		this->data->bitmap = o.data->bitmap;
		this->data->delta = o.data->delta;
		return *this;
	}

	Bitmap& Bitmap::operator=(Bitmap&& o){
		delete this->data;
		this->data = o.data;
		o.data = NULL;
		return *this;
	}
}