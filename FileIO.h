#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>
#include <fstream>

class FileIO {
    private:
        std::string _filename;
        std::string _write_string;
    public:
        FileIO(std::string filename);
        void setFilename(std::string filename);
        std::string getFilename();

        void setWriteString(std::string write_string);
        
        //Reads a file in the form of a string with no newlines
        std::string readFile();
        //Writes a file in the form of a string with no newlines
        void writeFile();
};

#endif