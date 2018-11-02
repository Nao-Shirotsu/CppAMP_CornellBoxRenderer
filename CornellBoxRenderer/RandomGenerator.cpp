#include "RandomGenerator.hpp"

namespace CBR{

RandomGenerator::RandomGenerator():
	engine( std::make_unique<std::mt19937>( std::random_device()( ) ) ),
	distRnd( std::make_unique<std::uniform_real_distribution<>>( 0.0, 1.0 ) ){}

double RandomGenerator::operator()() const{
	return ( *distRnd )( *engine );
}

}