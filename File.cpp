#include "File.h"



void File::setinputFilePath(std::string filePath){
    this->inputFilePath = filePath;
}

void File::setoutputFilePath(std::string filePath){
    this->outputFilePath = filePath;
}

std::string File::getinputFilePath(){
    return this->inputFilePath;
}

std::string File::getoutputFilePath(){
    return this->outputFilePath;
}
