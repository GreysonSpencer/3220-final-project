#include <iostream>

#include "AES.h"
#include "Encryptor.h"
#include "FileIO.h"

int main()
{
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("test.exe");

    FileIO test("test.exe");

    std::cout << test.readFile() << std::endl;

    delete enc;
}