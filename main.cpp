#include <iostream>

#include "AES.h"
#include "Encryptor.h"
#include "FileIO.h"

int main()
{
    FileIO *file = new FileIO("test.txt");
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    std::string input = file->readFile();

    std::string enc_input = enc->encrypt(input);

    delete enc;
    delete file;
}