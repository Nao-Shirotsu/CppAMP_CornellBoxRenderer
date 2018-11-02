#pragma once

namespace CBR{

// 画像の解像度, サンプリング回数などを管理する構造体
struct ImageResolution{
	ImageResolution( const int x, const int y, const int pixelDivNum, const int sampleNum );

	// 解像度
	int x;
	int y;

	// 1ピクセルに対する分割数 n*n = サブピクセル数
	int pixelDivNum;

	// 1サブピクセルに対するサンプリング回数
	int sampleNum;


};

}