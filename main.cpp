#include<iostream>
using namespace std;
#include "GDFReader.h"

int main(){

    string inputPath,outputPath;

    cin>>inputPath>>outputPath;

    size_t pos =  inputPath.find(".");
    string token ;
    token = inputPath.substr(pos + 1, inputPath.size());

    GDFReader*g=new GDFReader(inputPath,outputPath);
    g->ModifyFile();    

    return 0;
}