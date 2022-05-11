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

    std::cout << enc_input << std::endl;

    delete enc;
    delete file;
}