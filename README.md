# CornellBoxRenderer
     
### 概要 Overview
Visual C++でパストレーシング法というレンダリング手法を用いて       
コーネルボックスが描画されたppm形式画像を出力します。     
These C++ codes create a .ppm image that a 3D cornell box renders with the Path-tracing.     
     
### ビルド Build
C++17対応コンパイラでビルドできます。一部OpenMPを利用していますので、コンパイル時には各種オプションをお付けください。    
Visual Studioを使用する場合は後述のプロジェクトファイルを読み込み、ビルドできます。     
You can build with any C++ compiler that can handle C++17.     
Source codes need only standard library and compiling option for the OpenMP, so please put it.     
If you use Visual Studio, Please load the project file and build.
     
### ソースコード Source codes
CornellBoxRendererディレクトリ下に全てのソースコードとVisual Studioプロジェクトファイルがあります。     
You can find all C++ source and .vcxproj files under the CornellBoxRenderer directory.     
     
### 使い方 How to use
以下のコードで画像を描き出します。     
You can create an image by following code.

```cpp
#include "Render.hpp"
#include "Camera.hpp"
#include "ImageResolution.hpp"

int main(){
  // defines resolution of an image you want to create.
	CBR::ImageResolution image( 320, 240, 2, 4 ); 
  
  // initialize a camera that looks 3D space
	CBR::Camera camera;
  
  // rendering
	CBR::RenderImage( "..\\CBfront.ppm", image, camera );
}
```

各クラス/関数の説明
Description of each class and function:

`CBR::ImageResolution image( 320, 240, 2, 4 );`
  [1st parameter] x (length) of resolotion of an image
  [2nd parameter] y (width) of resolotion of an image
  [3rd parameter] number of subpixels N : this program calculates color of one pixel divided N*N subpixels
  [4th parameter] number of sampling times by one subpixel
     
