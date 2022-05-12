#include "RC6.h"

RC6::RC6()
{
    using namespace CryptoPP;

    SecByteBlock keyBlock(CryptoPP::RC6::DEFAULT_KEYLENGTH);
    SecByteBlock ivBlock(CryptoPP::RC6::BLOCKSIZE);

    AutoSeededRandomPool rng;
    rng.GenerateBlock(keyBlock, CryptoPP::RC6::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(ivBlock, CryptoPP::RC6::BLOCKSIZE);

    _key = keyBlock;
    _iv = ivBlock;
}

RC6::RC6(std::string keyFilename)
{
    using namespace CryptoPP;

    FileIO keyFile(keyFilename);
    _key = keyFile.readKey();
    _iv = SecByteBlock(CryptoPP::RC6::BLOCKSIZE);
}

void RC6::encrypt(std::string filename)
{
    using namespace CryptoPP;

    FileIO textFile(filename);

    std::string plaintext = textFile.readFile();

    try
    {
        CBC_Mode<RC6>::Encryption filter;
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void RC6::decrypt(std::string filename)
{

}