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

    // Read all of the input stream into the output string sink
    CryptoPP::FileSource fs(input, true, new CryptoPP::StringSink(output));
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
    std::ifstream stream(_filename, std::ios::binary);

    if(!stream.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        CryptoPP::SecByteBlock emptyKey(0);
        return emptyKey;
    }

    // Create the key space and then pump it in from the file
    CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::FileSource fs(stream, true, new CryptoPP::ArraySink(key.begin(), key.size()));

    return key;
}

void FileIO::writeKey(CryptoPP::SecByteBlock key)
{
    std::ofstream output(_filename, std::ios::binary);

    if(!output.is_open())
    {
        std::cout << "Failed to open file: " << _filename << std::endl;
        return;
    }
    
    // Create a sink on the ofstream and then put each byte into the file
    CryptoPP::FileSink sink(output);
    for (unsigned int i = 0; i < key.size(); i++)
    {
        sink.Put(key[i]);
    }
}