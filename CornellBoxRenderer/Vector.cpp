#include "Vector.hpp"

Vector3::Vector3() = default;

Vector3::Vector3( const double x_, const double y_, const double z_ ):
	x( x_ ), y( y_ ), z( z_ ){}

Vector3::Vector3( const Vector3& vec ) :
	x( vec.x ), y( vec.y ), z( vec.z ){}

Vector3::~Vector3() = default;

Vector3& Vector3::operator=( const Vector3& vec ){
	if( this != &vec ){
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	return *this;
}

double Dot( const Vector3& a, const Vector3& b ){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Cross( const Vector3& a, const Vector3& b ){
	return Vector3( a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x );
}

Vector3 operator+( const Vector3& a, const Vector3& b ){
	return Vector3( a.x + b.x, a.y + b.y, a.z + b.z );
}

Vector3 operator-( const Vector3& a, const Vector3& b ){
	return Vector3( a.x - b.x, a.y - b.y, a.z - b.z );
}