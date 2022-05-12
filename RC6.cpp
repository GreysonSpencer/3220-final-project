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

}

void RC6::encrypt(std::string filename)
{

}

void RC6::decrypt(std::string filename)
{

}