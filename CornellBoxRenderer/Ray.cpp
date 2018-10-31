#include <iostream>
#include "Ray.hpp"

Ray::Ray( const Vector3& origin_, const Vector3& end ):
	origin( origin_ ), dir( end ){}
