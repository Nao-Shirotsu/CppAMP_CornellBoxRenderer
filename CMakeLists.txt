cmake_minimum_required(VERSION 3.10)
project(CBR462)

find_package(OpenMP)
if (OPENMP_FOUND) 
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(cbr462
	CornellBoxRenderer/main.cpp
	CornellBoxRenderer/Camera.cpp
	CornellBoxRenderer/ImageResolution.cpp
	CornellBoxRenderer/Intersection.cpp
	CornellBoxRenderer/PPMHandler.cpp
	CornellBoxRenderer/Radiance.cpp
	CornellBoxRenderer/RandomGenerator.cpp
	CornellBoxRenderer/Ray.cpp
	CornellBoxRenderer/Render.cpp
	CornellBoxRenderer/Scene.cpp
	CornellBoxRenderer/Screen.cpp
	CornellBoxRenderer/Sphere.cpp
	CornellBoxRenderer/Vector.cpp
)
