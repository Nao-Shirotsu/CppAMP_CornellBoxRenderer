#include "Scene.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Constant.hpp"

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
