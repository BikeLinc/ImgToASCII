cmake_minimum_required(VERSION 2.8)
project( ImgToASCII )

set("OpenCV_DIR" "../build/opencv_build")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable( ImgToASCII ./src/main.cpp ./src/Image.cpp )
target_link_libraries( ImgToASCII ${OpenCV_LIBS} ${CURSES_LIBRARIES})