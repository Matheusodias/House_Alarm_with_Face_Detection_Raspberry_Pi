cmake_minimum_required(VERSION 2.8)
project( Faces )
find_package( raspicam REQUIRED )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Faces Faces.cpp )
target_link_libraries( Faces ${OpenCV_LIBS}
			     ${raspicam_LIBS} )
