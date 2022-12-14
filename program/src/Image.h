// Image.h
//
// Lincoln Scheer
// Lucien Verrone

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <fstream>


#ifndef _IMAGE_H_
#define _IMAGE_H_

// This class imports the image into a pixel buffer and converts
// it to a html page reperesentation of the image.
class Image {

public:
    // Instantiate a new image into a pixel buffer.
    Image(std::string filename);

    // Converts pixel buffer into a ascii character mathod
    void asciiToHTML(std::string filename);

private:
    cv::Mat pixelBuffer;
    int height;
    int width;

    // Load the image into a pixel buffer
    void loadImage(std::string filename);

};

#endif /* _IMAGE_H_ */