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
        std::cout << "Failed to open file\n";
        return "";
    }

    std::string output;
    std::getline(input, output);
    return output;
}

void FileIO::writeFile()
{
    std::ofstream output;
    output.open("enc" + _filename);

    if(!output.is_open())
    {
        std::cout << "Failed to open file\n";
        return;
    }

    output << _write_string;
}