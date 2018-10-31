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
	const Vector3 cameraPos( 0.0, 0.0, -49.0 );
	const Vector3 cameraDirFront = Vector3( 0.0, 0.0, 1.0 ).NormalizedVector();
	const Vector3 cameraDirUp( 0.0, 1.0, 0.0 );

	// スクリーン幅
	const double screenLength = 62.0 * length / width;
	constexpr double screenWidth = 62.0;

	// カメラ～スクリーン距離
	constexpr double distanceCamToScr = 40.0;

	// スクリーン設定
	const Vector3 screenX = Cross( cameraDirFront, cameraDirUp ).NormalizedVector() * screenLength;
	const Vector3 screenY = Cross( screenX, cameraDirFront ).NormalizedVector() * screenWidth;
	const Vector3 screenCenter = cameraPos + cameraDirFront * distanceCamToScr;

	// 出力画像データをピクセル単位で保存するバッファ
	Color* pixelData = new Color[length * width];

	// 描画の進行度
	int renderedPersent = 0;
	std::cout << "Now rendering... \n";

	// 1ピクセルに対する分割数(スーパーサンプリング数) n*n = サブピクセル数
	constexpr int pixelDivNum = 4;

	// pixelDivNumの逆数
	constexpr double invPixelDivNum = 1.0 / pixelDivNum;

	// 1サブピクセルに対するサンプリング回数
	constexpr int sampleNum = 6;

	// メインの計算処理 OpenMPで並列処理
	#pragma omp parallel for schedule(dynamic, 1) num_threads(4)
	for( int y = 0; y < width; ++y ){

		// 描画進行度の表示
		if( int persent = double( y ) / width * 100.0; persent > renderedPersent ){
			std::cout << "[ " << persent << " % ]\n";
			renderedPersent = persent;
		}

		RandomGenerator rnd;

		for( int x = 0; x < length; ++x ){
			const int pixelIndex = ( width - y - 1 ) * length + x;
			Color&& accRadiance = Color();

			// 1ピクセルをサブピクセルに分割して計算処理
			for( int subY = 0; subY < pixelDivNum; ++subY ){
				for( int subX = 0; subX < pixelDivNum; ++subX ){
					// サブピクセルに対して何度かサンプリング　平均値をとるため
					for( int s = 0; s < sampleNum; ++s ){
						const double r1 = subX * invPixelDivNum + invPixelDivNum / 2.0;
						const double r2 = subY * invPixelDivNum + invPixelDivNum / 2.0;

						// スクリーン上におけるこのピクセルの位置
						const Vector3 screenPos = screenCenter + 
												  screenX * ( ( r1 + x ) / length - 0.5 ) +
												  screenY * ( ( r2 + y ) / width - 0.5 );

						// レイを飛ばす方向
						const Vector3 rayDir = ( screenPos - cameraPos ).NormalizedVector();

						// 最終的な放射輝度
						accRadiance = accRadiance + Radiance( Ray( cameraPos, rayDir ), rnd, 0 ) / ( sampleNum * pixelDivNum * pixelDivNum );
					}
				}
			}
			pixelData[pixelIndex] = pixelData[pixelIndex] + accRadiance;
		}
	}

	GeneratePpmFile( pixelData, length, width );
	delete[] pixelData;
}