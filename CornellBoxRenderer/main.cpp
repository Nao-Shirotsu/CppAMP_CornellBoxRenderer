#include "Render.hpp"
#include "CameraInfo.hpp"
#include "ScreenInfo.hpp"
#include "ImageResolution.hpp"

int main(){
	Camera camera;
	ImageResolution image( 320, 240, 2, 4 );
	Screen screen( image, camera );

	RenderImage( "..\\image.ppm", image, camera, screen );
}