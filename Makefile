## Makefile for ImgToASCII Program
#
#
#  Authored: Lincoln Scheer and Lucien Verrone
#  
#  Breif: This makefile may take some time to complete. This program will
#  first compile OpenCV v4.4.0 before compiling the ImgToASCII program.
#
#  Compatibility Statement: This makefile has only been tested on MacOS and
#  and WSL (Windows Subsystem for Linux) and Linux Mint and had no promise 
#  for compatibility with windows computers.
#
#  OpenCV: Version 4.4.0 was chosen for compatibility with MacOS 10.15 and 
#  as newer versions cannot be sucessfully compiled with the old xcode compiler.
#

##
## OpenCV
##

opencv_cmake:
	rm -rf build && mkdir build
	cd build && mkdir opencv_build
	cd build && cd opencv_build && cmake ../../vendor/opencv-4.4.0


opencv:
	cd build && cd opencv_build && make -j7

##
## Comapile ImgToASCII with OpenCV
##

program: build/opencv_build/opencv2/opencv_modules.hpp
	cd program && rm -rf build
	cd program && mkdir build
	cd program && cd build && cmake -D CMAKE_PREFIX_PATH=../build/opencv_build ..
	cd program && cd build && make -j7

program_run:
	./program/build/ImgToASCII ./program/res/image.png

##
## ALL
##

all: opencv_cmake opencv program program_run










