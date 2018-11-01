#pragma once
#include <string>

#include "CameraInfo.hpp"
#include "ScreenInfo.hpp"
#include "ImageResolution.hpp"

// 画像を描き出す
void RenderImage( const std::string& filename, const ImageResolution& image, const Camera& camera, const Screen screen );