#ifndef ECOCO_DE_FIGHT_CAMERA_H
#define ECOCO_DE_FIGHT_CAMERA_H

#include "Point.h"
#include "Bitmap.h"
#include <functional>

namespace EcocoDeFightBase{
	using std::function;

	//The Camera Class Control All The Bitmap's Offset At PaintAt()
	class Camera
	{
	public:
		//no instance should be create
		Camera() = delete;
		//set camera position(no effect when tracing)
		static void SetCameraPosition(Point);
		//get camera position
		static Point GetCameraPosition();
		//tell the camera where the target is(no effect when tracing)
		static void SetTargetPosition(Point);
		//tell the camera how much length(chessboard distance) can be accept(create smooth result)
		static void SetTargetMaxOffset(unsigned int offset);

		//Start Tracing The Point Return By GetTargetPoint
		static void StartTrace(function<Point()> GetTargetPoint);
		//update trace point(no effect when not tracing)
		static void UpdateCamera();//strange to explict call this
		//Stop Trace
		static void StopTrace();

		//set the offset (target point - tracing point)(target-camera)
		static void SetTargetCameraScreenPoint(Point);
		//set the boundry of where camera can arrive
		static void SetCameraBoundary(Point upperLeft, Point lowerRight);
	private:
		static void SetCameraPositionI(Point);
		static void SetTargetPositionI(Point);
		static Point upperLeft;
		static Point lowerRight;
		static Point position;
		static Point targetCameraPosition;
		static unsigned int maxOffset;
		static function<Point()> getPointFunction;
	};
}
#endif