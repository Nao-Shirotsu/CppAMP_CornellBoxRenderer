#pragma once

#include "Vector.hpp"

// ワールド座標系におけるカメラ位置などの設定
struct Camera{
	// デフォルト値を自動設定する
	Camera();

	// 各種Setterはmain文でVector3クラスを使用しないようにするためのもの
	// 位置を更新
	void SetPos( const double x, const double y, const double z );

	// 前方向を示すベクトルを更新
	void SetDirectionFront( const double x, const double y, const double z );

	// 上方向を示すベクトルを更新
	void SetDirectionUp( const double x, const double y, const double z );

	Vector3 pos;
	Vector3 dirFront;
	Vector3 dirUp;
};