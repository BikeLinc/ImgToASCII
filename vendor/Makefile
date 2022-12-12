#  Makefile for building OpenCV for ImgToASCII
#
#  Lincoln Scheer and Lucien Verrone
#
#  This makefile concatonates the cmake build and makefile run process for
#  building OpenCV for use with ImgToASCII.
#
#  Compatibility Statement: 
#  This makefile makes no promises that this will work on any systems other than
#  unix-based operating systems. This file is sucessfull in compiling on Ubuntu 
#  and MacOS systems.
#

all: opencv_cmake opencv

opencv_cmake:
	cd .. && rm -rf build && mkdir build
	cd .. && cd build && mkdir opencv_build
	cd .. && cd build && cd opencv_build && cmake ../../vendor/opencv-4.4.0

opencv:
	cd .. && cd build && cd opencv_build && make -j7

clean:
	cd .. && cd build && rm -rf opencv_build












