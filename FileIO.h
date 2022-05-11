#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>

class FileIO {
    private:
        std::string _filename;
        std::string _write_string;
    public:
        FileIO(std::string filename);
        void setFilename(std::string filename);
        std::string getFilename();

        void setWriteString(std::string write_string);
        
        std::string readFile();
        void writeFile();
};

#endif