#pragma once

#include "Vector.hpp"
#include "ImageResolution.hpp"
#include "CameraInfo.hpp"

// ワールド座標系でのスクリーン情報
class Screen{
public:
	Screen( const ImageResolution& image, const Camera& camera );

	// 値を変更したいとき用のSetter
	void Reset( const ImageResolution& image, const Camera& camera );

	// Getter
	Vector3 GetXvec() const;
	Vector3 GetYvec() const;
	Vector3 GetCenter() const;

private:
	// ワールド座標系でのスクリーン幅
	double length;
	double width;

	// ワールド座標系でのカメラとの距離
	double distanceFromCamera;

	// ワールド座標系でこのスクリーンを張るベクトル
	Vector3 horizontalVec;
	Vector3 verticalVec;
	Vector3 centerPos;
};