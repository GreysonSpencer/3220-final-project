#include <iostream>
#include <unistd.h>

#include "AES.h"
#include "RC6.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include "FileIO.h"

int menu();
int flags(int argc, char* argv[]);
int aesEnc(std::string filename);
int aesDec(std::string filename, std::string keyFilename);
int rc6Enc(std::string filename);
int rc6Dec(std::string filename, std::string keyFilename);


int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << argc << argv[i] << std::endl;
    }

    if(argc < 2)
    {
        return menu();
    }
    else
    {
        return flags(argc, argv);
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
        std::cout << "4. Exit\n";
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
                std::cout << "2. RC6\n";
                std::cout << "3. Back to main menu\n";
                std::cout << "Enter a number: ";
                int encSelection;
                std::cin >> encSelection;
                switch(encSelection)
                {
                    case 1:
                    {
                        // AES
                        std::string encFilename;
                        std::cout << "Enter a filename to be encrypted with AES encryption: ";
                        std::cin >> encFilename;

                        aesEnc(encFilename);
                        sleep(3);
                        break;
                    }

                    case 2:
                    {
                        // RC6
                        std::string encFilename;
                        std::cout << "Enter a filename to be encrypted with RC6 encryption: ";
                        std::cin >> encFilename;

                        rc6Enc(encFilename);
                        sleep(3);
                        break;
                    }

                    case 3:
                        //Back to main loop
                    break;

                    default:
                        std::cout << "Selection " << encSelection << " is not a valid selection.\n";
                        sleep(1);
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
                std::cout << "2. RC6\n";
                std::cout << "3. Back to main menu\n";
                std::cout << "Enter a number: ";
                int decSelection;
                std::cin >> decSelection;
                switch(decSelection)
                {
                    case 1:
                    {
                        // AES
                        std::string decFilename;
                        std::cout << "Enter the file you wish to decrypt: ";
                        std::cin >> decFilename;

                        std::string decKey;
                        std::cout << "Enter the file that contains the private key: ";
                        std::cin >> decKey;

                        aesDec(decFilename, decKey);
                        sleep(2);
                        break;
                    }

                    case 2:
                    {
                        // RC6
                        std::string decFilename;
                        std::cout << "Enter the file you wish to decrypt: ";
                        std::cin >> decFilename;

                        std::string decKey;
                        std::cout << "Enter the file that contains the private key: ";
                        std::cin >> decKey;

                        rc6Dec(decFilename, decKey);
                        sleep(2);
                        break;
                    }

                    case 3:
                        // Back to main loop
                    break;

                    default:
                    break;
                }
                break;
            }

            case 3:
                std::cout << "<=========================>\n";
                std::cout << "<=========================>\n";
                std::cout << "Help information:";
                std::cout << "This tool is used to encrypt single line text files with symmetric encryption schemes.\n";
                std::cout << "Current implemented encryption schemes: \n";
                std::cout << "AES encryption\n\n";
                std::cout << "To use the menu, enter a number and press enter.\n";
                sleep(5);
            break;

            case 4:
                std::cout << "Exiting encryption program...\n";
                sleep(2);
                return EXIT_SUCCESS;
            break;

            default:
                std::cout << "Selection " << selection << " is not a valid selection.\n";
                sleep(2);
            break;
        }
    }
    return 1;
}

// Command line flags support:
// 1 option when showing help
// 2 options when encrypting: enc type and file name
// 3 options when decrypting: dec type and file name and key file name
int flags(int argc, char* argv[])
{
    // More flags than allowed
    if(argc > 4)
    {
        std::cout << "Too many arguments provided, exiting...\n";
        return EXIT_FAILURE;
    }

    std::string input = "";

    for (int i = 1; i < argc; i++)
    {
        input = argv[i];
        if(input == "-aesE")
        {
            // AES encryption
        }
        else if(input == "-aesD")
        {
            // AES decryption
        }
        else if(input == "-rc6E")
        {
            // RC6 encryption
        }
        else if(input == "-rc6D")
        {
            // RC6 decryption
        }
        else if(input == "-h")
        {
            // Help info
        }
        else
        {
            // invalid input
        }
    }
    
}

int aesEnc(std::string filename)
{
    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt(filename);
    delete enc;

    std::cout << "Encrypted file is called: " << filename << ".cipher\n";
    std::cout << "Encryption key is called: " << filename << ".key\n";
    return EXIT_SUCCESS;
}

int aesDec(std::string filename, std::string keyFilename)
{
    AES *aesDec = new AES(keyFilename);
    Decryptor *dec = new Decryptor(aesDec);

    dec->decrypt(filename);
    delete dec;
                        
    std::cout << "Decrypted file is located at: decoded_text.txt\n";
    return EXIT_SUCCESS;
}

int rc6Enc(std::string filename)
{
    RC6 *rc6 = new RC6();
    Encryptor *enc = new Encryptor(rc6);

    enc->encrypt(filename);
    delete enc;

    std::cout << "Encrypted file is called: " << filename << ".cipher\n";
    std::cout << "Encryption key is called: " << filename << ".key\n";
    return EXIT_SUCCESS;
}

int rc6Dec(std::string filename, std::string keyFilename)
{
    RC6 *rc6Dec = new RC6(keyFilename);
    Decryptor *dec = new Decryptor(rc6Dec);

    dec->decrypt(filename);
    delete dec;
                        
    std::cout << "Decrypted file is located at: decoded_text.txt\n";
    return EXIT_SUCCESS;
}