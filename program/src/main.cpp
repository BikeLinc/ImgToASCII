// main.cpp
//
// Lincoln Scheer
// Lucien Verrone


#include <stdio.h>
#include "Image.h"


// Demo Showing Image Conversion Class
int main(int argc, char** argv ) {
    std::string message;
    std::cout << "Image for Processing w/o Path:" ;
    std::getline( std::cin, message );
    Image image("res/" + message);
    std::cout << "Image to Save:" ;
    std::getline( std::cin, message );
    image.asciiToHTML(message + ".html");
    image.~Image();
    return 0;
}