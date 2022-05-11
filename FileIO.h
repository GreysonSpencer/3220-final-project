#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>
#include <fstream>

#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

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

        CryptoPP::SecByteBlock readKey();
        void writeKey(CryptoPP::SecByteBlock key, CryptoPP::SecByteBlock iv);
};

#endif