# CornellBoxRenderer
     
### 概要 Overview
Visual C++でパストレーシング法というレンダリング手法を用いて       
コーネルボックスが描画されたppm形式画像を出力します。     
These C++ codes create a .ppm image that a 3D cornell box renders with a ray-tracing method called path-tracing.     
![Cornell Box 1](https://imgur.com/a/ZGbfPYD) ![Cornell Box 2](https://imgur.com/a/K8J5KfZ)
*****

### ビルド Build
C++17対応コンパイラでビルドできます。一部OpenMPを利用していますので、コンパイル時には各種オプションをお付けください。    
Visual Studioを使用する場合は後述のプロジェクトファイルを読み込み、ビルドできます。     
You can build with any C++ compiler that can handle C++17.     
Source codes need only standard library and compiling option for the OpenMP, so please put it.     
If you use Visual Studio, Please load the project file and build.     
*****

### ソースコード Source codes
CornellBoxRendererディレクトリ下に全てのソースコードとVisual Studioプロジェクトファイルがあります。     
You can find all C++ source and .vcxproj files under the CornellBoxRenderer directory.     
*****
     
### 使い方 How to use
以下のコードで画像を描き出します。     
You can create an image by following code.
```cpp
#include "Render.hpp"
#include "Camera.hpp"
#include "ImageResolution.hpp"

int main(){
	CBR::ImageResolution image( 320, 240, 2, 4 ); 
	CBR::Camera camera;
	CBR::RenderImage( "..\\CBfront.ppm", image, camera );
}
```     
*****
     
### 各クラス/関数の説明 Description of each class and function
`CBR::ImageResolution image( 320, 240, 2, 4 );`     

**第1引数** 出力される画像の解像度x     
**第2引数** 出力される画像の解像度y     
**第3引数** 画像1ピクセルに対するN: 1ピクセルの解像度をN×N個のサブピクセルに分けて計算します      
**第4引数** 1サブピクセルに対するサンプリング回数です。     
第3, 第4引数の数が大きければ大きいほど綺麗な画像を出力します。     
     
**1st parameter** x (length) of resolotion of an image     
**2nd parameter** y (width) of resolotion of an image     
**3rd parameter** number of subpixels N: this program calculates color of one pixel divided N*N subpixels     
**4th parameter** number of sampling times by one subpixel     
If 3rd and 4th parameters are greater, created images get more beautiful and clean     
*****
`CBR::Camera camera;`     
3D空間を映すカメラを初期化します。     
また、以下のようにカメラの位置、正面向きのベクトル、上向きのベクトルを再定義できます。     
This sentence initializes a camera instance which looks 3D space.     
You can redefine the camera. Then you need define the cameras direction to front and upside, and position.
```cpp
// 3D-coodinate (x, y, z)
camera.SetPos( -45.0, 45.0, 25.0 );
camera.SetDirectionFront( 1.0, -0.75, -0.4 );
camera.SetDirectionUp( 0.75, 1.0, 0.0 );
```     
*****
`CBR::RenderImage( "..\\CBfront.ppm", image, camera );`     
ファイルパスと前述の2つのインスタンスを引数に渡し、レンダリングを実行します。     
Implementation of rendering. you need to hand filepath and the two instances as 2nd and 3rd parameters.
