#include "CameraInfo.hpp"
#include "Vector.hpp"

namespace CBR{

Camera::Camera():
	pos( 0.0, 0.0, -49.0 ),
	dirFront( 0.0, 0.0, 1.0 ),
	dirUp( 0.0, 1.0, 0.0 ){}

void Camera::SetPos( const double x, const double y, const double z ){
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void Camera::SetDirectionFront( const double x, const double y, const double z ){
	dirFront = Vector3( x, y, z ).NormalizedVector();
}

void Camera::SetDirectionUp( const double x, const double y, const double z ){
	dirUp = Vector3( x, y, z ).NormalizedVector();
}

}