#pragma once

#include "Vector.hpp"

struct Ray{
	// レイの始点位置ベクトルと進む方向ベクトルを渡すと、
	// 始点ベクトルと正規化された方向ベクトルをメンバ変数に保存する
	// もちろん正規化済のベクトルをendに渡しても問題ない
	Ray( const Vector3& origin_, const Vector3& end );

	// レイの始点
	Vector3 origin;

	// レイの方向を示す正規化ベクトル
	Vector3 dir;
};