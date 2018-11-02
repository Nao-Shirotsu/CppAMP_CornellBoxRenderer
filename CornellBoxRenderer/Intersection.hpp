#pragma once

#include "Vector.hpp"

namespace CBR{

// Rayと物体の交差点情報を保存する構造体
class Intersection{
public:
	Intersection();

	// コピー代入演算子
	Intersection& operator=( const Intersection& rIts );

	// Rayの始点から交差点までの距離
	double distance;

	// 交差点を始点とする物体の法線
	Vector3 normalVec;

	// 交差点のワールド座標系における位置
	Vector3 pos;

	// どの球と交差したか識別する番号
	// Scene.sphere[]の配列番号をこれに保存する
	int intersectedID;
};

}