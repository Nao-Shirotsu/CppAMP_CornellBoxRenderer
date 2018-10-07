#include <cstdlib>

#include "Intersection.hpp"
#include "Constant.hpp"

Intersection::Intersection():
	distance( Constant::INF ),
	normalVec(),
	pos(){
	id = ++objNum;
}

Intersection::~Intersection(){
	if( --objNum < 0 ){
		std::exit( -1 );
	}
}

int Intersection::GetID(){
	return id;
}
