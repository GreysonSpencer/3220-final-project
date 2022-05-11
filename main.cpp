#include <iostream>

#include "AES.h"
#include "Encryptor.h"
#include "FileIO.h"

int main()
{
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("test.txt");

    FileIO test1("test.txt");
    FileIO test2("test.txt.cipher");
    FileIO test3("test.txt.key");

    std::cout << test1.readFile() << std::endl;
    std::cout << test2.readFile() << std::endl;
    std::cout << test3.readFile() << std::endl;

    delete enc;
}