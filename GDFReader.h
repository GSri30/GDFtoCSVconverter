#ifndef GDFREADER_H_
#define GDFREADER_H_

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include "Graph.h"
#include "File.h"

using namespace std;

#define NODEDEF "nodedef>"
#define EDGEDEF "edgedef>"

class GDFReader:public File{
    //Constructors
    public:
        GDFReader();
        GDFReader(string,string);
        ~GDFReader();
    
    //Private inline helper function to trim a given string
    private:
        inline string trim(string);

    //Main function which converts the .gdf to .csv
    public:
        void ModifyFile()override;
};

#endif