#include "stdafx.h"
#include "Camera.h"
#include <functional>
using namespace std;

namespace EcocoDeFightBase{

	static void AdjustIntoRectangle(Point& point, const Point& upperLeft, const Point& lowerRight);

	//set camera position(no effect when tracing)
	void Camera::SetCameraPosition(Point position){
		if (getPointFunction)return;
		SetCameraPositionI(position);
	}

	//get camera position
	Point Camera::GetCameraPosition(){
		return position;
	}

	//tell the camera where the target is(no effect when tracing)
	void Camera::SetTargetPosition(Point pt){
		if (getPointFunction)return;
		SetTargetPositionI(position);
	}

	//tell the camera how much length(chessboard distance) can be accept(create smooth result)
	void Camera::SetTargetMaxOffset(unsigned int offset){
		maxOffset = offset;
	}

	//Start Tracing The Point Return By GetTargetPoint
	void Camera::StartTrace(function<Point()> GetTargetPoint){
		getPointFunction = GetTargetPoint;
	}

	//update trace point(no effect when not tracing)
	void Camera::UpdateCamera(){
		if (getPointFunction)
			SetTargetPositionI(getPointFunction());
	}

	//Stop Trace
	void Camera::StopTrace(){
		getPointFunction = nullptr;
	}

	//set the offset (target-camera)
	void Camera::SetTargetCameraScreenPoint(Point pt){
		targetCameraPosition = pt;
	}

	//set the boundry of where camera can arrive
	void Camera::SetCameraBoundary(Point upperLeft, Point lowerRight){
		Camera::upperLeft = upperLeft;
		Camera::lowerRight = lowerRight;
	}

	//set camera position without check if tracing
	void Camera::SetCameraPositionI(Point position){
		//keep position in boundary
		AdjustIntoRectangle(position, upperLeft, lowerRight);
		Camera::position = position;
	}

	//set target position without check if tracing
	void Camera::SetTargetPositionI(Point pt){
		pt = pt - targetCameraPosition;
		Point upperLeftBoundary = Point(pt.x - maxOffset, pt.y - maxOffset);
		Point lowerRightBoundary = Point(pt.x + maxOffset, pt.y + maxOffset);
		Point newPosition = Point(position);
		AdjustIntoRectangle(newPosition, upperLeftBoundary, lowerRightBoundary);
		SetCameraPositionI(newPosition);
	}

	static void AdjustIntoRectangle(Point& point, const  Point& upperLeft, const Point& lowerRight){
		if (point.x < upperLeft.x)point.x = upperLeft.x;
		else if (point.x > lowerRight.x)point.x = lowerRight.x;

		if (point.y < upperLeft.y)point.y = upperLeft.y;
		else if (point.y > lowerRight.y)point.y = lowerRight.y;
	}

#undef min
#undef max
	Point Camera::upperLeft = Point(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
	Point Camera::lowerRight = Point(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	Point Camera::position = Point(0, 0);
	Point Camera::targetCameraPosition;
	unsigned int Camera::maxOffset = 0;
	function<Point()> Camera::getPointFunction;
}