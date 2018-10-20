#pragma once
#include <vector>
#include <memory>

#include "Sphere.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"

// 実際に描画するシーン情報のクラス
class Scene{
public:
	// シーン内に存在するオブジェクト全てと1つのRayの交差判定
	static bool IntersectToScene( const Ray& ray, Intersection* its );
	
	// シーン内に存在する球オブジェクト全て
	static std::vector<Sphere> spheres;
};