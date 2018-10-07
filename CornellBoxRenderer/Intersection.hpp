#pragma once

#include "Vector.hpp"

// レイと物体の交差点情報を管理するクラス
class Intersection{
public:
	Intersection();
	~Intersection();

	// このオブジェクトのIDを返す
	int GetID();

	// Rayの始点から交差点までの距離
	double distance;

	// 交差点における物体の法線
	Vector3 normalVec;

	// 交差点のワールド座標系における位置
	Vector3 pos;

private:
	// 交差点オブジェクトの識別番号 1-origin
	int id;

	// このクラスのオブジェクト数を記録し、各objで使用=番被り防止
	static inline int objNum;
};
