#include "FileIO.h"

FileIO::FileIO(std::string filename)
{
    _filename = filename;
}

void FileIO::setFilename(std::string filename)
{
    _filename = filename;
}

std::string FileIO::getFilename()
{
    return _filename;
}

void FileIO::setWriteString(std::string write_string)
{
    _write_string = write_string;
}

std::string FileIO::readFile()
{
    std::ifstream input;
    input.open(_filename);

    if(!input.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        return "";
    }

    std::string output;
    std::getline(input, output);
    return output;
}

void FileIO::writeFile()
{
    std::ofstream output;
    output.open(_filename);

    if(!output.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        return;
    }

    output << _write_string;
}

CryptoPP::SecByteBlock FileIO::readKey()
{
    // std::ifstream input;
    // input.open(_filename);

    // if(!input.is_open())
    // {
    //     std::cout << "Failed to open file: " << _filename << std::endl;
    //     CryptoPP::SecByteBlock emptyKey(0);
    //     return emptyKey;
    // }

    // CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
    // input >> key;

    CryptoPP::SecByteBlock newKey(CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::FileSource fs(_filename.c_str(), true, new CryptoPP::ArraySink(newKey.begin(), newKey.size()));



    return newKey;
}

CryptoPP::SecByteBlock FileIO::readIV()
{
    std::ifstream input;
    input.open(_filename);

    if(!input.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        CryptoPP::SecByteBlock emptyKey(0);
        return emptyKey;
    }

    CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
    input >> key;

    CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
    input >> iv;

    return iv;
}

void FileIO::writeKey(CryptoPP::SecByteBlock key, CryptoPP::SecByteBlock iv)
{
    std::ofstream output;
    output.open(_filename);

    if(!output.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        return;
    }
    
    for (unsigned int i = 0; i < key.size(); i++)
    {
        output << key.data()[i];
    }
    output << "\n";

    for (unsigned int i = 0; i < iv.size(); i++)
    {
        output << iv.data()[i];
    }
}