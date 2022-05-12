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

    std::string ciphertext;
    try
    {
        CBC_Mode<RC6>::Encryption filter;

        // Set key and initial vector for filter
        filter.SetKeyWithIV(_key, CryptoPP::RC6::DEFAULT_KEYLENGTH, _iv);

        // Take all the plaintext,
        // encrypt it with the filter,
        // then put it in the ciphertext string
        StringSource(plaintext, true, new StreamTransformationFilter(filter, new StringSink(ciphertext)));
    }
    catch(const Exception& e)
    {
        std::cerr << "RC6 encryption failed, error: \n" <<  e.what() << '\n';
        exit(1);
    }

    // Write key to key file
    std::string keyFilename;
    keyFilename = filename + ".key";

    FileIO keyFile(keyFilename);

    keyFile.writeKey(_key);


    // Convert IV to string and prepend to ciphertext
    std::string iv = std::string((char*)_iv.data(), CryptoPP::RC6::BLOCKSIZE);
    std::string ivCiphertext = iv + ciphertext;

    // Write output to file
    std::string outputFilename = filename + ".cipher";
    FileIO outputFile(outputFilename);
    outputFile.writeFile();
}

void RC6::decrypt(std::string filename)
{
    using namespace CryptoPP;

    FileIO ciphertextFile(filename);
    std::string ivCiphertext = ciphertextFile.readFile();
}