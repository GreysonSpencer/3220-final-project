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
                std::cout << "AES encryption\n";
                std::cout << "RC6 encryption\n\n";
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
            if(i+1 < argc)
            {
                i++;
                std::string encFilename = argv[i];
                if(encFilename.find(".txt") != std::string::npos)
                {
                    return aesEnc(encFilename);
                }
                else
                {
                    std::cout << "-aesE requires a text file following the flag, encryption failed.\n";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                std::cout << "-aesE requires a text file following the flag, encryption failed.\n";
                return EXIT_FAILURE;
            }
        }
        else if(input == "-aesD")
        {
            if(i+2 < argc)
            {
                i++;
                std::string decFilename = argv[i];
                i++;
                std::string keyFilename = argv[i];
                if(decFilename.find(".txt.cipher") != std::string::npos)
                {
                    if(keyFilename.find(".txt.key") != std::string::npos)
                    {
                        return aesDec(decFilename, keyFilename);
                    }
                    else
                    {
                        // Key file wrong
                        std::cout << "Key file must be in the format of <filename>.txt.key\n";
                        return EXIT_FAILURE;
                    }
                }
                else
                {
                    // Cipher file wrong
                    std::cout << "Cipher file must be in the format of <filename>.txt.cipher\n";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                // Not enough inputs
                std::cout << "-aesD requires a cipher file and a key file following the argument, decryption failed.\n";
                return EXIT_FAILURE;
            }
        }
        else if(input == "-rc6E")
        {
            if(i+1 < argc)
            {
                i++;
                std::string encFilename = argv[i];
                if(encFilename.find(".txt") != std::string::npos)
                {
                    return rc6Enc(encFilename);
                }
                else
                {
                    std::cout << "-rc6E requires a text file following the flag, encryption failed.\n";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                std::cout << "-rc6E requires a text file following the flag, encryption failed.\n";
                return EXIT_FAILURE;
            }
        }
        else if(input == "-rc6D")
        {
            if(i+2 < argc)
            {
                i++;
                std::string decFilename = argv[i];
                i++;
                std::string keyFilename = argv[i];
                if(decFilename.find(".txt.cipher") != std::string::npos)
                {
                    if(keyFilename.find(".txt.key") != std::string::npos)
                    {
                        return rc6Dec(decFilename, keyFilename);
                    }
                    else
                    {
                        // Key file wrong
                        std::cout << "Key file must be in the format of <filename>.txt.key\n";
                        return EXIT_FAILURE;
                    }
                }
                else
                {
                    // Cipher file wrong
                    std::cout << "Cipher file must be in the format of <filename>.txt.cipher\n";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                // Not enough inputs
                std::cout << "-rc6D requires a cipher file and a key file following the argument, decryption failed.\n";
                return EXIT_FAILURE;
            }
        }
        else if(input == "-h")
        {
            // Help info
            std::cout << "Help information: \n";
            std::cout << "Encryption supported by this tool: AES and RC6\n";
            std::cout << "To encrypt files, use arguments: \n";
            std::cout << "-aesE \"filename\"\n";
            std::cout << "-rc6E \"filename\"\n";
            std::cout << "To decrypt files, use arguments: \n";
            std::cout << "-aesD \"filename\" \"key filename\"\n";
            std::cout << "-rc6D \"filename\" \"key filename\"\n";
            return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Invalid arguments, try running with \"-h\" for help.\n";
            return EXIT_FAILURE;
        }
    }
    return EXIT_FAILURE;
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