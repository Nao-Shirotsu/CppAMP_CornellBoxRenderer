#pragma once
#include <string>

#include "Camera.hpp"
#include "Screen.hpp"
#include "ImageResolution.hpp"

namespace CBR{

// CornellBoxを表現する画像を描き出す
void RenderImage( const std::string& filename, const ImageResolution& image, const Camera& camera );

}