// Image.cpp
//
// Lincoln Scheer
// Lucien Verrone

#include "Image.h"

Image::Image(std::string filename) {
    loadImage(filename);
}

void Image::loadImage(std::string filename) {
    pixelBuffer = cv::Mat(cv::imread(filename, 1));
    if (!pixelBuffer.data) {
        printf("No image data \n");
        exit (1);
    } else {
        height = pixelBuffer.rows;
        width = pixelBuffer.cols;
        printf("Image Sucessfully Loaded \n");
    }
}

void Image::asciiToHTML(std::string filename) {
    char asciiBuffer[width*3][height];

    // Loop through pixel buffer array
    for (int x = 0; x <= height; x = x + 3) {
        for (int y = 0; y <= width; y++) {

            // Compute grayscale by averaging RGB triplets
            int b = pixelBuffer.at<cv::Vec3b>(x, y)[0];
            int g = pixelBuffer.at<cv::Vec3b>(x, y)[1];
            int r = pixelBuffer.at<cv::Vec3b>(x, y)[2];
            unsigned int a = ((b + r + g)/3);

            // Match gradient to 30 different ascii character depending on grayscale value.
            int range = 255/30;
            char asciiAssigned;
            if (a < range) { asciiAssigned = '`'; }
            else if (a <= range*1) { asciiAssigned = '.'; }
            else if (a <= range*2) { asciiAssigned = '\''; } 
            else if (a <= range*3) { asciiAssigned = '\"'; } 
            else if (a <= range*4) { asciiAssigned = ':'; }
            else if (a <= range*5) { asciiAssigned = 'l'; } 
            else if (a <= range*6) { asciiAssigned = '!'; } 
            else if (a <= range*7) { asciiAssigned = '<'; }
            else if (a <= range*8) { asciiAssigned = '+'; } 
            else if (a <= range*9) { asciiAssigned = '?'; }
            else if (a <= range*10) { asciiAssigned = ']'; }
            else if (a <= range*11) { asciiAssigned = '{'; } 
            else if (a <= range*12) { asciiAssigned = ')'; } 
            else if (a <= range*13) { asciiAssigned = '\\'; }
            else if (a <= range*14) { asciiAssigned = 'j'; } 
            else if (a <= range*15) { asciiAssigned = 'x'; } 
            else if (a <= range*16) { asciiAssigned = 'v'; }
            else if (a <= range*17) { asciiAssigned = 'c'; } 
            else if (a <= range*18) { asciiAssigned = 'Y'; }
            else if (a <= range*19) { asciiAssigned = 'J'; }
            else if (a <= range*20) { asciiAssigned = 'Q'; }
            else if (a <= range*21) { asciiAssigned = '0'; }
            else if (a <= range*22) { asciiAssigned = 'm'; }
            else if (a <= range*23) { asciiAssigned = 'q'; }
            else if (a <= range*24) { asciiAssigned = 'b'; }
            else if (a <= range*25) { asciiAssigned = 'k'; }
            else if (a <= range*26) { asciiAssigned = 'o'; }
            else if (a <= range*27) { asciiAssigned = '#'; }
            else if (a <= range*28) { asciiAssigned = '%'; }
            else if (a <= range*29) { asciiAssigned = '@'; }
            else if (a <= range*30) { asciiAssigned = '$'; }

            // Set three pixels in map to compensate for character size ratio,
            asciiBuffer[x][y] = asciiAssigned;
            asciiBuffer[x+1][y] = asciiAssigned;
            asciiBuffer[x+2][y] = asciiAssigned;
        }
    }
    std::ofstream htmlOut;
    htmlOut.open (filename);
    htmlOut << "<!DOCTYPE html><html><head></head><body style=\"font-family: monospace;background:black;\">"; //starting html
    for (int x = 0; x <= width; x++) {
        htmlOut << "<div>";
        for (int y = 0; y <= height; y++) {
            int b = pixelBuffer.at<cv::Vec3b>(x, y)[0];
            int g = pixelBuffer.at<cv::Vec3b>(x, y)[1];
            int r = pixelBuffer.at<cv::Vec3b>(x, y)[2];
            htmlOut << "<span style=\"color:rgb(" << r << ", "<< g << ", "<< b << ");\">"<< asciiBuffer[x][y] << "</span>";
        }
        htmlOut << "</div>";
    }
    htmlOut << "</body></html>";
    htmlOut.close();
}
