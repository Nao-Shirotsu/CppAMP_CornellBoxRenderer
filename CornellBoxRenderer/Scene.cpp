#include "Scene.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Constant.hpp"

std::vector<Sphere> Scene::spheres{
	Sphere( 1e5, Vector3( -1e5 - 55, 0.0, 0.0 ), Color(),	 	    Color( 0.75, 0.25, 0.25 ) ), // 左
	Sphere( 1e5, Vector3( 1e5 + 55, 0.0, 0.0 ),  Color(),	 	    Color( 0.25, 0.25, 0.75 ) ), // 右
	Sphere( 1e5, Vector3( 0.0, 0.0,  1e5 + 50 ), Color(),	 	    Color( 0.75, 0.75, 0.25 ) ), // 奥
	Sphere( 1e5, Vector3( 0.0, 0.0, -1e5 - 50 ), Color(),	 	    Color( 0.75, 0.375, 0.25 ) ), // 手前
	Sphere( 1e5, Vector3( 0.0, -1e5 - 50, 0.0 ), Color(),	 	    Color( 0.75, 0.75, 0.75 ) ), // 床
	Sphere( 1e5, Vector3( 0.0,  1e5 + 50, 0.0 ), Color(),	 	    Color( 0.75, 0.75, 0.75 ) ), // 天井
	Sphere( 15,  Vector3( -20.0, -30.0, 25.0 ),  Color(),		    Color( 0.25, 0.75, 0.25 ) ), // 緑球
	Sphere( 15,  Vector3( 20.0, -30.0, 35.0 ),   Color(),		    Color( 0.75, 0.25, 0.75 ) ), // 紫球
	Sphere( 15.0,Vector3( 0.0, 59.0, 0.0 ),		 Color( 36,36,36 ), Color() ), //照明
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
