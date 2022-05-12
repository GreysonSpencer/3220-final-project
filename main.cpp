#include <iostream>
#include <unistd.h>

#include "AES.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include "FileIO.h"

int menu();
int flags(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << argc << argv[i] << std::endl;
    }
    
    // Encryption
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("test.txt");
    delete enc;

    FileIO test1("test.txt");
    FileIO test2("test.txt.cipher");
    FileIO test3("test.txt.key");

    //std::cout << test1.readFile() << std::endl;
    //std::cout << test2.readFile() << std::endl;
    //std::cout << test3.readFile() << std::endl;


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
    bool exitFlag = false;
    int selection = 0;
    while(!exitFlag)
    {
        std::cout << "<=========================>\n";
        std::cout << "Welcome to encryption menu:\n";
        std::cout << "<=========================>\n";
        std::cout << "Choose menu options for functionality or help for help: \n";
        std::cout << "1. Encrypt\n";
        std::cout << "2. Decrypt\n";
        std::cout << "3. Help\n";
        std::cout << "Enter a number: ";
        std::cin >> selection;

        switch(selection)
        {
            case 1:
                // Encryption
            break;

            case 2:
                // Decryption
            break;

            case 3:
                std::cout << "<=========================>\n";
                std::cout << "<=========================>\n";
                std::cout << "Help information:";
                std::cout << "This tool is used to encrypt single line text files with symmetric encryption schemes.\n";
                std::cout << "Current implemented encryption schemes: \n";
                std::cout << "AES encryption\n\n\n";
                std::cout << "To use the menu, enter a number and press enter.";
                sleep(5);
            break;

            default:
                std::cout << "Selection " << selection << " is not a valid selection.\n";
                sleep(2);
            break;
        }
    }
    return 1;
}

// int flags(int argc, char* argv[])
// {

// }