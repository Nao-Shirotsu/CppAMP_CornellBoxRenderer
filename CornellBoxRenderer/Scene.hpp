#pragma once
#include <vector>
#include <memory>

#include "Sphere.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"

// 実際に描画するシーン情報のクラス
class Scene{
public:
	Scene();

	// シーン内に存在するオブジェクト全てと1つのRayの交差判定
	bool IntersectAll( const Ray& ray, std::shared_ptr<Intersection> const its ) const;
	
	// シーン内に存在する球オブジェクト全て
	std::vector<Sphere> spheres;
};