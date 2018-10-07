#pragma once

#include "RenderingData.hpp"

// RenderingData型をもとに.ppmファイルを生成する(==ppmファイルに描画する)
// length = 横幅 = x,  width = 縦幅 = y
void GeneratePpmFile( const RenderingData* color, const int length, const int width );

// 0.0~1.0の色データを0~255の整数値に変換
int ToPixelValue( double n );