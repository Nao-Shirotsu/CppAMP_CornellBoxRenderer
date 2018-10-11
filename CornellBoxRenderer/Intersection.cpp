#include <cstdlib>

#include "Intersection.hpp"
#include "Constant.hpp"

Intersection::Intersection():
	distance( Constant::INF ),
	normalVec(),
	pos(),
	intersectedID( -1 ){}

Intersection& Intersection::operator=( const Intersection& rIts ){
	if( this != &rIts ){
		distance = rIts.distance;
		normalVec = rIts.normalVec;
		pos = rIts.pos;
		intersectedID = rIts.intersectedID;
	}
	return *this;
}
