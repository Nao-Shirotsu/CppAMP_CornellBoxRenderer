#pragma once

// length = 横幅 = x
// width = 縦幅 = y
// pixelDivNum = 1ピクセルに対する分割数 n*n = サブピクセル数
// sampleNum = 1サブピクセルに対するサンプリング回数
void Render( const int length, const int width, const int pixelDivNum, const int sampleNum );