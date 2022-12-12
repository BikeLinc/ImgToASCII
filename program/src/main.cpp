// ImgToASCII
//
// main.cpp
//
// Lincoln Scheer and Lucien Verrone
//
// Compile with:    make program
// Run with:        make run

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv ) {


    // Load image with OpenCV
    Mat image = imread( "res/trollface.jpg", 1 );
    if ( !image.data ) {
        printf("No image data \n");
        return -1;
    } else {
        printf("Image Sucessfully Loaded \n");

        // Try to read through pixel values in matrix

        int imageWidth = image.cols;
        int imageHeight = image.rows;



        char asciiMap[imageWidth][imageHeight * 2];

        for (int x = 0; x <= 160; x = x + 2) {
            for (int y = 0; y <= 240; y++) {
                int b = image.at<Vec3b>(x, y)[0];//getting the pixel values//
                int g = image.at<Vec3b>(x, y)[1];//getting the pixel values//
                int r = image.at<Vec3b>(x, y)[2];//getting the pixel values//
                //std::cout << "Value of blue channel:" << b << std::endl;//showing the pixel values//
                //std::cout << "Value of green channel:" << g << std::endl;//showing the pixel values//
                //std::cout << "Value of red channel:" << r << std::endl;//showing the pixel values//

                unsigned int a = ((b + r + g)/3);


                int range = 255/3;
                char asciiAssigned;
                if (a < range) {

                    asciiAssigned = '`';
                }
                
                else if (a <= range*2) {

                    asciiAssigned = '^';

                }

                else if (a <= range*3){

                    asciiAssigned = '\\'; // written as '\'

                } 
                
                else if (a <= range*4) {

                    asciiAssigned = '_';

                } 
                
                else if (a <= range*5) {

                    asciiAssigned = 'a';
                    
                }


                asciiMap[x][y] = asciiAssigned;
                asciiMap[x+1][y] = asciiAssigned;
                std::cout << asciiAssigned;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}