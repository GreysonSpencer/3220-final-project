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

}

void FileIO::writeFile()
{

}