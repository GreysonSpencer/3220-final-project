#include <iostream>

#include "AES.h"
#include "Encryptor.h"
#include "FileIO.h"

int main()
{
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("test.txt");

    FileIO test("test.txt");

    std::cout << test.readFile() << std::endl;

    delete enc;
}