#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <iostream>
#include<fstream>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *
 * virtual Base Class stores (input/output)FilePath   *
 *                                                    *
 * @func ModifyFile : pure virtual function           *
 *                  : to Modify File to required spec *
 *                  : @parms none ,@return void       *
 *                                                    *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


class File{
    private:
        std::string inputFilePath;
        std::string outputFilePath;

    public:
        virtual void ModifyFile() = 0;
        void setinputFilePath(std::string);
        void setoutputFilePath(std::string);
        std::string getinputFilePath();
        std::string getoutputFilePath();
};


#endif // FILE_H_INCLUDED
