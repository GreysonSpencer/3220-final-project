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
        menu();
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
        std::cout << "Welcome to insert name here:\n";
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
            {
                std::cout << "<=========================>\n";
                std::cout << "<=========================>\n";
                std::cout << "What kind of encryption to you want to use?\n";
                std::cout << "1. AES\n";
                std::cout << "2. Back to main menu\n";
                std::cout << "Enter a number: ";
                int encSelection;
                std::cin >> encSelection;
                switch(encSelection)
                {
                    case 1:
                    {
                        std::string encFilename;
                        std::cout << "Enter a filename to be encrypted with AES encryption: ";
                        std::cin >> encFilename;

                        AES *aes = new AES();
                        Encryptor *enc = new Encryptor(aes);

                        enc->encrypt(encFilename);
                        delete enc;

                        std::cout << "Encrypted file is called: " << encFilename << ".cipher\n";
                        std::cout << "Encryption key is called: " << encFilename << ".key\n";
                        break;
                    }

                    case 2:
                    break;

                    default:
                        std::cout << "Selection " << encSelection << " is not a valid selection.\n";
                    break;
                }
                break;
            }

            case 2:
            {
                std::cout << "<=========================>\n";
                std::cout << "<=========================>\n";
                std::cout << "What kind of encryption was used to encrypt the file?\n";
                std::cout << "1. AES\n";
                std::cout << "2. Back to main menu\n";
                std::cout << "Enter a number: ";
                int decSelection;
                std::cin >> decSelection;
                switch(decSelection)
                {
                    
                }
                break;
            }

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