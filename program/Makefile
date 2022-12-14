#  Makefile for building ImgToASCII
#
#  Lincoln Scheer and Lucien Verrone
#
#  This makefile is for building the ImgToASCII source code. Please make sure
#  that you have sucessfully ran the makefile in the ./build/ directory to 
#  compile the required OpenCV libary and dependencies.
#
#  Compatibility Statement: 
#  This makefile makes no promises that this will work on any systems other than
#  unix-based operating systems. This file is sucessfull in compiling on Ubuntu 
#  and MacOS systems.
#

all: program

program:
	rm -rf build && mkdir build
	cd build && cmake -D CMAKE_PREFIX_PATH=../build/opencv_build ..
	cd build && make -j7

run:
	./build/ImgToASCII

build_run: program run

clean: 
	rm -rf build