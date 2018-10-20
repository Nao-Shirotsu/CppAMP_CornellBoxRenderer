#include <iostream>
#include <memory>

#include "Render.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "RandomGenerator.hpp"
#include "Ray.hpp"
#include "Radiance.hpp"
#include "PPMhandler.hpp"

// length = 横幅 = x,  width = 縦幅 = y
void Render( const int length, const int width ){
	// カメラ設定
	const Vector3 cameraPos( 50.0, 52.0, 220.0 );
	const Vector3 cameraDirFront = Vector3( 0.0, -0.04, -1.0 ).NormalizedVector();
	const Vector3 cameraDirUp( 0.0, 1.0, 0.0 );

	// スクリーン幅
	const double screenLength = 30.0 * length / width;
	constexpr double screenWidth = 30.0;

	// カメラ～スクリーン距離
	constexpr double distanceCamToScr = 40.0;

	// スクリーン設定
	const Vector3 screenX = Cross( cameraDirFront, cameraDirUp ).NormalizedVector() * screenLength;
	const Vector3 screenY = Cross( screenX, cameraDirFront ).NormalizedVector() * screenWidth;
	const Vector3 screenCenter = cameraPos + cameraDirFront * distanceCamToScr;

	// 出力画像データをピクセル単位で保存するバッファ
	Color* pixelData = new Color[length * width];

	// パストレーシングで用いる乱数生成器
	RandomGenerator rnd;

	// 1ピクセルに対するn*n分割数(スーパーサンプリング) = サブピクセル数
	constexpr int pixelDivNum = 2;

	// pixelDivNumの逆数
	constexpr double invPixelDivNum = 1.0 / pixelDivNum;

	// 1サブピクセルに対するサンプリング回数
	constexpr int sampleNum = 4;

// #pragma omp parallel for schedule(dynamic, 1) num_threads(4)
	for( int y = 0; y < width; ++y ){
		std::cout << "[ " << ( 100 * y / width ) << " % ]\n";

		for( int x = 0; x < width; ++x ){
			const int pixelIndex = ( width - y - 1 ) * length + x;

			// 1ピクセルをサブピクセルに分割して計算処理
			for( int sWidth = 0; sWidth < pixelDivNum; ++sWidth ){
				for( int sLength = 0; sLength < pixelDivNum; ++sLength ){
					Color accRadiance;

					// サブピクセルに対して何度かサンプリング　平均値をとるため
					for( int s = 0; s < sampleNum; ++s ){
						const double r1 = sLength * invPixelDivNum + invPixelDivNum / 2.0;
						const double r2 = sWidth * invPixelDivNum + invPixelDivNum / 2.0;

						// スクリーン上におけるこのピクセルの位置
						const Vector3 screenPos = screenCenter
							+ screenX * ( ( r1 + x ) / length - 0.5 )
							+ screenY * ( ( r2 + y ) / width - 0.5 );

						// レイを飛ばす方向
						const Vector3 rayDir = ( screenPos - cameraPos ).NormalizedVector();

						// 最終的な放射輝度
						accRadiance = accRadiance + Radiance( Ray( cameraPos, rayDir ), rnd, 0 ) / ( sampleNum * pixelDivNum * pixelDivNum );
					}
					pixelData[pixelIndex] = pixelData[pixelIndex] + accRadiance;
				}
			}
		}
	}

	GeneratePpmFile( pixelData, length, width );
	delete[] pixelData;
}