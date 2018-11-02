#pragma once
#include <vector>

#include "Sphere.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"

namespace CBR{

// 実際に描画するシーン情報のクラス
class Scene{
public:
	// シーン内に存在するオブジェクト全てと1つのRayの交差判定
	// レイの始点に最も近いオブジェクトとの交差点情報をitsに渡す実体に保存
	static bool IntersectToScene( const Ray& ray, Intersection* its );

	// シーン内に存在する球オブジェクト全て
	static std::vector<Sphere> spheres;
};

}