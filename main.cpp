#include <iostream>

#include "AES.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include "FileIO.h"

int menu();
int flags(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    // Encryption
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("test.txt");
    delete enc;

    FileIO test1("test.txt");
    FileIO test2("test.txt.cipher");
    FileIO test3("test.txt.key");

    std::cout << test1.readFile() << std::endl;
    std::cout << test2.readFile() << std::endl;
    std::cout << test3.readFile() << std::endl;


    // Decryption
    AES *aesDec = new AES("test.txt.key");
    Decryptor *dec = new Decryptor(aesDec);

    dec->decrypt("test.txt.cipher");
    delete dec;

    if(argc < 2)
    {
        // Run the CL menu
    }
    else
    {
        // Run the flag detection
    }
}

int menu()
{

}

int flags(int argc, char* argv[])
{

}