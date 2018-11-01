#include <iostream>
#include <string>

#include "Render.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "RandomGenerator.hpp"
#include "Ray.hpp"
#include "Radiance.hpp"
#include "PPMhandler.hpp"
#include "CameraInfo.hpp"
#include "ScreenInfo.hpp"
#include "ImageResolution.hpp"

void RenderImage( const std::string& filename, const ImageResolution& image, const Camera& camera, const Screen screen ){
	// 出力画像データをピクセル単位で保存するバッファ
	Color* pixelData = new Color[image.x * image.y];

	// 描画の進行度
	int renderedPersent = 0;
	std::cout << filename << "\nNow rendering... \n";

	// image.pixelDivNumの逆数
	const double invPixelDivNum = 1.0 / image.pixelDivNum;

	// メインの計算処理 OpenMPで並列処理
	#pragma omp parallel for schedule(dynamic, 1) num_threads(4)
	for( int y = 0; y < image.y; ++y ){

		// 描画進行度の表示
		if( int persent = static_cast< int >( double( y ) / image.y * 100.0 ); persent > renderedPersent ){
			std::cout << "[ " << persent << " % ]\n";
			renderedPersent = persent;
		}

		RandomGenerator rnd;

		for( int x = 0; x < image.x; ++x ){
			const int pixelIndex = ( image.y - y - 1 ) * image.x + x;
			Color&& accRadiance = Color();

			// 1ピクセルをサブピクセルに分割して計算処理
			for( int subY = 0; subY < image.pixelDivNum; ++subY ){
				for( int subX = 0; subX < image.pixelDivNum; ++subX ){
					// サブピクセルに対して何度かサンプリング　平均値をとるため
					for( int s = 0; s < image.sampleNum; ++s ){
						const double r1 = subX * invPixelDivNum + invPixelDivNum / 2.0;
						const double r2 = subY * invPixelDivNum + invPixelDivNum / 2.0;

						// スクリーン上におけるこのピクセルの位置
						const Vector3 pixelPos = screen.GetCenter() + 
												 screen.GetXvec() * ( ( r1 + x ) / image.x - 0.5 ) +
												 screen.GetYvec() * ( ( r2 + y ) / image.y - 0.5 );

						// レイを飛ばす方向
						const Vector3 rayDir = ( pixelPos - camera.pos ).NormalizedVector();

						// 最終的な放射輝度
						accRadiance = accRadiance + Radiance( Ray( camera.pos, rayDir ), rnd, 0 ) / ( image.sampleNum * image.pixelDivNum * image.pixelDivNum );
					}
				}
			}
			pixelData[pixelIndex] = pixelData[pixelIndex] + accRadiance;
		}
	}

	GeneratePpmFile( filename, pixelData, image.x, image.y );
	delete[] pixelData;
}
