#include "Scene.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Constant.hpp"

// 今回は球データは直書きする
std::vector<Sphere> Scene::spheres{
	Sphere( 1e5, Vector3( 1e5 + 1, 40.8, 81.6 ),   Color(),				Color( 0.75, 0.25, 0.25 ) ),// 左壁
	Sphere( 1e5, Vector3( -1e5 + 99, 40.8, 81.6 ), Color(),				Color( 0.25, 0.25, 0.75 ) ),// 右壁
	Sphere( 1e5, Vector3( 50, 40.8, 1e5 ),       Color(),				Color( 0.75, 0.75, 0.75 ) ),// 奥壁
	Sphere( 1e5, Vector3( 50, 40.8, -1e5 + 250 ),  Color(),				Color() ),					// 手前壁
	Sphere( 1e5, Vector3( 50, 1e5, 81.6 ),	   Color(),					Color( 0.75, 0.75, 0.75 ) ),// 床
	Sphere( 1e5, Vector3( 50, -1e5 + 81.6, 81.6 ), Color(),				Color( 0.75, 0.75, 0.75 ) ),// 天井
	Sphere( 20,  Vector3( 65, 20, 20 ),          Color(),				Color( 0.25, 0.75, 0.25 ) ),// 緑球
	Sphere( 15,  Vector3( 50, 90, 81.6 ),		   Color( 36, 36, 36 ), Color( 0.99, 0.99, 0.99 ) ) // 照明
};

bool Scene::IntersectToScene( const Ray& ray, Intersection* its ){

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
