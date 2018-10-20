#include <memory>
#include <cmath>

#include "Radiance.hpp"
#include "Intersection.hpp"
#include "Scene.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "Constant.hpp"

namespace{

constexpr int DEPTH = 5; //ロシアンルーレットの最低保証回数
constexpr int DEPTHLIMIT = 64;

}

Color Radiance( const Ray& ray, const RandomGenerator& rnd, const int depth ){
	Intersection its;

	// シーン内の何にも交差しなかった時
	if( !Scene::IntersectToScene( ray, &its ) ){
		return Vector3( 0.0, 0.0, 0.0 );
	}

	const Sphere& currentObj = Scene::spheres[its.intersectedID];
	const Intersection& hitpoint = its;
	const Vector3 orientingNormalVec =
		( Dot( hitpoint.normalVec, ray.dir ) < 0.0 )?
		hitpoint.normalVec :
		-1.0 * hitpoint.normalVec;

	// ロシルレ継続率
	double rusRouletteProbability = 0.75;

	// 一定回数以上rayが反射したらロシルレドボン確率を上げる
	if( depth > DEPTHLIMIT ){
		rusRouletteProbability *= std::pow( 0.5, depth - DEPTHLIMIT );
	}

	// 普通にロシルレをする時
	if( depth > DEPTH && rnd() >= rusRouletteProbability ){
		
		return currentObj.emission;
	}
	else{
		// ロシルレ実行されない時
		rusRouletteProbability = 1.0;
	}

	Color incomingRadiance;
	Color weight( 1.0, 0.0, 0.0 );

	// 完全拡散面のRay反射処理
	// u, v, wは反射した後のRayを求めるための正規直交基底
	Vector3 u;
	Vector3 v;
	Vector3 w = orientingNormalVec;

	if( std::fabs( w.x ) > Constant::MIN0 ){
		u = Cross( Vector3( 0.0, 1.0, 0.0 ), w ).NormalizedVector();
	}
	else{
		u = Cross( Vector3( 1.0, 0.0, 0.0 ), w ).NormalizedVector();
	}

	v = Cross( w, u );
	
	const double r1 = 2.0 * Constant::PI * rnd();
	const double r2 = rnd();
	const double rootR2 = std::sqrt( r2 );

	Vector3 dir = ( u * std::cos( r1 ) * rootR2 +
					v * std::sin( r1 ) * rootR2 +
					w * std::sqrt( 1.0 - r2 ) ).NormalizedVector();

	incomingRadiance = Radiance( Ray( hitpoint.pos, dir ), rnd, depth + 1 );
	weight = currentObj.color / rusRouletteProbability;

	return Vector3( currentObj.emission.x + weight.x * incomingRadiance.x,
					currentObj.emission.y + weight.y * incomingRadiance.y,
					currentObj.emission.z + weight.z * incomingRadiance.z );
}
