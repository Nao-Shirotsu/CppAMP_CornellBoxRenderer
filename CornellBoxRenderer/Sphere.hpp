#pragma once

#include "Vector.hpp"
#include "Color.hpp"
#include "Intersection.hpp"
#include "Ray.hpp"

// 幾何的に3次元空間で表現する光を完全拡散する球
class Sphere{
public:
	Sphere( const double radius_, const Vector3& pos_, const Color& emission_, const Color& color_ );

	// あるRayがこのSphereに交差するか判定する
	// 交差していたらitsにその情報を書き込む
	bool Intersect( const Ray& ray, Intersection& its ) const;

protected:
	// 半径
	double radius;

	// 中心のワールド座標系における位置ベクター
	Vector3 pos;

	// 発光色
	Color emission;

	// 反射率
	Color color;
};