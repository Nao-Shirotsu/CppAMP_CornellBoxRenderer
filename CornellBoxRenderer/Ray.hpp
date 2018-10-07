#pragma once

#include "Vector.hpp"

struct Ray{
	Ray( const Vector3& origin_, const Vector3& end_ );

	// 一つのレイの始点と終点
	Vector3 origin;
	Vector3 end;
};