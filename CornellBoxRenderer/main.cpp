#include "Render.hpp"
#include "Camera.hpp"
#include "ImageResolution.hpp"

int main(){
	// necessary settings

	// image resolution and radiance-sampling number
	CBR::ImageResolution image( 320, 240, 2, 4 );

	// a camera that takes a screen
	CBR::Camera camera;

	// rendering of a picture from frontside
	CBR::RenderImage( "./CBfront.ppm", image, camera );


	// rendering of another angle picture
	camera.SetPos( -45.0, 45.0, 25.0 );
	camera.SetDirectionFront( 1.0, -0.75, -0.4 );
	camera.SetDirectionUp( 0.75, 1.0, 0.0 );

	CBR::RenderImage( "./CBlookdown.ppm", image, camera );
}