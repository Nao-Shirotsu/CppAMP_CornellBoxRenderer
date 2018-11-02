#include "Ray.hpp"
#include "Color.hpp"
#include "RandomGenerator.hpp"

namespace CBR{

// ray方向からの放射輝度を求める
Color Radiance( const Ray& ray, const RandomGenerator& rnd, const int depth );

}