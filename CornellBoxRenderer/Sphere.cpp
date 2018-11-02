#include <cmath>

#include "Sphere.hpp"
#include "Constant.hpp"

namespace CBR{

Sphere::Sphere( const double radius_, const Vector3 & pos_, const Color & emission_, const Color & color_ ):
	radius( radius_ ),
	pos( pos_ ),
	emission( emission_ ),
	color( color_ ){}

bool Sphere::Intersect( const Ray & ray, Intersection & its ) const{
	// 位置ベクトルは全てワールド座標系におけるものとする
	// 二次方程式の判別式 D/4 = ( B^2 - 4AC )/4
	// これを用いて、RayがSphereに交差しているか判定する

	// tを実数とすると、交差点の位置ベクトル
	// P(t) = ray.origin - t * ray.dir

	// よって、次の方程式によってtを求められる。
	// (交差判定と判別式Dは次の式によって計算するということ)
	// | pos - P(t) | = radius
	// ( pos - P(t) )^2 - radius = 0

	const Vector3& p_o = pos - ray.origin;
	const double b = Dot( p_o, ray.dir );
	const double Ddiv4 = b * b - Dot( p_o, p_o ) + radius * radius;

	// 交差点が存在するかどうか
	if( Ddiv4 < 0.0 ){
		return false;
	}

	const double rootDdiv4 = std::sqrt( Ddiv4 );

	// 上述方程式の解2つ どちらかがRay入射点
	const double t1 = b - rootDdiv4;
	const double t2 = b + rootDdiv4;

	if( t1 < Constant::MIN0 && t2 < Constant::MIN0 ){
		return false;
	}

	if( t1 > Constant::MIN0 ){
		its.distance = t1;
	}
	else{
		its.distance = t2;
	}

	// P(t) = ray.origin - t * ray.dir
	its.pos = ray.origin + its.distance * ray.dir;
	its.normalVec = ( its.pos - pos ).NormalizedVector();

	return true;
}

}