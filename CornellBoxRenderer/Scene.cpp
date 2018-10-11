#include "Scene.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Constant.hpp"

Scene::Scene(){
	spheres.emplace_back( Sphere( 1e5, Vector3( 1e5+1, 40.8, 81.6 ),   Color(),				Color( 0.75, 0.25, 0.25 ) ) ); // 左壁
	spheres.emplace_back( Sphere( 1e5, Vector3( -1e5+99, 40.8, 81.6 ), Color(),				Color( 0.25, 0.25, 0.75 ) ) ); // 右壁
	spheres.emplace_back( Sphere( 1e5, Vector3( 50, 40.8, 1e5 ),       Color(),				Color( 0.75, 0.75, 0.75 ) ) ); // 奥壁
	spheres.emplace_back( Sphere( 1e5, Vector3( 50, 40.8, -1e5+250 ),  Color(),				Color() ) );				   // 手前壁
	spheres.emplace_back( Sphere( 1e5, Vector3( 50, 1e5, 81.6 ),	   Color(),				Color( 0.75, 0.75, 0.75 ) ) ); // 床
	spheres.emplace_back( Sphere( 1e5, Vector3( 50, -1e5+81.6, 81.6 ), Color(),				Color( 0.75, 0.75, 0.75 ) ) ); // 天井
	spheres.emplace_back( Sphere( 20,  Vector3( 65, 20, 20 ),          Color(),				Color( 0.25, 0.75, 0.25 ) ) ); // 緑球
	spheres.emplace_back( Sphere( 15,  Vector3( 50, 90, 81.6 ),		   Color( 36, 36, 36 ), Color( 0.99, 0.99, 0.99 ) ) ); // 照明
}	

bool Scene::IntersectAll( const Ray& ray, Intersection* const its ){
	its->distance = Constant::INF;

	for( int i = 0; i < spheres.size(); ++i ){
		Intersection hitpoint;
		if( spheres[i].Intersect( ray, hitpoint ) ){
			if( hitpoint.distance < its->distance ){
				*its = hitpoint;
				its->intersectedID = i; 
			}
		}
	}

	return ( its->intersectedID != -1 );
}
