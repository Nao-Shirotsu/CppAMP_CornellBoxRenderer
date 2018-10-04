#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "PPMhandler.h"

void GeneratePpmFile( const RenderingData* color, const int length, const int width ){
	std::ofstream ofs( "../cornell_box.ppm" );

	if( !ofs ){
		std::exit( 1 );
		std::cerr << "ERROR : file open failed." << std::endl;
	}

	ofs << "P3\n" << length << " " << width << "\n255\n";
	for( int i = 0; i < length * width; ++i ){
		ofs << ToPixelValue( color[i].x ) << " "
			<< ToPixelValue( color[i].y ) << " "
			<< ToPixelValue( color[i].z ) << "\n";
	}

	ofs.close();
	std::cout << "Rendering succeeded : written to \"cornell_box.ppm\"" << std::endl;
}

int ToPixelValue( double n ){
	if( n < 0.0 ){
		n = 0.0;
	}

	if( n > 1.0 ){
		n = 1.0;
	}

	return int( std::pow( n, 1.0 / 2.2 ) * 255 );
}
