cmake_minimum_required(VERSION 2.8)
project( ImgToASCII )

set("OpenCV_DIR" "../build/opencv_build")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ImgToASCII ./src/main.cpp )
target_link_libraries( ImgToASCII ${OpenCV_LIBS} )