#ifndef FILEIO_H
#define FILEIO_H

#include <string>

class FileIO {
    private:
        std::string filename;
    public:
        FileIO(std::string filename);
        void setFilename(std::string filename);
        std::string getFilename();
};

#endif