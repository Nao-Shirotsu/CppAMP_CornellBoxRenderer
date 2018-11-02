#include <cmath>

#include "Vector.hpp"

namespace CBR{

Vector3::Vector3():
	x( 0 ), y( 0 ), z( 0 ){}

Vector3::Vector3( const double x_, const double y_, const double z_ ) :
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

Vector3 Vector3::operator+( const Vector3 & vec ) const{
	return Vector3( x + vec.x, y + vec.y, z + vec.z );
}

Vector3 Vector3::operator-( const Vector3 & vec ) const{
	return Vector3( x - vec.x, y - vec.y, z - vec.z );
}

Vector3 Vector3::operator/( const double num ) const{
	return Vector3( x / num, y / num, z / num );
}

Vector3 Vector3::operator*( const double num ) const{
	return Vector3( x * num, y * num, z * num );
}

double Vector3::Abs() const{
	return std::sqrt( x * x + y * y + z * z );
}

Vector3 Vector3::NormalizedVector() const{
	double abs = Abs();
	return Vector3( x / abs, y / abs, z / abs );
}

Vector3 operator*( const double num, const Vector3 & vec ){
	return Vector3( vec.x * num, vec.y * num, vec.z * num );
}

double Dot( const Vector3& a, const Vector3& b ){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Cross( const Vector3& a, const Vector3& b ){
	return Vector3( a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x );
}

}