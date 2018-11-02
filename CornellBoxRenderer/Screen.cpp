#include "Screen.hpp"
#include "Vector.hpp"

namespace CBR{

Screen::Screen( const ImageResolution & image, const Camera & camera ):
	length( 62.0 * image.x / image.y ),
	width( 62.0 ),
	distanceFromCamera( 40.0 ),
	horizontalVec( Cross( camera.dirFront, camera.dirUp ).NormalizedVector() * length ),
	verticalVec( Cross( horizontalVec, camera.dirFront ).NormalizedVector() * width ),
	centerPos( camera.pos + camera.dirFront * distanceFromCamera ){}

Vector3 Screen::GetXvec() const{
	return horizontalVec;
}

Vector3 Screen::GetYvec() const{
	return verticalVec;
}

Vector3 Screen::GetCenter() const{
	return centerPos;
}

}